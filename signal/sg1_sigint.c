// SIGINT 시그널 추가 후 시그널 집합에 속하는지 확인
// SIGINT : 터미널에서 인터럽트 키를 눌렀을 때 보내지는데 이 시그널을 받으면 종료

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(){
	sigset_t set; // 시그널 집합의 데이터형: sigset_t

	// 빈 시그널 집합 set 생성
	if(sigemptyset(&set)==-1){
		perror("sigemptyset failed"); exit(1);
	}
	// set에 SIGINT 추가
	if(sigaddset(&set,SIGINT)==-1){
		perror("sigaddset failed"); exit(1);
	}
	// SIGINT가 set에 속하는지 확인
	if(sigismember(&set,SIGINT))
		printf("SIGINT is a member\n");
	else
		printf("SIGINT is not a member\n");
	exit(0);
}
