#ifndef __WRAPPER_RESTFULLSERVER_H__
#define __WRAPPER_RESTFULLSERVER_H__

#include <Enseed/Restless/WebServer/RestlessServer.h>
#include <Enseed/Generic/AutoPtr/AutoPtr.h>

struct mg_connection;

namespace restful {

	class RestfulServer : public restless::RestlessServer
	{
	public:
		RestfulServer(int port);
		virtual ~RestfulServer();

		virtual int onError(mg_connection *connection, int statusCode) override;
		virtual sd::AutoPtr<HttpResult> RestfulServer::onException(mg_connection *connection, const std::exception &exception) override;


	private:
		RestfulServer(RestfulServer &);
		RestfulServer& operator=(const RestfulServer&);
	};

} // namespace restless

#endif // __WRAPPER_RESTFULLSERVER_H__
