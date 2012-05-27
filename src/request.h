#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>

class Request
{
public:
	Request(std::string src);

public:
	std::string _method;
	std::string _request_url;
	std::string _http_version;
	std::string _message_body;
};

#endif //REQUEST_H
