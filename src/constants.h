#ifndef CONSTANS_H
#define CONSTANS_H

#include <iostream>

const int REQUEST_LEN = 1024;

namespace Message
{
	static const std::string SP = " ";
	static const std::string CRLF = "\n";
}

namespace General
{
	namespace Header
	{
		static const std::string cache_control = "Cache-Control";
		static const std::string connection = "Connection";
		static const std::string date = "Date";
		static const std::string pragma = "Pragma";
		static const std::string trailer = "Trailer";
		static const std::string transfer_encoding = "Transfer-Encoding";
		static const std::string upgrade = "Upgrade";
		static const std::string via = "Via";
		static const std::string warning = "Warning";
	}
}

namespace Request
{
	namespace Method 
	{
		static const std::string OPTIONS = "OPTIONS";
		static const std::string GET = "GET";
		static const std::string HEAD = "HEAD";
		static const std::string POST = "POST";
		static const std::string PUT = "PUT";
		static const std::string DELETE = "DELETE";
		static const std::string TRACE = "TRACE";
		static const std::string CONNECT = "CONNECT";
		static const std::string TOKEN  = "extension-method";
	}
	static const std::string Methods[9] = {Method::OPTIONS, Method::GET, Method::HEAD, 
											Method::POST, Method::PUT, Method::DELETE, 
											Method::TRACE, Method::CONNECT, Method::TOKEN};
	static const std::string HOST = "Host";

	namespace Header
	{

	}
}
#endif //CONSTANS_H
