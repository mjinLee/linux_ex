// SIGPIPE 시그널 제거 후 시그널 집합에 속하는지 확인
// SIGPIPE : 닫힌 파이프에 쓰고자 할 때 보내지는데 이 시그널을 받으면 종료

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(){
	sigset_t set;
	
	// 모든 시그널을 포함하는 시그널 집합 set 생성
	if(sigfillset(&set)==-1){
		perror("sigfillset failed"); exit(1);
	}
	// set에서 SIGPIPE 삭제
	if(sigdelset(&set,SIGPIPE)==-1){
		perror("sigdelset failed"); exit(1);
	}
	// SIGPIPE가 set에 속하는지 확인
	if(sigismember(&set,SIGPIPE))
		printf("SIGPIPE is a member\n");
	else
		printf("SIGPIPE is not a member\n");
	exit(0);
}
