#ifndef GENERAL_H
#define GENERAL_H

#include <string>

class GeneralHeader
{
public:
	GeneralHeader(){};
	GeneralHeader(std::string &src, int &index);
	void parse(std::string &src, int &index);
	int compose();
	int get_content(std::string&);
	~GeneralHeader(){};
	
	friend std::ostream& operator << (std::ostream&, GeneralHeader&);
private:
	std::string cache_control;
	std::string connection;
	std::string date;
	std::string	pragma;
	std::string trailer;
	std::string transfer_encoding;
	std::string	upgrade;
	std::string via;
	std::string warning;
};

#endif //GENERAL_H
