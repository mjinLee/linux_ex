// print_loop.c 프로세스 pid를 인수로 입력해 종료
/* pid 인수의 값과 의미
    - "ps j" 명령어로 PGID 확인 가능
    - 슈퍼 유저의 프로세스인 경우 아무 프로세스에게 시그널 전송 가능
    - 일반사용자의 프로세스인 경우 보내고받는 프로세스의 사용자ID가 같아야함
   양의 정수 : 프로세스 ID가 pid인 프로세스에 시그널을 보냄
   0         : kill을 호출한 프로세스가 속한 프로세스 그룹의 모든 프로세스에 시그널을 보냄
   -1        : 1번 프로세스를 제외한 모든 프로세스에 큰 번호에서 작은 번호의 프로세스 순으로 시그널을 보냄
   -1 미만   : pid 절대값 프로세스 그룹의 모든 프로세스에 시그널을 보냄 */

// kill() : 프로세스에 시그널 전송
// SIGKILL : 프로세스를 종료시키기 위해 보내는데 이 시그널을 받으면 반드시 종료

#include <stdio.h>
#include <sys/types.h> // kill()
#include <signal.h> // kill()
#include <stdlib.h>

int main(int argc, char *argv[]){
	// argv[1]번 프로세스에 SIGKILL 시그널 보냄
	kill(atoi(argv[1]),SIGKILL); // argv[1]은 문자열이므로 정수로 변환(atoi())
}

//	> ./sg7_kill print_loop
