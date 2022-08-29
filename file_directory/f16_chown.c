// 소유권 변경(argv[2]의 소유자 및 그룹을 argv[1]의 소유자 및 그룹으로 변경)
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	struct stat st;

	if(stat(argv[1],&st)==-1){ // argv[1] 파일에 대한 정보가 st에 저장
		perror("stat failed"); exit(1);
	}
	// argv[2]의 소유자와 그룹을 st.st_uid와 st.st_gid로 변경
	if(chown(argv[2],st.st_uid,st.st_gid)==-1){
		perror("chown failed"); exit(1);
	}
	exit(0);
}

/* 프로그램 실행 예시
	> ls -l /etc/passwd Lee
	-rw-r--r-- 1 root root 10 ... /etc/passwd
	-rw-r--r-- 1 ubuntu ubuntu 0 ... Lee
	> ./a.out /etc/passwd Lee
	> ls -l /etc/passwd Lee
	-rw-r--r-- 1 root root 10 ... /etc/passwd
	-rw-r--r-- 1 root root 0 ... Lee
*/
