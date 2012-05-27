#ifndef HTTPD_H
#define HTTPD_H

class Httpd
{
public:
	Httpd();
	void start();
private:
	void loop();
	void response();
};

#endif //HTTPD_H
