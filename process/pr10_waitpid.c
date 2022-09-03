// wait vs waitpid
// waitpid를 이용해 첫 번째 자식 프로세스의 종료를 대기
/* waitpid의 pid 값과 의미
    -1  : 여러 자식 프로세스 중 하나라도 종료되기를 기다림
     0  : 호출한 프로세스의 그룹 ID와 같은 그룹 ID를 가지는 자식 프로세스가 종료되기를 기다림
   양수 : pid번 프로세스가 종료되기를 기다림 */ 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int pid1,pid2,child_pid,status;

	// 첫 번째 자식 프로세스 생성
	if((pid1=fork())==-1)
		perror("for failed");
	// 부모 프로세스
	else if(pid1 !=0){
		// 두 번째 자식 프로세스 생성
		if((pid2=fork())==-1)
			perror("fork failed");
		// 부모 프로세스
		else if(pid2 != 0){
			// pid1 프로세스가 종료되기를 기다림
			child_pid = waitpid(pid1, &status,0);
			printf("child[pid:%d] terminated with code %x\n",child_pid,status);
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
