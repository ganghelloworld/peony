#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <fstream>

class EntityHeader
{
public:
	EntityHeader(){};
	int compose(std::ifstream&);
	int get_content(std::string&);
private:
	std::string allow;
	std::string content_encoding;
	std::string content_language;
	int content_length;
	std::string content_location;
	std::string content_md5;
	std::string content_range;
	std::string content_type;
	std::string expires;
	std::string last_modified;
	std::string extension_header;

	std::string entity;
};

#endif //ENTITY_H
