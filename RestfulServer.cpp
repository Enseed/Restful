#include "Precompiled.h"
#include "RestfulServer.h"
#include "Domain/DTO/Errors/ErrorDTO.h"
#include "Domain/DTO/Errors/ErrorDTO.h.reflect.h"
#include "HTTP/HttpDTOResult.h"
#include <boost/uuid/random_generator.hpp>
#include <boost/date_time/microsec_time_clock.hpp>
#include <Enseed/Restless/HTTP/HttpStatus.h>
#include <Enseed/Restless/HTTP/HttpResult.h>
#include <Enseed/Restless/HTTP/HttpMediaType.h>
#include <Enseed/Restless/HTTP/HttpResponse.h>
#include <Enseed/Restless/HTTP/HttpExceptions.h>
#include "HTTP/HttpErrors.h"

#include "Log.h"

namespace restful {


	RestfulServer::RestfulServer(int port)
		: RestlessServer(port)
	{}

	RestfulServer::~RestfulServer()
	{}

	sd::AutoPtr<HttpResult> RestfulServer::onException(mg_connection *connection, const std::exception &exception)
	{
		return HttpErrors::createFromException(exception).givePtr();
	}


	int RestfulServer::onError(mg_connection * connection, int statusCode)
	{ 
		ErrorDTO errorDTO;
		errorDTO.id = boost::uuids::random_generator()();
		errorDTO.message = HttpStatus::fromInt(statusCode).defaultMessage();
		errorDTO.time = boost::posix_time::microsec_clock::universal_time();
		HttpResult *result = HttpDTOResult::createFromDTO(errorDTO, HttpMediaType::APPLICATION_JSON);
		result->setStatus(HttpStatus::fromInt(statusCode));

		HttpResponse response(connection);
		response.send(*result);
		delete result;

		LOG_ERROR << "Error: " << season::RapidSeason::toJSON(errorDTO);
		return 0;
	}

} // namespace restless
