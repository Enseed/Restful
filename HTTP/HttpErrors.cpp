#include "Precompiled.h"

#include "../Domain/DTO/Errors/ErrorDTO.h"
#include "../Domain/DTO/Errors/ErrorDTO.reflect.h"
#include "HttpErrors.h"
#include "HttpExceptionErrors.h"
#include <boost/uuid/random_generator.hpp>

void HttpErrors::createDTOFromException(const std::exception &ex, ErrorDTO *outDTO)
{
	outDTO->id = boost::uuids::random_generator()();
	outDTO->time = boost::posix_time::second_clock::local_time();
	outDTO->message = ex.what();
	outDTO->error_type = typeid(ex).name();
}

void HttpErrors::createDTOFromException(const HttpException &ex, ErrorDTO *outDTO)
{
	outDTO->id = boost::uuids::random_generator()();
	outDTO->time = boost::posix_time::second_clock::local_time();
	outDTO->message = ex.what();
	outDTO->stack = seed::Strings::splitstr(ex.backtrace(), '\n');
	outDTO->error_type = typeid(ex).name();
	if (ex.cause())
	{
		const std::exception &cause = ex.cause().get();
		outDTO->cause = new ErrorDTO;
		if (const HttpException *httpCause = dynamic_cast<const HttpException*>(&cause))
			createDTOFromException(*httpCause, outDTO->cause.ptr());
		else
			createDTOFromException(cause, outDTO->cause.ptr());
	}
}

seed::AutoPtr<HttpResult> HttpErrors::createFromException(const std::exception &ex)
{
	const HttpException *httpEx = dynamic_cast<const HttpException*>(&ex);
	if (const HttpException *httpEx = dynamic_cast<const HttpException*>(&ex))
	{
		return HttpExceptionResponseBuilder::build(*httpEx).givePtr();
	}
	else
	{
		return HttpExceptionResponseBuilder::build(ex).givePtr();
	}
}
