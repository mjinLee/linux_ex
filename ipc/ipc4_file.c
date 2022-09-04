// File을 이용한 프로세스 간 통신

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int fd;
	struct flock filelock;

	filelock.l_type = F_WRLCK; // 쓰기잠금
	// 파일 전체를 영역으로
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;

	// argv[1] 파일을 여는데 없으면 생성
	fd = open(argv[1],O_RDWR | O_CREAT,0666);
	// fd 파일에 대해 쓰기 잠금을 설정
	if(fcntl(fd,F_SETLK,&filelock)==-1){
		perror("fcntl failed"); exit(1);
	}
	printf("locked %s\n",argv[1]);
	// 파일에 데이터 쓰기
	write(fd,"Hi Linux\n",9);
	sleep(10);
	printf("unlocked %s\n",argv[1]);
	// 종료하면 레코드 잠금은 자동적으로 해제
	exit(0);
}
