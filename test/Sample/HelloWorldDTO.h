#pragma once

#include <string>
#include <cpp-netlib/uri/src/network/uri.hpp>

struct HelloWorldDTO
{
	network::uri self;
	std::string hello;
};
