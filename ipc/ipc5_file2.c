// File을 이용한 프로세스 간 통신

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define SIZE 20

int main(int argc, char *argv[]){
	int fd;
	struct flock filelock;
	char buffer[SIZE];
	int length;

	filelock.l_type = F_RDLCK; // 읽기잠금
	// 파일 전체를 영역으로
	filelock.l_whence = SEEK_SET;
	filelock.l_start=0;
	filelock.l_len=0;

	fd=open(argv[1],O_RDWR); // argv[1] 파일 열기
	// fd 파일에 대해 읽기 잠금을 설정. 이미 레코드 잠금이 설정되어 있으면 해제될 때까지 기다림
	if(fcntl(fd, F_SETLKW,&filelock)==-1){
		perror("fcntl failed"); exit(1);
	}
	printf("locked %s\n",argv[1]);
	// 파일에서 데이터 읽기
	length = read(fd, buffer,SIZE);
	// 읽은 데이터를 표준출력장치에 출력
	write(STDOUT_FILENO,buffer,length);
	printf("unlocked %s\n",argv[1]);
	exit(0);
}

/* 파일을 이용해 프로세스간 통신
    - ipc4_file가 temp에 잠금설정후 파일에 데이터 씀
    - ipc5_file2가 temp 파일에 잠금설정 시도하나, 이미 잠금설정이 되어 있어 대기
    - ipc4_file가 temp 파일잠금해제시, ipc5_file2가 temp 파일잠금설정후 데이터 읽은 후 출력
    > ./ipc4_file temp &
   [1] 3738
   
    locked temp

    > ./ipc5_file2 temp
   unlocked temp
   locked temp
   Hi Linux
   unlocked temp
   [1]+  완료		./ipc4_file temp
*/
