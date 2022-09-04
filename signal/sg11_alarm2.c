// 1) alarm(0)을 사용해 이전에 설정한 알람을 취소
// 2) 자식 프로세스가 SIGALRM에 의해 종료

#include <stdio.h>
//#include <stdlib.h>
#include <unistd.h>
//#define MAX 100
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	/* char buffer[MAX];
	int n;

	// 10초 후에 SIGALRM 시그널을 자신에게 보냄
	alarm(10);
	n = read(0,buffer,MAX);
	// SIGALRM 시그널을 받기 전에 실행하면 SIGALRM 시그널 요청은 취소
	alarm(0);
	write(1,buffer,n);
	exit(0); */
	
	int status;
	
	if(fork()){
		// 부모프로세스는 자식프로세스가 종료되기를 기다림
		wait(&status);
		printf("child process terminated with code %x\n",status);
	} else{
		// 자식프로세스는 3초 후에 SIGALRM 시그널을 자신에게 보냄
		alarm(3);
		printf("looping forever...\n");
		while(1)
			;
	}
}
