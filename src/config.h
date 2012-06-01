#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>

namespace Peony
{
	const int PORT = 88;
	const std::string Host = "127.0.0.1:" + PORT;
	const std::string Protocol = "HTTP";
	const int VERSION_MAJOR = 1;
	const int VERSION_MINOR = 1;
	const std::string Http_Version = "HTTP/1.1";

	const std::string Directory = "/Users/gang/program/c-family/peony/www";
	const std::string Directory_Index = "index.html";
}

#endif //CONFIG_H
