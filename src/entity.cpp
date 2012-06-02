#include "entity.h"
#include "constants.h"
#include <iostream>
#include <cstring>

using namespace std;

int EntityHeader::compose(ifstream& in)
{
	entity = "In Entity, Hello Gang!";
	content_length = entity.length();
	content_type = "text/html";
	return 0;
}

int EntityHeader::get_content(string& content)
{
	int temp = content.size();
	string tag = ": ";	
	if(content_length >= 0)
	{
		content += Entity::Header::Content_Length + tag + "22" + Message::CRLF;
	//	content += content_length + Message::CRLF;
	}
	if(content_type.size() != 0)
		content += Entity::Header::Content_Type + tag + content_type + Message::CRLF;

	content += Message::CRLF;
	content += entity;
	return 0;
}
