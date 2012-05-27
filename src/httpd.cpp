#include "config.h"
#include "httpd.h"
#include "utility.h"

#include <cstring>
#include <string>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

Httpd::Httpd()
{

}

void Httpd::start()
{
	loop();
}

void Httpd::loop()
{
	int sock_fd;
	int ret;
	struct sockaddr_in serv_addr, cli_addr;

	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	require(sock_fd >= 0, "Failed socket");

	memset(&serv_addr, 0, sizeof(struct sockaddr_in));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	ret = bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in));
	require(ret >= 0, "Failed bind");
	listen(sock_fd, 5);
	
	socklen_t cli_len = sizeof(cli_addr);
	int cli_sockfd = accept(sock_fd, (struct sockaddr *)&cli_addr, &cli_len);
	require(cli_sockfd >= 0, "Failed accept");

	char buffer[256];
	bzero(buffer, 256);
	int n = read(cli_sockfd, buffer, 255);
	require(n >= 0, "Failed read");
	cout << buffer << endl;
	string response = "HTTP/1.1 200 OK\n";
	string content = "Hello Gang!";
	response += "Date: Sat, 26 May 2012 08:55:26 GMT\n";
	response += "Server: Peony/0.1\n";
	response += "Content-Length: " + int2string(content.length()) + "\n";
	response += "Keep-Alive: timeout=5, max=100\nConnection: Keep-Alive\n";
	response += "Content-Type: text/html\n\n";
	response += content;
	n = write(cli_sockfd, response.c_str(), response.length());
	close(cli_sockfd);
	close(sock_fd);
}

void Httpd::response()
{
}
