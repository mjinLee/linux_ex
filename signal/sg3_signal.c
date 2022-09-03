/* SIGINT 시그널로 프로세스 종료
    SIGINT 시그널의 기본 동작은 프로세스 종료 */
// SIGINT 시그널을 무시함. CTRL + \ 로 프로세스 종료
// SIGINT 시그널을 무시 후, count가 5가 되면 SIGINT 시그널을 기본동작으로 재설정 해 SIGINT 시그널에 의해 종료

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(){
	int count = 0;

	// SIGINT 시그널 받으면 무시(SIG_IGN)하도록 설정
	signal(SIGINT,SIG_IGN);
	while(1){
		printf("Hello World\n");
		sleep(1); // 1초 동안 정지

		// count가 5가 되면
		if(++count == 5)
			// SIGINT 시그널을 받으면 시스템에서 기본적으로 설정한 동작을 하도록(SIG_DFL) 설정
			signal(SIGINT,SIG_DFL);
	}
}
