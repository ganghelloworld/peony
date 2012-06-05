#include "general.h"
#include "constants.h"
#include "utility.h"

#include <string>
#include <iostream>

using namespace std;

GeneralHeader::GeneralHeader(string &src, int &index)
{
	parse(src, index);
}

void GeneralHeader::parse(string &src, int &index)
{
	get_value(src, index, cache_control, General::Header::Cache_Control);
	get_value(src, index, connection, General::Header::Connection);
	get_value(src, index, date, General::Header::Date);
	get_value(src, index, pragma, General::Header::Pragma);
	get_value(src, index, trailer, General::Header::Trailer);
	get_value(src, index, transfer_encoding, General::Header::Transfer_Encoding);
	get_value(src, index, upgrade, General::Header::Upgrade);
	get_value(src, index, via, General::Header::Via);
	get_value(src, index, warning, General::Header::Warning);
}

int GeneralHeader::compose()
{
	date = "Sat, 02 Jun 2012 02:14:28 GMT";
}
int GeneralHeader::get_content(string& content)
{
	string tag = string("") + Message::COLON + Message::SP;
	int temp = content.size();
	if(connection.size() != 0)
		content += General::Header::Connection + tag + connection + Message::CRLF;
	if(date.size() != 0)
		content += General::Header::Date + tag + date + Message::CRLF;
	return content.size() - temp;
}

ostream& operator << (std::ostream& out, GeneralHeader &gh)
{
	out << "GeneralHeader : " << endl;
	if(gh.cache_control.size() != 0) out << "\t" << "cache_control|" << gh.cache_control << "|" << endl;
	if(gh.connection.size() != 0) out << "\t" << "connection|" << gh.connection << "|" << endl;
	if(gh.date.size() != 0) out << "\t" << "date|" << gh.date << "|" << endl;
	if(gh.pragma.size() != 0) out << "\t" << "pragma|" << gh.pragma << "|" << endl;
	if(gh.trailer.size() != 0) out << "\t" << "trailer|" << gh.trailer << "|" << endl;
	if(gh.transfer_encoding.size() != 0) out << "\t" << "transfer_encoding|" << gh.transfer_encoding<< "|" << endl;
	if(gh.upgrade.size() != 0) out << "\t" << "upgrade|" << gh.upgrade<< "|" << endl;
	if(gh.via.size() != 0) out << "\t" << "via|" << gh.via << "|" << endl;
	if(gh.warning.size() != 0) out << "\t" << "warning|" << gh.warning << "|" << endl;
	return out;
}
