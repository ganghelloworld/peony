#include "request.h"
#include <iostream>
#include <string>

using namespace std;

HttpRequest::HttpRequest(string &src)
{
}
void HttpRequest::HttpRequest(string &src)
{
	int index = 0;
	request_line.init(src, index);
	general_header.init(src, index);
	request_header.init(src, index);
}

RequestLine::RequestLine(std::string &src, int &index)
{
	init(src, index);
}
void RequestLine::init(std::string &src, int &index)
{
	for(int i = 0; i < Request::Methods.size(); i++)
	{
		if((index = src.find_first_of(Request::Methods[i], index)) >= 0) break;
	}
	method = Request::Methods[i];
	index += method.size() + 1;
}

RequestHeader::RequestHeader(string &src, int &index)
{
	init(src, index);
}
void RequestHeader::RequestHeader(string &src, int &index)
{

}
