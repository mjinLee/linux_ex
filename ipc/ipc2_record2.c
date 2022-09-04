// 레코드 잠금
// 읽기/쓰기 잠금 파일의 읽기/쓰기 잠금 시도 2

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int fd;
	struct flock filelock;

	filelock.l_type = (!strcmp(argv[1],"r"))?F_RDLCK:F_WRLCK;
	// 파일 전체를 영역으로
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;

	fd = open(argv[2],O_RDWR); // argv[2] 파일 열기
	// fd 파일에 대해 filelock 형태로 레코드 잠금을 설정
	// 설정에 실패하면 -1을 반환
	if(fcntl(fd,F_SETLK,&filelock)==-1){
		perror("fcntl failed");
		exit(1);
	}
	// 레코드 잠금에 성공하면 실행
	printf("success\n");
	exit(0);
}

/* ipc1_record.c 백그라운드로 실행 후 ipc2_record2.c를 실행
   이전 파일에서 locking이 되어 있어서 이 실행 결과는 write가 안 되므로 locking 실패가 될 것임 */

/* - temp 파일에 읽기 또는 쓰기 잠금 설정(앞선 예제에서 읽기 잠금 설정 시)
   > ./ipc2_record2 r temp
   success
   > ./ipc2_record2 w temp
   fcntl failed: Resource temporarily unavailable
   - temp 파일에 읽기 또는 쓰기 잠금 설정(앞선 예제에서 쓰기 잠금 설정 시)
   > ./ipc2_record2 r temp
   fcntl failed: Resource temporarily unavailable
   > ./ipc2_record2 w temp
   fcntl failed: Resource temporarily unavailable
*/
