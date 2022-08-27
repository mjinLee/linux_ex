// O_APPEND 플래그 옵션을 사용해 파일 끝에 데이터 추가
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 10

int main(){
	int fd;
	char buf[MAX]="C Program";

	// Lee 파일이 있으면 쓰기 전용으로 열고, 읽기/쓰기 포인터가 파일의 끝을 가리키고, 만약 Lee 파일이 없으면 파일을 생성하고 쓰기 전용으로 엶
	if((fd=open("Lee",O_WRONLY|O_CREAT|O_APPEND,0644))==-1){
		perror("open failed");
		exit(1);
	}
	write(fd,buf,MAX);
	close(fd);
	exit(0);
} 
