#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

main(){
	int fd;
	char *adc = "/dev/adc";
	char buffer[512];
	int len = 0,r = 0;
	
	memset(buffer,0,sizeof(buffer));
	
	printf("adc ready\n");
	
	if((fd = open(adc,O_RDWR|O_NOCTTY|O_NDELAY))<0){
		printf("Open %s err\n",adc);
	}
	else{
		printf("Open adc success\n");
		
		len = read(fd,buffer,10);
		
		if(len == 0){
			printf("return null\n");
		}
		else{
			r = atoi(buffer);
			r = (int)(r*10000/4095);
			printf("res value is %d\n",r);
		}
	}
}