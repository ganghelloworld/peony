#include "config.h"
#include "constants.h"
#include "httpd.h"
#include "utility.h"
#include "request.h"
#include "response.h"

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
	serv_addr.sin_port = htons(Peony::PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;

	ret = bind(sock_fd, (struct sockaddr *)&serv_addr, sizeof(struct sockaddr_in));
	require(ret >= 0, "Failed bind");
	listen(sock_fd, 5);
	char buffer[Request::REQUEST_LEN];
	while(1)	
	{
		socklen_t cli_len = sizeof(cli_addr);
		int cli_sockfd = accept(sock_fd, (struct sockaddr *)&cli_addr, &cli_len);
		require(cli_sockfd >= 0, "Failed accept");

		bzero(buffer, Request::REQUEST_LEN);
		int n = read(cli_sockfd, buffer, Request::REQUEST_LEN - 1);
		require(n >= 0, "Failed read");
		cout << "request len = " << n << endl;
		cout << buffer << endl;

		string temp(buffer, n);
		HttpRequest request(temp);
		//cout << request;
		HttpResponse response(&request);

		cout << response.get_content() << endl;
		n = write(cli_sockfd, response.get_content().c_str(), response.get_content().length());
		close(cli_sockfd);
		//break;
	}
	close(sock_fd);
}

void Httpd::response()
{
}
