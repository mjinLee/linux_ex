#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strerror()
#include <errno.h>

int main(){
	FILE *fp;
	
	// fopen() 호출에 실패하면 NULL
	if((fp=fopen("nodata","r"))==NULL){
		// errno를 설명하는 문자열을 표준 오류인 모니터로 출력
		fprintf(stderr,"ERROR: %s\n",strerror(errno));
		exit(1);
	}
	exit(0);
}

// 프로그램 실행 시, 
//  ERROR: No such file or directory 출력
