#pragma once

#include <Restless/HTTP/HttpResult.h>
#include <Restless/HTTP/HttpMediaType.h>

#include <boost/lexical_cast.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/random_generator.hpp>


#include <Generic/Strings/Strings.h>
#include <Generic/Base/RTTI.h>

#include "../Domain/DTO/Errors/ErrorDTO.reflect.h"

#include "HttpErrors.h"
#include <Restless/HTTP/HttpExceptions.h>

#include <Season/RapidSeason.h>

template<class TEX>
class HttpExceptionError : public HttpResult
{
public:
	HttpExceptionError(const TEX &iEx)
	{
		const std::exception &ex = iEx;
		ErrorDTO dto;
		HttpErrors::createDTOFromException(ex, &dto);

		setStatus(HttpStatus::eSERVER_ERROR);
		setBytes(season::RapidSeason::toJSON(dto), HttpMediaType::APPLICATION_JSON);
	}
};

template<>
class HttpExceptionError<HttpException> : public HttpResult
{
public:
	HttpExceptionError(const HttpException &ex)
	{
		ErrorDTO dto;
		HttpErrors::createDTOFromException(ex, &dto);
		setStatus(ex.statusCode(), ex.what());
		setBytes(season::RapidSeason::toJSON(dto), HttpMediaType::APPLICATION_JSON);
	}
};


struct HttpExceptionResponseBuilder
{
public:
	template<class T>
	static sd::AutoPtr<HttpResult> build(const T &ex)
	{
		return new HttpExceptionError<T>(ex);
	}
};

