// FIFO 기반 두 프로세스 간 통신 2

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 128 // buffer 크기를 나타내는 매크로
#define FIFO "fifo" // fifo 나타내는 매크로

int main(int argc, char *argv[]){
	int fd, i;
	char buffer[SIZE];

	// fifo 열기
	if((fd=open(FIFO,O_WRONLY))==-1){
		perror("open failed"); exit(1);
	}
	
	// 명령라인 두 번째 인수부터 마지막 인수까지
	for(i=1;i<argc;i++){
		strcpy(buffer,argv[i]);
		// fifo 쓰기
		if(write(fd,buffer,SIZE)==-1){
			perror("write failed"); exit(1);
		}
	}
	exit(0);
}

// ./a.out ***
