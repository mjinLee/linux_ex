#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(){
	int i;

	// 오류 번호 1-124에 대한 설명 출력
	for(i=0; i<125; i++)
		printf("[%3d] %s\n",i,strerror(i));
	exit(0);
}

// 프로그램 실행 시, 각 오류 관련 매크로의 설명 출력
