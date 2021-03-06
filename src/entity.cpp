#include "entity.h"
#include "constants.h"
#include "utility.h"
#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int EntityHeader::compose(ifstream& in)
{
	if(in.is_open())
	{
		stringstream buffer;
		buffer << in.rdbuf();
		entity = buffer.str();
		content_length = entity.length();
		content_type = "text/html";
		return 0;
	}
	return -1;
}

int EntityHeader::get_content(string& content)
{
	int temp = content.size();
	string tag = string("") + Message::COLON + Message::SP;	
	if(content_length >= 0)
	{
		content += Entity::Header::Content_Length + tag + int2string(content_length) + Message::CRLF;
	}
	if(content_type.size() != 0)
		content += Entity::Header::Content_Type + tag + content_type + Message::CRLF;

	content += Message::CRLF;
	content += entity;
	return 0;
}
