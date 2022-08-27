// ftruncate() 이용해 파일 크기를 100바이트로 변경
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h> // ftruncate()

int main(int argc, char *argv[]){
	int fd;
	
	if((fd=open(argv[1],O_WRONLY))==-1){
		perror("open failed");
		exit(1);
	}
	// fd 파일을 100바이트 크기로 자름
	if(ftruncate(fd,100)==-1){
		perror("ftruncate failed");
		exit(1);
	}
	close(fd);
	exit(0);
}
