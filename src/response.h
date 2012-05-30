#ifndef RESPONSE_H
#define RESPONSE_H
#include <iostream>
#include "request.h"
#include "general.h"

struct ResponseStatusCode
{
	int num;
	std::string desc;
};

class ResponseStatusLine
{
public:
	ResponseStatusLine(){};
	std::string compose();
	~ResponseStatusLine(){};
private:
	std::string http_version;
	ResponseStatusCode response_status_code;
};

class ResponseHeader
{
public:
	ResponseHeader(){};
	std::string compose();
	~ResponseHeader(){};
};

class HttpResponse
{
public:
	HttpResponse();
	HttpResponse(HttpRequest*);
	void compose();
	std::string& get_content();
	void add_message_body();
	~HttpResponse();

private:
	HttpRequest *request;

	ResponseStatusLine response_status_line; 
	GeneralHeader general_header;
	ResponseHeader response_header;
	std::string content;
};

#endif //RESPONSE_H
