// SIGINT 시그널 블록과 동시에 SIGINT 시그널 해제

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signo);

int main(){
	sigset_t set, oldset;
	struct sigaction act;

	act.sa_handler = signalHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	// SIGINT에 대해 act 행동을 하도록 설정
	sigaction(SIGINT,&act,NULL);

	sigemptyset(&set);
	sigaddset(&set,SIGINT);
	// SIGINT 시그널에 블록 설정
	sigprocmask(SIG_BLOCK,&set,&oldset);
	sleep(10);
	// 시그널 블록을 oldset로 설정함과 동시에 시그널이 도착할 때까지 중단
	sigsuspend(&oldset);
	exit(0);
}

void signalHandler(int signo){
	printf("Hi! signal %d\n",signo);
}
