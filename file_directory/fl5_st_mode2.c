// 접근 권한 출력
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	struct stat st;
	
	if(stat(argv[1],&st)==-1){
		perror("stat failed"); exit(1);
	}
	
	// (st.st_mode & S_IRUSR) 수식은 소유자에게 읽기 권한이 있는지를 파악하는 식으로 참이면 "read"가 선택되고, 거짓이면 ""이 선택
	printf("user: %s%s%s\n",(st.st_mode & S_IRUSR) ? "read " : "", (st.st_mode & S_IWUSR)?"write ":"", (st.st_mode & S_IXUSR)?"execute":"");
	printf("group: %s%s%s\n",(st.st_mode & S_IRGRP) ? "read " : "", (st.st_mode & S_IWGRP)?"write ":"", (st.st_mode & S_IXGRP)?"execute":"");
	printf("others: %s%s%s\n",(st.st_mode & S_IROTH) ? "read " : "", (st.st_mode & S_IWOTH)?"write ":"", (st.st_mode & S_IXOTH)?"execute":"");
	exit(0);
}

/*	st_mode의 우측 3자리(접근권한)가 644일 때,
	  st_mode  110 100 100
	& S_IRUSR  100 000 000
	----------------------
		   100 000 000	// 1이 아니므로, 참이 되어 read가 출력됨
*/
