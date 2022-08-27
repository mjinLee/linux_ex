// Lee 파일 크기 계산
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 100 // buf의 크기를 나타내는 매크로

int main(){
	int fd,i;
	char buf[MAX];
	long int length = 0;
	
	if((fd=open("Lee",O_RDONLY))==-1){
		perror("open failed");
		exit(1);
	}
	// fd 파일의 크기를 계산하는 부분
	// read가 반환하는 값은 실제 읽어 들인 데이터의 바이트 수
	while((i=read(fd,buf,MAX))>0)
		length += i;
	printf("Total characters in Lee: %ld\n",length);
	close(fd);
	exit(0);
}
