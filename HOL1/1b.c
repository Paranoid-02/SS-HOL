//Akshay Sharma MT2024016
//Hard link (link system call) 

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
