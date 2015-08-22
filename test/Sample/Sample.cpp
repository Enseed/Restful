#include "Precompiled.h"
#include <Enseed/Restless/WebServer/RestlessServer.h>
#include <Enseed/Restless/WebServices/WebService.h>
#include <Enseed/Restless/HTTP/HttpMediaType.h>
#include <Enseed/Restless/HTTP/HttpRequest.h>
#include <Enseed/Restful/HTTP/HttpDTOResult.h>
#include <Enseed/Restful/RestfulServer.h>
#include <Enseed/Restless/HTTP/HttpExceptions.h>

#include "HelloWorldDTO.h"
#include "HelloWorldDTO.h.reflect.h"

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