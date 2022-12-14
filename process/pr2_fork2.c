// 부모와 자식 프로세스 간 별도의 코드 실행
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t pid;
	
	// pid에는 fork의 반환 값이 저장. 호출에 실패했을 경우엔 -1 저장
	if((pid=fork())==-1)
		perror("fork failed");
	// 이 조건이 참인 프로세스는 부모 프로세스인데, 부모 프로세스의 pid 변수에는 0이 아닌 자식 프로세스의 프로스세 ID가 저장되기 때문
	else if(pid != 0)
		printf("parent process\n");
	// pid가 0이라는 의미가 되므로 현재 프로세는 자식 프로세스인데, 자식 프로세스의 pid 변수에는 0이 저장되기 때문
	else
		printf("child process\n");
}
