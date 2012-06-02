#ifndef RESPONSE_H
#define RESPONSE_H
#include <iostream>
#include <fstream>
#include "request.h"
#include "general.h"
#include "entity.h"

class HttpRequest;


struct ResponseStatusCode
{
	int num;
	std::string desc;
};

class ResponseStatusLine
{
public:
	ResponseStatusLine(){};
	int compose(HttpRequest*);
	int get_content(std::string&);
	~ResponseStatusLine(){};

	friend class HttpResponse;
private:
	//std::string http_version;
	ResponseStatusCode response_status_code;
	std::ifstream response_file;
};

class ResponseHeader
{
public:
	ResponseHeader(){};
	int compose();
	int get_content(std::string&);
	~ResponseHeader(){};
private:
	std::string accept_ranges;
	std::string age;
	std::string etag;
	std::string location;
	std::string proxy_authenticate;
	std::string retry_after;
	std::string server;
	std::string vary;
	std::string www_authenticate;
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
	GeneralHeader* general_header;
	ResponseHeader response_header;
	EntityHeader entity_header;
	std::string content;
};

#endif //RESPONSE_H
