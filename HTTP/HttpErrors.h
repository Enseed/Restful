#pragma once

#include <Restless/HTTP/HttpExceptions.h>
#include <Generic/AutoPtr/AutoPtr.h>

struct ErrorDTO;
class HttpResult;

class HttpErrors
{
public:
	static seed::AutoPtr<HttpResult> createFromException(const std::exception &ex);
	static void createDTOFromException(const std::exception &ex, ErrorDTO *outDTO);
	static void createDTOFromException(const HttpException &ex, ErrorDTO *outDTO);
};

