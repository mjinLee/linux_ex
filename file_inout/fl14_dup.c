// 표준출력에 대해 새로운 파일 식별자를 부여 받아 사용
// dup() : 사용하지 않고 있던 파일 식별자 번호 중 가장작은 번호를 반환
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h> // dup()

int main(){
	int fd;

	// 1번 파일 식별자에 새로운 파일 식별자를 부여받아 fd에 저장
	// 1번은 표준출력(:모니터)을 의미하므로 fd도 표준출력을 나타냄
	// 표준출력에 대한 파일 식별자는 1과 fd 두 개임
	if((fd=dup(1))==-1){
		perror("dup failed");
		exit(1);
	}
	// fd번 파일에 "ABCD"를 쓰는 동작으로 표준출력장치인 모니터로 출력
	write(fd, "ABCD",5);
	exit(0);
}
