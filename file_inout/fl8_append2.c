// O_APPEND 플래그 옵션 사용
// 	>[실행파일] file1 file2
// => file1의 내용이 file2에 이어서 써짐
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 1024

int main(int argc, char *argv[]){
	int fd1, fd2;
	int count;
	char buf[MAX];
	
	if(argc !=3){
		perror("argc is not 3");
		exit(1);
	}
	if((fd1=open(argv[1],O_RDONLY))==-1){
		perror("open failed");
		exit(1);
	}

	//O_APPEND 옵션을 추가하고 파일을 열면 읽기/쓰기 포인터가 파일의 끝을 가리킴
	if((fd2=open(argv[2],O_WRONLY|O_APPEND))==-1){
		perror("open failed");
		exit(1);
	}
	while((count=read(fd1,buf,MAX))>0){
		if(write(fd2,buf,count)!=count){
			perror("write failed");
			exit(1);
		}
	}
	close(fd1);
	close(fd2);
	exit(0);
}
