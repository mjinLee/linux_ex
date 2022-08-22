#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // getopt()

// getopt()를 사용해 명령라인 분석
int main(int argc, char *argv[]){
	int opt;
	// 명령라인의 l,f,a,i 옵션 처리
	while( (opt = getopt(argc,argv,"lf:ai")) != -1){
		switch(opt){
			// l,a,i 옵션이면, 옵션을 출력
			case 'l':
			case 'a':
			case 'i':
				printf("option : %c\n",opt);
				break;
			// f 옵션이면 옵션과 인수를 출력
			case 'f':
				printf("option : %c's argument : %s\n",opt,optarg);
				break;
			// 인식되지 않는 옵션 출력
			default:
				printf("unknown option : %c\n",optopt);
		}
	}
	exit(0);
}

/* 프로그램 실행 시.
	> ./en4_getopt -l -f test.c -ai
	option : l
	option f's argument : test.c
	option : a
	option : i
	> ./en4_getopt 'hello world' -o
	./en4_getopt: invalid option -- 'o' // 자체 오류 메시지
	unknown option : o
	> ./en4_getopt -f
	./en4_getopt: option requires an argument -- 'f' // 자체 오류 메시지
	unknown option : f
	> ./en4_getopt -f test -a
	option f's argument : test
	option : a

// 자체 에러 메시지 출력을 막으려면
// opterr 를 0으로 설정
*/
