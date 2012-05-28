#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>

class RequestLine
{
public:
	RequestLine(){};
	RequestLine(std::string &src, int &index);
	void init(std::string &src, int &index);

private:
	std::string method;
	std::string request_url;
	std::string http_version;
};

class RequestHeader
{
public:
	RequestHeader(){};
	RequestHeader(std::string &src, int &index);
	void init(std::string &src, int &index);

private:
	std::string accept;
	std::string accept_charset;
	std::string accept_encoding;
	std::string accept_language;
	std::string authorization;
	std::string expect;
	std::string from;
	std::string host;
	std::string if_match;
	std::string if_modified_since;
	std::string if_none_match;
	std::string if_range;
	std::string if_unmodified_since;
	std::string max_forwards;
	std::string proxy_authorization;
	std::string range;
	std::string referer;
	std::string te;
	std::string user_agent;
};

class HttpRequest
{
public:
	HttpRequest(){};
	HttpRequest(std::string &src);

private:
	RequestLine request_line;
	GeneralHeader general_header;
	RequestHeader general_header;
	std::string _message_body;
};

#endif //REQUEST_H
