// FIFO 기반 통신
// FIFO 기반 두 프로세스 간 통신
/* mkfifo() : FIFO 생성
   - FIFO 이용 시 open() 사용
    mkfifo("fifo",0666);
    fd = open("fifo",O_RDONLY);
   - 생성된 FIFO는 파일이므로 "rm" 명령어로 삭제 가능 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 128 // buffer 크기를 나타내는 매크로
#define FIFO "fifo" // fifo를 나타내는 매크로

int main(int argc, char *argv[]){
	int fd;
	char buffer[SIZE];

	// 접근 권한이 0666인 fifo라는 이름의 FIFO 생성
	if(mkfifo(FIFO,0666)==-1){
		perror("mkfifo failed"); exit(1);
	}
	// FIFO를 사용하기 위해서는 열어야 함
	if((fd=open(FIFO,O_RDWR))==-1){
		perror("open failed"); exit(1);
	}

	// 무한 반복
	while(1){
		// fifo로부터 읽기
		if(read(fd,buffer,SIZE)==-1){
			perror("read failed"); exit(1);
		}
		// 읽은 데이터가 quit이면 종료
		if(!strcmp(buffer,"quit"))
			exit(0);
		// 읽은 데이터를 출력
		printf("receive message: %s\n",buffer);
	}
}

// background로 실행
