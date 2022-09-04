// 레코드 잠금(record locking)
// fcntl() : 파일 제어
// 읽기/쓰기 잠금 파일의 읽기/쓰기 잠금 시도

#include <stdio.h>
#include <string.h>
#include <unistd.h> // fcntl()
#include <fcntl.h> // fcntl()
#include <stdlib.h>

int main(int argc, char *argv[]){
	int fd;
	struct flock filelock;

	// argv[1]의 내용이 "r"이면 F_RDLCK(읽기잠금설정)를,
       // 아니면 F_WRLCK(쓰기잠금설정)를 filelock.l_type에 저장
	filelock.l_type = (!strcmp(argv[1],"r")) ? F_RDLCK : F_WRLCK;
	// 파일 전체를 영역으로
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;
	/* 파일 전체에 locking을 걸고,
	   argv[1] r이면 read locking을 걸고
	   r이 아니면 write locking을 건다
	   argv[2]는 파일 이름 */
	
	// argv[2] 파일을 여는데 없으면 생성
	fd = open(argv[2],O_RDWR | O_CREAT, 0666);

	// fd 파일 즉, argv[2]에 대해 filelock 형태로 레코드 잠금 설정
	if(fcntl(fd,F_SETLK,&filelock)==-1){
		perror("fcntl failed"); exit(1);
	}
	// F_SETLK : 레코드 잠금설정. 다른 프로세스에 의해 레코드가 잠겨 동작이 불가능하면 즉시 실패로 -1을 반환
	printf("locked %s\n",argv[2]);
	sleep(30);
	printf("unlocked %s\n",argv[2]);
	exit(0);
}

/* background process로 실행
   - temp 파일에 읽기잠금설정
    > ./ipc1_record r temp &
   [1] 762
   locked temp

    > ./ipc1_record w temp &
   [2] 763
   fcntl failed: Resource temporarily unavailable
   [2]  + 763 exit 1   ./ipc1_record w temp

    unlocked temp

   [1] + 762 done     ./ipc1_record r temp

   - temp 파일에 쓰기잠금설정
    > ./ipc1_record w temp &
   [1] 764
   locked temp

    unlocked temp

   [1] + 764 done     ./ipc1_record w temp
 */
