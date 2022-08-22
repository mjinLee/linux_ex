// getuid(), getgid() 사용해 사용자 및 그룹 ID 출력
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	// 실제 사용자 ID를 알아 냄
	printf("UserId : %d\n", getuid());
	// 실제 그룹 ID를 알아 냄
	printf("GroupId : %d\n", getgid());
	exit(0);
}
