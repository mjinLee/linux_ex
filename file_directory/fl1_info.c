// 파일 크기, 소유자 ID, 그룹 ID, 최종변경시간 출력
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]){
	struct stat st;

	// argv[1] 파일에 대한 정보가 st에 저장
	if(stat(argv[1],&st)==-1){
		perror("stat failed"); exit(1);
	}
	// st.st_size는 파일의 크기, st.st_uid는 파일 소유자 ID, st.st_mtime는 파일에 대한 최종 수정 시간으로, ctime은 시간 정보를 문자열로 변환하는 함수
	printf("%ld byte, user-id %d, group-id %d, modify time %s", st.st_size, st.st_uid, st.st_gid, ctime(&st.st_mtime));
	exit(0);
}
