// 모든 시그널 블록 후 sigpending을 사용해 SIGQUIT (CTRL + \) 시그널이 존재하면 종료
// SIGQUIT : 터미널에서 종료 키를 눌렀을 때 보내지는데 이 시그널을 받으면 코어 덤프하고 종료

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int main(){
	sigset_t set, pend;

	sigfillset(&set);
	sigprocmask(SIG_BLOCK,&set,NULL); // 모든 시그널에 블록 설정

	while(1){
		printf("Halo World");
		sleep(2);
		sigpending(&pend); // 블록된 시그널 얻어옴
		if(sigismember(&pend,SIGQUIT))
			// SIGQUIT가 pend에 속해 있으면 종료
			exit(0);
	}
}
