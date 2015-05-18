#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 888
#define LISTEN_LEN 10

int main(int argc,char ** argv){
    //sock
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock<0){
        perror("create socket failed");
        return -1;
    }

    //server addr
    struct sockaddr_in server;
    memset(&server, 0, sizeof(struct sockaddr_in));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    //bind
    if(bind(sock, (struct sockaddr *)&server,sizeof(struct sockaddr))!=0){
        perror("bind error");
        return -2;
    }

    //listen
    if(listen(sock,LISTEN_LEN)!=0){
        perror("listen error");
        return -3;
    }

    while(1){
        printf("working in listen thread---\n");
		sleep(2);
	}

	return 0;

}
