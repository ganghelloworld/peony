#include "response.h";
#include "utility.h";
#include "request.h";
#include "constants.h";
#include "config.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

HttpResponse::HttpResponse() : request(0)
{
}
HttpResponse::~HttpResponse()
{
	//if(request != 0) delete request; //
}

HttpResponse::HttpResponse(HttpRequest *r) : request(r)
{
	general_header = &(request->general_header);
	compose();
}

void HttpResponse::compose()
{
	response_status_line.compose(request);
	general_header->compose();
	response_header.compose();
	if(response_status_line.response_file.is_open())
		entity_header.compose(response_status_line.response_file);
}

void HttpResponse::add_message_body()
{
}
string& HttpResponse::get_content()
{
	response_status_line.get_content(content);
	general_header->get_content(content);
	response_header.get_content(content);

	entity_header.get_content(content);

	//content += Message::CRLF;

	add_message_body();
	string& temp = content;
	return  temp;
}

int ResponseHeader::get_content(string& content)
{
	int temp = content.size();
	string tag = string("") + Message::COLON + Message::SP;
	if(server.size() != 0)
		content += Response::Header::Server + tag + server + Message::CRLF;
	return content.size() - temp;
}
int ResponseHeader::compose()
{
	server = Peony::Server;
}

int ResponseStatusLine::get_content(string& content)
{
	content += Peony::Http_Version + Message::SP;
	content += int2string(response_status_code.num) + Message::SP;
	content += response_status_code.desc + Message::CRLF;
	return 0;
}
int ResponseStatusLine::compose(HttpRequest* request)
{
	RequestLine request_line = request->request_line;
	string version = request->request_line.http_version;
	HttpVersion request_http(version);
	HttpVersion support_http(Peony::Http_Version);
	if(!request_http.is_http()) // It's not HTTP protocol, 101??
	{
		return -1;
	}
	if(version == Peony::Http_Version || 
		request_http.compare(support_http) >= 0)
	{
		if(request->request_line.method == Request::Method::Get)
		{
			string path = Peony::Directory + request->request_line.request_url;
			//is a directory and exist
			if(1)
			{
				path += Peony::Directory_Index;
			}
			response_file.open(path.c_str(), ios::in);
			if(response_file.is_open()) //is a file and exist, 200
			{
				response_status_code = StatusCode::OK;
			}
			else //404 : not found
			{
			}
		}
		else
		{
		}
	}
	else //505 : HTTP Version	not supported
	{
		return -1;
	}
}
