#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // getopt()

// getopt()를 사용해 명령라인 분석
// 미옵션 인수도 출력
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
			case '?':
				printf("unknown option : %c\n",optopt);
		}
	}
	// 처리되지 않은 인수들을 출력
	// optind에 다음에 처리해야 할 인수의 argv 첨자 저장
	for(; optind<argc; optind++)
		printf("argument : %s\n", argv[optind]);
	exit(0);
}

// en5_getopt_unknown_gdb결과.txt 참고
/* 프로그램 실행 시.
	> gdb en5_getopt_unknown
	 (gdb)break 11
	 (gdb)break 30
	 (gdb)run -f test.c hello world -f test2 c programming
	 (gdb)print optind
	 $1 = 3
	 (gdb)continue
	 ...
	 $3 = 5   // optind 변수값이 5로 변함
	 (gdb)print argv[4]
	 $4 = 0x7fffffffe9aa "test2"   // getopt() 실행 수 명령 라인 변경
	 (gdb)print argv[5]
	 $5 = 0x7fffffffe99b "hello"
*/
