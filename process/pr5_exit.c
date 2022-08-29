// exit() 호출해 부모와 자식 프로세스 종료
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t pid;
	
	if((pid=fork())==-1){
		perror("fork failed");
		exit(1); // fork 호출에 실패하면 1을 반환하고 종료
	} else if(pid != 0){
		printf("parent process\n");
		exit(2); // 부모 프로세스는 2를 반환하고 종료
	} else{
		printf("child process\n");
		exit(3); // 자식 프로세스는 3을 반환하고 종료
	}
}
// 프로그램 종료 후 "echo $?" 명령어로 프로그램 종료 값 출력
