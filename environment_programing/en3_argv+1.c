#include <stdio.h>

int main(int argc, char *argv[]){
	int i;

	// 첫 번째 인수를 제외한 모든 인수들에 대해
	for(i=1; i<argc; i++){
		// 명령라인 인수의 첫 글자가 '-'면 옵션
		if(argv[i][0] == '-')
			printf("option : %s\n", argv[i]+1);
		// 그렇지 않으면 인수
		else
			printf("argument : %s\n", argv[i]);
	}
}

/* 프로그램 실행 시, 옵션과 인수를 구분해 출력
	> ./en3_argv+1 -l linux -a
	option : l
	argument : linux
	option : a
*/
