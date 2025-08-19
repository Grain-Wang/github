#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <cstring>
#include <arpa/inet.h>
#include <errno.h>

using namespace std;
int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(2000);
    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *)&serveraddr, sizeof(struct sockaddr)) == -1)
    {
        cout << "bind failed : " << strerror(errno) << endl;
    }
    listen(sockfd, 10);
    cout << "listen end" << endl;

    getchar();
    cout << "exit" << endl;
    return 0;
}