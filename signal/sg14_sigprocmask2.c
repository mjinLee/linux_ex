// 시그널 블록 설정하고 10초 후 SIGINT 블록 해제 후 pause를 통해 시그널의 도착을 기다림

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int singno);

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
	// oldset의 시그널들이 블록화된 시그널 집합으로 교체되는데 이 상황에서는 SIGINT 시그널에 대한 블록이 해제
	sigprocmask(SIG_SETMASK,&oldset,NULL);
	// 시그널이 도착할 때까지 실행을 중단
	pause();
	exit(0);
}

void signalHandler(int signo){
	printf("Hi! signal %d\n",signo);
}

/* (1) SIGINT는 블록되었다가 두 번째 sigprocmask에 의해 SIGINT 블록이 해제되면서, 블록되었던 SIGINT를 받게 되어 signalHandler를 실행하고 pause에 의해 다시 실행을 중단
   (2) signalHandler를 실행하고 pause에 의해 다시 실행을 중단
   (3) pause에서 깨어남과 동시에 signalHandler를 실행하고 프로세스를 종료
   => (1)과 (2)의 경우 두 번의 SIGINT 시그널이 발생해야 프로세스가 종료
      이를 해결하려면, 시그널의 해제와 동시에 시그널을 대기해야 함 */
