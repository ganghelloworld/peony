#include "response.h";
#include "utility.h";
#include "request.h";
#include "constants.h";

#include <iostream>

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
	compose();
}

void HttpResponse::compose()
{
	content += response_status_line.compose();
	content += general_header.compose();
	content += response_header.compose();
	content += Message::CRLF;
	add_message_body();
}

void HttpResponse::add_message_body()
{
}
string& HttpResponse::get_content()
{
	string& temp = content;
	return  temp;
}

string ResponseHeader::compose()
{

}

string ResponseStatusLine::compose()
{

}
