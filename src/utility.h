#ifndef UTILITY_H
#define UTILITY_H
#include <string>
#include <iostream>
#include <sstream>
#include <time.h>
#include "constants.h"
#include "config.h"

int require(bool b, std::string msg);

inline std::string int2string(int a)
{
	std::stringstream ss;
	ss << a;
	return ss.str();
}

inline std::string current_date_time()
{
	time_t rawtime;
	struct tm * timeinfo;
	char buf[32];
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buf, sizeof(buf), "%a, %d %b %Y %X GMT", timeinfo);
	return std::string(buf);
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

class HttpVersion
{
public:
	HttpVersion(std::string);
	HttpVersion(std::string na, int ma, int mi) : name(na), major(ma), minor(mi){};
	inline bool is_http()
	{
		if(name == Peony::Protocol) return true; //case sensitive
		else return false;
	}
	int compare(HttpVersion&);
private:
	std::string name;
	int major;
	int minor;
};
#endif //UTILITY_H
