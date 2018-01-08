#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define MAX_SIZE 1000

main(){
	int fd;
	ssize_t length_w,ret,length_r = MAX_SIZE;
	char *testwrite = "/bin/testwrite";
	char buffer_write[]="Hello Write Function!";
	char buffer_read[MAX_SIZE];
	
	if ((fd = open (testwrite,O_RDWR|O_CREAT,0777))<0){
		printf("open %s failed!\n",testwrite);
	}
	length_w = write (fd,buffer_write,strlen(buffer_write));
	if (length_w == -1){
		perror("write error");
	}
	else{
		printf("write function OK!\n");
	}
	close(fd);
	if ((fd = open (testwrite,O_RDWR|O_CREAT,0777))<0){
		printf("open %s failed!\n",testwrite);
	}
	
	if((ret = read(fd,buffer_read,length_r))<0){
		perror("read error");
	}
	else{
		printf("files content is %s and fd is %s\n",buffer_read,ret);
	}
	close(fd);
		
	
}