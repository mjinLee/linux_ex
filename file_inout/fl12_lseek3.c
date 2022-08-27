// lseek() 이용해 파일 크기 알아냄
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int fd;
	off_t filesize;
	if((fd=open(argv[1],O_RDONLY))==-1){
		perror("open failed");
		exit(1);
	}
	// 읽기/쓰기 포인터가 파일의 끝을 가리키게 되고,
	// 변경된 읽기/쓰기 포인터가 반환되는데 이는 파일의 크기가 됨
	if((filesize=lseek(fd,0,SEEK_END))==-1){
		perror("lseek failed");
		exit(1);
	}
	printf("%s\'s size is %ld\n", argv[1],filesize);
	close(fd);
	exit(0);
}

/* 	> gcc fl12_lseek3.c
	> ./a.out Lee
	Lee's size is 33
	> ls -l Lee
	-rw-r... 1 ... 33 .. Lee

  O_APPEND 플래그 효과를 이용해 구현할 수 있다
	lseek(fd,0,SEEK_END)
*/ 
