#include <stdio.h>
#include <errno.h> // errno 변수를 선언하는 헤더 파일
#include <stdlib.h> // exit()

int main(){
	FILE *fp;

	// fopen 함수 호출에 실패하면 NULL 반환
	if((fp = fopen("nodata","r"))==NULL){
		// 오류 발생하면 errno에 오류번호 저장
		printf("errno = %d\n",errno);
		exit(1); // 종료
	}
	exit(0); // 종료
}

/* 프로그램 실행 시, errno=2 출력
   nodata 라는 파일을 열려고 시도하나,
   fopen() 호출에 실패해 NULL이 반환되며,
   errno에 저장된 오류 번호를 출력 */
