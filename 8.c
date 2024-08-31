/*
============================================================================
Name : 8.c
Author : Akshay Sharma
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read. Close the file when end of file is reached.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
const char EOL = '\n';

int main(){
   FILE* fd = fopen("file.txt","r");
   if(fd == NULL){
	perror("INVALID FILE");
	exit(0);
   }
	int c = fgetc(fd);
	char buffer[1024];
	int k = 0;
	while(c!=EOF){
	 while(c!=EOL){
	  buffer[k] = c;
	  k++;
	  c = fgetc(fd);
  	 }
	
	 buffer[k++] = '\n';
	 write(1,buffer,k);
	 buffer[0] = '\0';
	 k=0;
	 c = fgetc(fd);
	}
	fclose(fd);
	return 0;  
}

/*
Hello World!
Hello World!
*/