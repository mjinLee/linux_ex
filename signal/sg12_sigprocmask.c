// 1) 전체 시그널 블록 후 10초 후 SIGINT 시그널 블록 해제
/* 시그널 블록)
   - 아주 중요한 부분에 대한 작업의 경우 시그널로부터 보호하기 위해 시그널 블록을 설정
   - 시그널 블록 설정 시, 시그널이 오면 해제될 때까지 시그널 처리를 미룸
   - sigprocmask() : 블록될 시그널을 설정
    - 첫 번째 인수 값과 의미)
    	SIG_BLOCK : 기존에 블록화 된 시그널 집합에 set의 시그널들이 추가
	SIG_UNBLOCK : 기존에 블록화 된 시그널 집합에서 set의 시그널들이 제외
	SIG_SETMASK : set의 시그널들이 블록화 된 시그널 집합으로 교체 */
// 2) SIGINT 시그널 블록 후 10초 후 예전 시그널 설정으로 복귀

#include <stdio.h>
#include <signal.h> // sigprocmask()
#include <unistd.h>

int main(){
	/* sigset_t set1, set2;

	// 꽉 찬 시그널 집합 set1 생성
	sigfillset(&set1);
	sigemptyset(&set2);
	// SIGINT를 원소로 하는 시그널 집합 set2
	sigaddset(&set2,SIGINT);

	// 모든 시그널에 블록 설정
	sigprocmask(SIG_BLOCK, &set1, NULL);
	printf("block start\n");
	sleep(10);

	// SIGINT 시그널은 블록에서 해제
	sigprocmask(SIG_UNBLOCK, &set2, NULL);
	printf("SIGINT unblock\n"); */

	sigset_t set, oldset;

	sigemptyset(&set);
	sigaddset(&set,SIGINT);

	// SIGINT에 대해 블록 설정하고 이전 블록화된 시그널 집합을 oldset에 저장
	sigprocmask(SIG_BLOCK,&set,&oldset);
	printf("block start");
	sleep(10);
	// oldset의 시그널들이 블록화된 시그널 집합으로 교체
	sigprocmask(SIG_SETMASK,&oldset,NULL);
	printf("restore to the original state\n");

	while(1){
		printf("Halo World\n");
		sleep(2);
	}
}

/* - 10초 안에 CTRL + C 명령으로 SIGINT 시그널 생성 시, 블록되나, 10초 후 SIGINT 시그널이 해제되면서 pending 되던 SIGINT 시그널이 실행되어 프로세스 종료
   - 10초 후에는 SIGINT 시그널이 블록 해제되어, SIGINT 시그널에 의해 프로세스 종료 */

/* 	set1
	 all signal
	set2
	 SIGINT
	BLOCK signal set
	 all signal - SIGINT */
