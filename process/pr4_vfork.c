// vfork를 사용해 자식 프로세스 ID 출력 후 부모의 ID 출력
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t pid;

	// vfork를 이용해 자식 프로세스 생성
	if((pid=vfork())==-1) // (1)
		perror("fork failed");
	// 부모 프로세스는 자식 프로세스가 exit 호출을 한 후에 동작
	else if(pid != 0) // (3)
		printf("PID is %d, child process pid is %d\n", getpid(),pid);
	// 자식 프로세스는 곧바로 실행
	else{ // (2)
		printf("PID is %d, parent process is %d\n",getpid(),getppid());
		exit(0);
	}
}
