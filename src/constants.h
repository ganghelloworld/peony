#ifndef CONSTANS_H
#define CONSTANS_H

#include <iostream>

const int REQUEST_LEN = 1024;

namespace Message
{
	static const char CR = '\r';
	static const char LF = '\n';
	static const char SP = ' ';
	static const char HT = '\t';
	static const std::string CRLF = "\r\n";
	static const char COLON = ':';
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
	static const int Methods_NUM = 9;
	static const std::string Methods[Methods_NUM] = {Method::OPTIONS, Method::GET, Method::HEAD, 
											Method::POST, Method::PUT, Method::DELETE, 
											Method::TRACE, Method::CONNECT, Method::TOKEN};
	static const std::string HOST = "Host";

	namespace Header
	{
		static const std::string accept = "Accept";
		static const std::string accept_charset = "Accept-Charset";
		static const std::string accept_encoding = "Accept-Encoding";
		static const std::string accept_language = "Accept-Language";
		static const std::string authorization = "Authorization";
		static const std::string expect = "Expect";
		static const std::string from = "From";
		static const std::string host = "Host";
		static const std::string if_match = "If-Match";
		static const std::string if_modified_since = "If-Modified-Since";
		static const std::string if_none_match = "If-None-Match";
		static const std::string if_range = "If-Range";
		static const std::string if_unmodified_since = "If-Unmodified-Since";
		static const std::string max_forwards = "Max-Forwards";
		static const std::string proxy_authorization = "Proxy-Authorization";
		static const std::string range = "Range";
		static const std::string referer= "Referer";
		static const std::string te = "Te";
		static const std::string user_agent = "User-Agent";
	}
}

namespace Response
{
}

namespace Entity
{

}
#endif //CONSTANS_H
