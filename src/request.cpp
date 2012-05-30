#include "request.h"
#include "constants.h"
#include "utility.h"
#include <iostream>
#include <string>

using namespace std;

HttpRequest::HttpRequest(string &src) : valid(false)
{
	valid = init(src);
}
bool HttpRequest::init(string &src)
{
	int index = 0;
	string_trim_header(src);
	if(!request_line.init(src, index)) return false;
	cout << request_line;

	general_header.init(src, index);
	cout << general_header;

	request_header.init(src, index);
	cout << request_header;
	return true;
}
std::ostream& operator <<(std::ostream &out, HttpRequest& hr)
{
	out << hr.request_line;
	return out;
}

RequestLine::RequestLine(std::string &src, int &index)
{
	init(src, index);
}
bool RequestLine::init(std::string &src, int &index)
{
	int i = 0;
	string_cut(src, index, method, Message::SP);
	string_cut(src, index, request_url, Message::SP);
	string_cut(src, index, http_version, Message::CRLF);

	get_value(src, index, host, Request::HOST);
	return true;
}
std::ostream& operator <<(std::ostream &out, RequestLine& rl)
{
	out << "RequestLine:" << endl
		<< "\tmethod=|" << rl.method  << "|" << endl
		<< "\trequest_url=|" << rl.request_url << "|" << endl
		<< "\thttp_version=|" << rl.http_version << "|" << endl
		<< "\thost=|" << rl.host << "|" << endl;
	return out;
}

RequestHeader::RequestHeader(string &src, int &index)
{
	init(src, index);
}
bool RequestHeader::init(string &src, int &index)
{
	get_value(src, index, accept, Request::Header::accept);
	get_value(src, index, accept_charset, Request::Header::accept_charset);
	get_value(src, index, accept_encoding, Request::Header::accept_encoding);
	get_value(src, index, accept_language, Request::Header::accept_language);
	get_value(src, index, authorization, Request::Header::authorization);
	get_value(src, index, expect, Request::Header::expect);
	get_value(src, index, from, Request::Header::from);
	get_value(src, index, host, Request::Header::host);
	get_value(src, index, if_match, Request::Header::if_match);
	get_value(src, index, if_modified_since, Request::Header::if_modified_since);
	get_value(src, index, if_none_match, Request::Header::if_none_match);
	get_value(src, index, if_range, Request::Header::if_range);
	get_value(src, index, if_unmodified_since, Request::Header::if_unmodified_since);
	get_value(src, index, max_forwards, Request::Header::max_forwards);
	get_value(src, index, proxy_authorization, Request::Header::proxy_authorization);
	get_value(src, index, range, Request::Header::range);
	get_value(src, index, referer, Request::Header::referer);
	get_value(src, index, te, Request::Header::te);
	get_value(src, index, user_agent, Request::Header::user_agent);
}
std::ostream& operator <<(std::ostream &out, RequestHeader& rh)
{
	out << "RequestHeader:" << endl;
	if(rh.accept.size() != 0) cout << "\t" << "accept=|" << rh.accept << "|" << endl;
	if(rh.accept_charset.size() != 0) cout << "\t" << "accept_charset=|" << rh.accept_charset << "|" << endl;
	if(rh.accept_encoding.size() != 0) cout << "\t" << "accept_encoding=|" << rh.accept_encoding << "|" << endl;
	if(rh.accept_language.size() != 0) cout << "\t" << "accept_language=|" << rh.accept_language << "|" << endl;
	if(rh.authorization.size() != 0) cout << "\t" << "authorization=|" << rh.authorization<< "|" << endl;
	if(rh.expect.size() != 0) cout << "\t" << "expect=|" << rh.expect << "|" << endl;
	if(rh.from.size() != 0) cout << "\t" << "from=|" << rh.from << "|" << endl;
	if(rh.host.size() != 0) cout << "\t" << "host=|" << rh.host << "|" << endl;
	if(rh.if_match.size() != 0) cout << "\t" << "if_match=|" << rh.if_match << "|" << endl;
	if(rh.if_modified_since.size() != 0) cout << "\t" << "if_modified_since=|" << rh.if_modified_since << "|" << endl;
	if(rh.if_none_match.size() != 0) cout << "\t" << "if_none_match=|" << rh.if_none_match << "|" << endl;
	if(rh.if_range.size() != 0) cout << "\t" << "if_range=|" << rh.if_range << "|" << endl;
	if(rh.if_unmodified_since.size() != 0) cout << "\t" << "if_unmodified_since=|" << rh.if_unmodified_since << "|" << endl;
	if(rh.max_forwards.size() != 0) cout << "\t" << "max_forwards=|" << rh.max_forwards << "|" << endl;
	if(rh.proxy_authorization.size() != 0) cout << "\t" << "proxy_authorization=|" << rh.proxy_authorization << "|" << endl;
	if(rh.range.size() != 0) cout << "\t" << "range=|" << rh.range << "|" << endl;
	if(rh.referer.size() != 0) cout << "\t" << "referer=|" << rh.referer << "|" << endl;
	if(rh.te.size() != 0) cout << "\t" << "te=|" << rh.te << "|" << endl;
	if(rh.user_agent.size() != 0) cout << "\t" << "user_agent=|" << rh.user_agent << "|" << endl;
	return out;
}
