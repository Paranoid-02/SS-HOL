//Akshay Sharma MT2024016
//Soft link (symlink system call) 

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
