#ifndef CONSTANS_H
#define CONSTANS_H

#include <iostream>
#include "response.h"

namespace Message
{
	const char CR = '\r';
	const char LF = '\n';
	const char SP = ' ';
	const char HT = '\t';
	const std::string CRLF = "\r\n";
	const char COLON = ':';
}

namespace General
{
	namespace Header
	{
		const std::string Cache_Control = "Cache-Control";
		const std::string Connection = "Connection";
		const std::string Date = "Date";
		const std::string Pragma = "Pragma";
		const std::string Trailer = "Trailer";
		const std::string Transfer_Encoding = "Transfer-Encoding";
		const std::string Upgrade = "Upgrade";
		const std::string Via = "Via";
		const std::string Warning = "Warning";
	}
}

namespace Request
{
	const int REQUEST_LEN = 1024;
	namespace Method 
	{
		const std::string Options = "OPTIONS";
		const std::string Get = "GET";
		const std::string Head = "HEAD";
		const std::string Post = "POST";
		const std::string Put = "PUT";
		const std::string Delete = "DELETE";
		const std::string Trace = "TRACE";
		const std::string Connect = "CONNECT";
		const std::string Token = "extension-method";
	}
	const int METHODS_NUM = 9;
	const std::string Methods[METHODS_NUM] = {Method::Options, Method::Get, Method::Head, 
											Method::Post, Method::Put, Method::Delete, 
											Method::Trace, Method::Connect, Method::Token};
	const std::string Host = "Host";

	namespace Header
	{
		const std::string Accept = "Accept";
		const std::string Accept_Charset = "Accept-Charset";
		const std::string Accept_Encoding = "Accept-Encoding";
		const std::string Accept_Language = "Accept-Language";
		const std::string Authorization = "Authorization";
		const std::string Expect = "Expect";
		const std::string From = "From";
		const std::string Host = "Host";
		const std::string If_Match = "If-Match";
		const std::string If_Modified_Since = "If-Modified-Since";
		const std::string If_None_Match = "If-None-Match";
		const std::string If_Range = "If-Range";
		const std::string If_Unmodified_Since = "If-Unmodified-Since";
		const std::string Max_Forwards = "Max-Forwards";
		const std::string Proxy_Authorization = "Proxy-Authorization";
		const std::string Range = "Range";
		const std::string Referer= "Referer";
		const std::string Te = "Te";
		const std::string User_Agent = "User-Agent";
	}
}
namespace StatusCode
{
	const ResponseStatusCode OK = {200, "OK"};
}
namespace Response
{
}

namespace Entity
{

}
#endif //CONSTANS_H
