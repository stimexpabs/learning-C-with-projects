#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Practical.h"

int main(int argc, char *argv[]) {
	
	if (argc < 3 || argc > 4)	// test for correct number of arguments
		DieWithUserMessage("Parameter(s)", "<Server Address> <Echo Word> [<Server Port>]");
	
	char *servIP = argv[1];		// First arg: server IP address (dotted quad)
	char *echoString = argv[2];	// Second arg: string to echo
	
	in_port_t servPort = (argc == 4)? atoi(argv[3]: 7;	// Third arg (optional): server port (numeric). 7 is a well-known echo port 
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	// Create a reliable, stream socket using TCP.
	if (sock < 0)
		DieWithUserMessage("socket() failed");


	// construct the server address structure
	struct sockaddr_in servAddr;		// server adderss
	memset(&servAddr, 0, sizeof(servAddr));	// zero out structure
	servAddr.sin_family = AF_INET;		// IPv4 address family
	

	// convert address
	int rtnVal = inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr);
	if (rtnVal == 0)
		DieWithUserMessage("inet_pton() failed", "invalid address string");
	else if (rtnVal < 0) 
		DieWithSystemMessage("inet_pton() failed");
	servAddr.sin_port = htons(servPort);	// server port
	

	// establish the connection to the echo server
	if (connect(sock, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0)
		DieWithSystemMessage("connect() failed");

	size_t echoStringLen = strlen(echoString);	//Determine input length
	

	// send the string to the server
	ssize_t numBytes = send(sock, echoString, echoStringLen, 0);
	if (numBytes < 0)
		DieWithUserMessage("send()", "sent unexpected numbe of bytes");


	// receive the same string back from the server
	unsigned int totalBytesRcvd = 0;		// count the total number of bytes received
	fputs("Received: ", stdout);			// setup to print the echoed string
	while (totalBytesRcvd < echoStringLen) {
		char buffer [BUFSIZE];				// I/O buffer
		/* receive up to the buffer size (minus 1 to leave space for a null terminator) bytes from the sender. */
		numBytes = recv(sock, buffer, BUFSIZE - 1, 0);
		if (numBytes < 0)
			DieWithUserMessage("recv() failed");
		else if (numBytes == 0)
			DieWithUseMessage("recv()", "connection closed prematurely");
		totalBytesRcvd += numBytes;	// keep tally of total bytes
		buffer[numBytes] = '\0';	// terminate the string
		fputs(buffer, stdout);		// print the echo buffer
	}

	fputc('\n', stdout);	// print a final linefeed
	
	close(sock);
	exit(0);
}
