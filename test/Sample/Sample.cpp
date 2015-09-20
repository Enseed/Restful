#include "Precompiled.h"
#include <Restless/WebServer/RestlessServer.h>
#include <Restless/WebServices/WebService.h>
#include <Restless/HTTP/HttpMediaType.h>
#include <Restless/HTTP/HttpRequest.h>
#include <Restful/HTTP/HttpDTOResult.h>
#include <Restful/RestfulServer.h>
#include <Restless/HTTP/HttpExceptions.h>

#include "HelloWorldDTO.h"
#include "HelloWorldDTO.rh"

class HelloWorldWebService : public restless::WebService
{
public:
	HelloWorldWebService()
	{
		onGet("/throw", [](const HttpRequest &request, const HttpArguments &args)
		{
			throw HttpServerErrorException("Hello World!!!");
			return nullptr;
		});

		onGet("/", [](const HttpRequest &request, const HttpArguments &args)
		{
			HelloWorldDTO helloDTO;
			helloDTO.self = network::uri(request.baseURL() + "/hello/");
			helloDTO.hello = "world";
			return HttpDTOResult::createFromDTO(helloDTO, HttpMediaType::APPLICATION_JSON);
		});

	}


};

class WebServer : public restful::RestfulServer
{
public:
	WebServer()
		: restful::RestfulServer(8081)
	{
		delegateSubPath("/hello", WebServiceRef(new HelloWorldWebService));
	}
};

int main(int argc, const char *argv[])
{
	WebServer webServer;
	Sleep(1000000);
	return 0;
}