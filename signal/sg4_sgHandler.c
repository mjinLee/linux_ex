// SIGINT 시그널 시 핸들러 함수 실행 후 SIGINT 시그널 기본설정으로 재설정 해 SIGINT 시그널에 의해 종료

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void signalHandler(int signo);

int main(){
	// SIGINT 시그널 받으면 signalHandler 실행하도록 설정
	signal(SIGINT,signalHandler);
	while(1){
		printf("Hello World\n");
		sleep(1);
	}
}

void signalHandler(int signo){
	printf("Hi! signal %d\n",signo); // signo : 시그널 번호
	// SIGINT 시그널 받으면 시스템에서 기본적으로 설정한 동작을 하도록 설정
	signal(SIGINT,SIG_DFL);
}
