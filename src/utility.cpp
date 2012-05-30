#include <iostream>
#include <sstream>
#include <string>
#include "utility.h"

using namespace std;

int require(bool b, string msg)
{
	if(!b)
	{
		cout << msg << endl;
		exit(1);
	}
	return 1;
}

int string_cut(string& src, int &index, string& des, char ch)
{
	string tag;
	tag += ch;
	return string_cut(src, index, des, tag);
}

int string_cut(string& src, int &index, string& des, string end_tag)
{
	des = src.substr(index, src.find(end_tag, index) - index); 
	if(des.size() > 0)
	{
		index += des.size() + end_tag.size();
		return des.size();
	}
	return -1;
}

int get_value(string& src, int index, string& des, string tag)
{
	//cout << "Tag : " << tag << endl;
	//cout << src.substr(index) << endl;
	int pos = src.find(tag, index);
	//cout << "index =" << index << " pos=" << pos << endl;
	if(pos < 0) return -1;
	pos += tag.size();
	if(src[pos] == Message::COLON) pos++;
	while(is_whitespace(src[pos])) pos++;
	return string_cut(src, pos, des, Message::CRLF);
}

void string_trim_header(std::string& src)
{
	int pos = 0;
	while(is_whitespace(src[pos++]));
	src = src.substr(pos-1);
}

