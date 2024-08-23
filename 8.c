#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
const char EOL = '\n';

int main(){
   FILE* fd = fopen("file1","r");
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
