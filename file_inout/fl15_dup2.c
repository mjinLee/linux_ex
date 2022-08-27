// 입력받은 파일을 dup2()를 이용해 새로운 파일 식별자 부여
// dup2() : oldfd가 가리키는 파일에 newfd로 지정한 파일 식별자 지정
// dup2(int oldfd, int newfd);
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h> // dup2()

int main(int argc, char *argv[]){
	int fd;

	if((fd=open(argv[1],O_WRONLY))==-1){
		perror("open failed");
		exit(1);
	}
	// dup2를 이용하여 fd번 파일에 대한 새로운 파일 식별자 7을 부여받음
	// argv[1] 파일에 대한 파일 식별자는 fd와 7 두 개임
	if((dup2(fd,7))==-1){
		perror("dup2 failed");
		exit(1);
	}
	if(lseek(7,0,SEEK_END)==-1){
		perror("lseek failed");
		exit(1);
	}
	write(7,"ABCD",5);
	close(fd);
	exit(0);
}
