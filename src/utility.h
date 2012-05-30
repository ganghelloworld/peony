#ifndef UTILITY_H
#define UTILITY_H
#include <string>
#include <iostream>
#include <sstream>
#include "constants.h"

int require(bool b, std::string msg);

inline std::string int2string(int a)
{
	std::stringstream ss;
	ss << a;
	return ss.str();
}

int string_cut(std::string&, int &, std::string& , std::string end_tag);
int string_cut(std::string& src, int &index, std::string& des, char ch);

int get_value(std::string& src, int index, std::string& des, std::string tag);

void string_trim_header(std::string&);

inline bool is_whitespace(char ch)
{
	if(ch == Message::CR || ch == Message::LF ||
		ch == Message:: SP || ch == Message::HT)
		return true;
	return false;
}
#endif //UTILITY_H
