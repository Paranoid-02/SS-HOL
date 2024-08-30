/*
============================================================================
Name : 7.c
Author : Akshay Sharma
Description : Write a program to copy file1 into file2.
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<fcntl.h>

int main(int argc,char *argv[]){
	int file1 = open(argv[1], O_RDONLY);
	if(file1<0){
	  perror("file invalid");
	  exit(0);
	}
	int file2 = open(argv[2],O_WRONLY | O_EXCL | O_CREAT, 0600);
	if(file2<0){
	  perror("file invalid");
	  exit(0);
	}

	char buffer[1024];
	int n;
	while ((n = read(file1, buffer, sizeof(buffer))) > 0) {
        	write(file2, buffer, n);
	}
	close(file1);
	close(file2);
	return 0;
}
