// 접근 권한 변경
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // chmod()
#include <sys/stat.h> // chmod()

int main(){
	// Lee의 접근 권한을 0644로 변경
	// 소유자는 읽기, 쓰기 권한, 그룹과 기타 사용자들은 읽기 권한 부여
	if(chmod("Lee",0644)==-1)
		perror("chmod failed");

	// You의 접근 권한 변경
	// 소유자는 읽기, 쓰기 권한, 그룹과 기타 사용자들은 읽기 권한 부여
	if(chmod("You", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)==-1)
		perror("chmod failed");

	exit(0);
}
