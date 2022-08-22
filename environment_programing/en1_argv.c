#include <stdio.h>
#include <stdlib.h>

// 명령라인 인수를 가져옴
// argc : 인수의 개수
// argv : 인수의 내용
int main(int argc, char *argv[]){
	int i;

	// 인수의 개수 출력
	printf("argc : %d\n", argc);

	// 인수의 내용 출력
	for(i=0; i<argc; i++)
		printf("argv[%d] : %s\n",i, argv[i]);
	
	exit(0);
}

/* 프로그램 실행 시, 명령 인수 출력
	> ./en1_argv linux program
	argc : 3
	argv[0] : ./en1_argv
	argv[1] : linux
	argv[2] : program  */
