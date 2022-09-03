// waitpid의 option 설정
/* waitpid의 option 값과 의미
   WNOHANG : 자식 프로세스가 종료되지 않더라도 부모 프로세스는 블록화 되지 않고 다른 일을 실행
   0       : wait와 동일하게 자식 프로세스가 종료될 때까지 부모 프로세스는 블록화 됨 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int pid,status;

	if((pid=fork())==-1)
		perror("fork failed");
	// 부모 프로세스
	else if(pid != 0){
		/* // waitpid의 세 번째 인수를 0으로 설정하면 부모 프로세스는 자식 프로세스가 종료될 때까지 블록화. 자식프로세스가 종료되면 자식프로세스의 프로세스 ID가 반환되므로 while문을 벗어남
		while(waitpid(pid,&status,0)==0){ */

		// waitpid의 세 번째인수를 WNOHANG로 설정하여 호출하면 부모프로세스는 자식프로세스가 종료되지 않더라도 블록화되지 않고 다른 일을 실행. 자식프로세스가 종료되지 않은 상태에서 waitpid가 반환하는 값은 0
		while(waitpid(pid,&status,WNOHANG)==0){
			printf("still waiting\n");
			sleep(1); // 1초 동안 실행 중단
		}
	// 자식 프로세스
	} else{
		printf("run child\n");
		sleep(5);
		exit(0);
	}
}
