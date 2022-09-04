// 레코드 잠금
// F_SETLKW : 레코드 잠금을 설정. 다른 프로세스에 의해 레코드가 잠겨 동작이 불가능하면 가능할 때 까지 기다림

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int fd;
	struct flock filelock;

	filelock.l_type = F_WRLCK; // 쓰기 잠금
	filelock.l_whence = SEEK_SET; // 파일의 시작을 기준으로
	filelock.l_start = 0; // 기준의 처음부터

	fd = open(argv[1],O_RDWR); // argv[1] 파일 열기

	switch(fork()){  // fork에 의해 자식프로세스 생성
		case -1:  // fork 호출에 실패하면
			perror("fork failed");
			exit(1);
		case 0:  // 자식프로세스는
			filelock.l_len = 5; // 5바이트 크기에 대해
			// fd파일에 대해 레코드 잠금을 설정. 이미 레코드 잠금이 설정되어 있으면 해제될 때까지 기다림
			if(fcntl(fd,F_SETLKW,&filelock)==-1){
				perror("fcntl failed"); exit(1);
			}
			printf("child process: locked\n");
			sleep(3);
			filelock.l_type = F_UNLCK; // 레코드 잠금을 해제
			if(fcntl(fd,F_SETLK,&filelock)==-1){
				perror("fcntl failed"); exit(1);
			}
			printf("child process: unlocked\n");
			break;
		default:  // 부모프로세스는
			filelock.l_len = 10; // 10바이트 크기에 대해
			// fd 파일에 대해 레코드 잠금을 설정
			if(fcntl(fd,F_SETLKW,&filelock)==-1){
				perror("fcntl failed"); exit(1);
			}
			printf("parent process: locked\n");
			sleep(3);
			filelock.l_type = F_UNLCK; // 레코드 잠금 해제
			if(fcntl(fd,F_SETLK, &filelock)==-1){
				perror("fcntl failed"); exit(1);
			}
			printf("parent process: unlocked\n");
			wait(NULL); // 자식프로세스가 종료될 때까지 기다림
	}
	exit(0);
}

/* 두 프로세스 중 한 프로세스가 파일을 잠금. 남은 프로세스가 파일 잠금을 실행하나, 파일 잠금이 해제될 때까지 기다림
   > ./ipc3_record3 temp
   parent process: locked
   parent process: unlocked
   child process: locked
   child process: unlocked
   - 부모(자식)프로세스가 temp 파일잠금
   - 자식(부모)프로세스가 temp 파일잠금을 시도함
   - 해당 파일에 이미 잠금 설정이 되어 있어, 잠금이 성공할 때까지 기다림
   - 부모(자식)프로세스가 temp 파일잠금을 해제하면, 자식(부모)프로세스가 temp파일에 잠금을 설정
*/
