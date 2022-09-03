// 전달 받은 환경 변수 출력
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 환경 변수 정보를 설정
char *envp[]={"USER=Lee","PATH=/tmp",(char *)0};

int main(){
	// print_envp는 새롭게 실행될 프로그램 이름
	char *arg[]={"print_envp",(char *)0};

	printf("Runnig %s with execve\n",arg[0]);

	// print_envp에 envp에 설정된 환경정보 전달
	execve("./print_envp",arg,envp);

	printf("execve failed to run %s\n",arg[0]);

	exit(0);
}
