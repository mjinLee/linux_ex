// alphabet 파일로부터 10바이트씩 읽고, 첫 문자 출력
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // close()
#include <unistd.h> // read()
#define MAX 10

int main(){
	int fd;
	char buf1[MAX], buf2[MAX];
	// alphabet 파일을 읽기 전용으로 열기
	if((fd = open("alphabet", O_RDONLY))==-1){
		perror("open failed");
		exit(1);
	}
	// fd 파일로부터 처음 MAX바이트 크기만큼의 문자를 읽어 buf1에 저장
	read(fd, buf1, MAX);
	// fd 파일로부터 19라인에서 읽힌 다음으로부터 MAX바이트 크기만큼의 문자를 읽어 buf2에 저장
	read(fd, buf2, MAX);
	printf("buf1[0]: %c\nbuf2[0]: %c\n", buf1[0], buf2[0]);
	close(fd);
	exit(0);
}
