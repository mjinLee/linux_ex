/* wait vs waitpid
   wait : pr9_wait2.c / waitpid : pr10_waitpid.c
   wait는 자식 프로세스 중 하나라도 종료 시 호출
   waitpid는 특정 프로세스가 종료되기를 기다리도록 지정 가능
   waitpid에서는 자식 프로세스가 종료되지 않아도 부모 프로세스가 다른 일을 할 수 있도록 지정 가능 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int pid, child_pid, status;

	// 첫 번째 자식 프로세스 생성
	if((pid=fork())==-1)
		perror("fork failed");
	// 부모 프로세스
	else if(pid != 0){
		// 두 번째 자식 프로세스 생성
		if((pid=fork())==-1)
			perror("fork failed");
		// 부모 프로세스
		else if(pid != 0){
			// 아무 자식 프로세스나 종료되기를 기다림
			// 여러 자식 프로세스가 있다면 아무 프로세스나 종료되기를 기다림
			child_pid = wait(&status);
			printf("child[pid:%d] terminated with code %x\n",child_pid, status);
		// 두 번째 자식 프로세스
		} else{
			printf("run child2[pid:%u]\n",getpid());
			exit(3);
		}
	// 첫 번째 자식 프로세스
	} else{
		printf("run child1[pid:%u]\n",getpid());
		exit(2);
	}
}

/* 실행 예시
	> ./a.out
	run child2[pid:2821]
	run child1[pid:2920]
	> ./a.out
	run child2[pid:2824]
	run child1[pid:2823]
	child[pid:2823] terminated with code 200
*/
