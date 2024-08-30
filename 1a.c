/*
============================================================================
Name : 1a.c
Author : Akshay Sharma
Description : SymLink System Call - Soft Link
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	int link = symlink("greetings.h","gs.h");
	if(link == -1){
		perror("symlink");
		return 1;
	}
	return 0;
}
