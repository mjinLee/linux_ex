// 부모프로세스는 pause에 의해 실행 중단. 자식프로세스가 5초 후 kill()로 SIGINT 시그널을 부모에게 전송. 부모프로세스는 핸들러 함수 실행 후 종료
// pause() : 임의의 시그널이 도착할 때까지 실행 중단

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h> // pause()

static int signal_flag = 0;
void signalHandler(int signo);

int main(){
	struct sigaction act;

	// 부모 프로세스는
	if(fork()){
		printf("parent process\n");
		act.sa_handler = signalHandler;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;
		// SIGINT에 대해 act 행동을 하도록 설정
		sigaction(SIGINT, &act,NULL);
		pause();
		if(signal_flag)
			printf("signal fired\n");
		exit(0);
	// 자식 프로세스는
	} else{
		sleep(5);
		// 부모 프로세스에 SIGINT 시그널 보냄
		kill(getppid(),SIGINT); 
		// getppid는 부모 프로세스의 프로세스 ID를 반환
		exit(0);
	}
}

void signalHandler(int signo){
	signal_flag = 1;
}
		// 
