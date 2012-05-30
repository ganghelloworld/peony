#include "general.h"
#include "constants.h"
#include "utility.h"

#include <string>
#include <iostream>

using namespace std;

GeneralHeader::GeneralHeader(string &src, int &index)
{
	init(src, index);
}

void GeneralHeader::init(string &src, int &index)
{
	get_value(src, index, cache_control, General::Header::cache_control);
	get_value(src, index, connection, General::Header::connection);
	get_value(src, index, date, General::Header::date);
	get_value(src, index, pragma, General::Header::pragma);
	get_value(src, index, trailer, General::Header::trailer);
	get_value(src, index, transfer_encoding, General::Header::transfer_encoding);
	get_value(src, index, upgrade, General::Header::upgrade);
	get_value(src, index, via, General::Header::via);
	get_value(src, index, warning, General::Header::warning);
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
