#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main(){
	int fd;
	// nodata 파일을 읽기 전용으로 연다
	if((fd = open("nodata",O_RDONLY))==-1){
		// open 함수 호출에 실패하면 -1 반환
		printf("errno = %d\n",errno);
		exit(1);
	}
	exit(0);
}

/* 프로그램 실행 시, errno=2 출력
   nodata라는 파일을 열려고 시도하나,
   open() 함수 호출에 실패해 -1 반환되며,
   errno에 저장된 오류 번호 출력 */
