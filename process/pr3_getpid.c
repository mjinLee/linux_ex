// 부모와 자식 프로세스의 프로세스 ID를 각각 출력
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t pid;

	if((pid=fork())==-1)
		perror("fork failed");
	// 부모 프로세스는 자신과 자식 프로세스의 프로세스 ID 출력
	else if(pid != 0)
		// getpid는 자신의 프로세스 ID를 반환하는 함수
		printf("PID is %d, child process pid is %d\n",getpid(),pid);
	// 자식 프로세스는 자신과 부모 프로세스의 프로세스 ID 출력
	else
		// getppid는 부모 프로세스의 프로세스 ID를 반환하는 함수
		printf("PID is %d, parent process pid is %d\n",getpid(),getppid());
}

/*	> ./pr3_getpid
	PID is 2700, child process pid is 2701
	PID is 2701, parent process pid is 2700

	> ./pr3_getpid
	PID is 2690, child process pid is 2691
	> PID is 2691, parent process pid is 1
	 // 1 : 부모 프로세스가 자식 프로세스보다 먼저 종료 시, init 프로세스가 부모 프로세스가 된다. (pa aux 명령어로 init 프로세스의 pid가 1이라는 것 확인 가능)
	// 좀비 프로세스: 부모 프로세스가 먼저 종료한 자식 프로세스
*/
