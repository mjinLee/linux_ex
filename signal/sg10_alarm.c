// alarm() 이용해 자기 자신에게 SIGALRM 시그널 전송
// SIGALRM : alarm()를 호출하면 보내지는데 이 시그널을 받으면 종료

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void alarmHandler(int signo);

int main(){
	int status;
	struct sigaction act;

	// 시그널에 대해 alarmHandler가 실행되도록 설정
	act.sa_handler = alarmHandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	// SIGALRM에 대해 act 행동을 하도록 설정
	sigaction(SIGALRM,&act,NULL);
	// 3초 후에 SIGALRM 시그널을 자신에게 보냄
	alarm(3);
	while(1) // 무한반복
		;
}

void alarmHandler(int signo){
	printf("Hi! signal %d\n",signo);
	exit(0);
}
