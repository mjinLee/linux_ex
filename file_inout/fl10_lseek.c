#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>	// lseek()
#include <unistd.h>	// lseek()
#define MAX 10

int main(){
	int fd, count;
	char buf[MAX];

	if((fd=open("alphabet",O_RDONLY))==-1){
		perror("open failed");
		exit(1);
	}
	// fd 파일의 읽기/쓰기 포인터를 첫 위치로부터 뒤로 5칸 이동
	lseek(fd,5,SEEK_SET);
	count = read(fd,buf,MAX);
	// 표준 출력 장치로 buf에 있는 count 바이트의 데이터를 출력
	write(STDOUT_FILENO,buf,count);
	close(fd);
	exit(0);
}

// 'fghi...'로 결과 출력
