// 자식 프로세스 종료 시, 반환값 출력
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // wait()
#include <sys/wait.h> // wait()
#include <unistd.h>

int main(){
	int pid, child_pid, status;

	if((pid=fork())==-1)
		perror("fork failed");
	// 부모프로세스는 자식프로세스가 종료될 때까지 아무 일 하지 않고 기다림
	else if(pid!=0){
		// wait를 호출하여 자식 프로세스가 종료할 때까지 기다림
		// 자식 프로세스가 종료되면 자식프로세스의 프로세스ID가 child_pid에 저장되고, 종료될 때의 상태정보가 sataus에 저장
		child_pid = wait(&status);
		// status를 16진수 형태(%x)로 출력. 실행 결과의 300은 우측8비트가 0이고 좌측 8비트가 3이라는 것이므로 정상 종료이면서 exit(no)의 no가 3이란 의미
		printf("child[pid:%d] terminated with code %x\n",child_pid,status);
	// 자식 프로세스는 출력하고 exit에 의해 종료
	} else{
		printf("run child\n");
		// exit(3)에 의해 3을 반환하고 종료하는데 이 3이라는 값이 부모프로세스의 status의 좌측 8비트에 저장
		exit(3);
	}
}
