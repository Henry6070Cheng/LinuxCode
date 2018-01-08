#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

main(){
     int fd;
	 ssize_t length_w;
	 char *testwrite = "/bin/testwrite";
	 char buffer_write[] = "Hello Write Function!";
	 
	 if((fd = open(testwrite,O_RDWR|O_CREAT,0777))<0){
		 printf("open %s failed!\n");
	 }
	 length_w = write(fd,buffer_write,strlen(buffer_write));
	 if (length_w == -1){
		 perror("write error\n");
	 }
	 else{
		 printf("write function success\n");
	 }
	 
	 close(fd);
}