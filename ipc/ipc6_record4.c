// 레코드 잠금(record locking)
// F_GETLK 로 레코드 잠금 정보 획득(잠금설정한 프로세스의 ID 출력)
// F_GETLK : 레코드 잠금 정보를 얻음. 세 번째 인수인 lock에 레코드 잠금 정보가 저장됨

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int arg, char *argv[]){
	int fd;
	struct flock filelock;

	filelock.l_type = F_WRLCK; // 쓰기잠금
	// 파일 전체
	filelock.l_whence = SEEK_SET;
	filelock.l_start=0;
	filelock.l_len=0;

	fd = open(argv[1],O_RDWR);
	// fd 파일이 다른 프로세스에 의해 잠겨있어서 레코드 잠금에 실패하면
	if(fcntl(fd,F_SETLK,&filelock)==-1){
		// 레코드 잠금 정보를 filelock에 얻어옴
		fcntl(fd,F_GETLK,&filelock);
		// filelock.l_pid는 잠금을 설정하고 있는 프로세스의 프로세스ID
		fprintf(stderr,"%s locked by %d\n",argv[1],filelock.l_pid);
		exit(1);
	}
	exit(0);
}

/* ipc4_file을 백그라운드로 실행
   ipc6_record4 실행 시 프로세스 ID 출력
    > ./ipc4_file temp &
   [1] 817
   locked temp
    > ./ipc6_record4 temp
   temp locked by 817
   unlocked temp

   [1]  + 817 done	./ipc4_file temp
*/
