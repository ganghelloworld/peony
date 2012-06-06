#ifndef HTTPD_H
#define HTTPD_H
#include <iostream>
class Httpd
{
public:
	Httpd();
	void start();
	~Httpd(){};
	void response(std::string*, int);
private:
	void loop();
};

#endif //HTTPD_H
