/*
============================================================================
Name : 1b.c
Author : Akshay Sharma
Description : Link System Call - Hard Link
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
	int li = link("greetings.sh","ghard.sh");
	if(li == -1){
		perror("link");
		return 1;
	}
	return 0;	
}
