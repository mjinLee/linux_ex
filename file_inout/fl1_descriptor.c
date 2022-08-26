#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
	int fd1, fd2;

	// Lee 파일을 읽기 전용으로 열기.
	// 반환되는 양의 정수 값을 파일 식별자라 함
	fd1 = open("Lee",O_RDONLY);
	// You 파일을 쓰기 전용으로 열기
	fd2 = open("You",O_WRONLY);
	// 배정받은 파일 식별자를 출력
	printf("Lee's file descriptor: %d\nYou's file descriptor: %d\n",fd1,fd2);
	// 파일 식별자를 이용해서 파일 닫음
	close(fd1);
	close(fd2);
}

/* -프로그램 실행시
   Lee's file descriptor: -1
   You's file descroptor: -1
   -Lee & You 파일 생성 후 재실행
   Lee's file descriptor: 3
   You's file descriptor: 4
