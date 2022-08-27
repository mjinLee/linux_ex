/* 표준입력으로 받은 내용을 표준출력으로 쓰기
	표준입력 #define STDIN_FILENO   0
	표준출력 #define STDOUT_FILENO  1
	표준에러 #define STDERR_FILENO  2
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 1024

int main(){
	int count;
	char buf[MAX];

	// STDIN_FILENO: 표준입력, 키보드를 통해 이루어짐
	while((count=read(STDIN_FILENO,buf,MAX))>0){
		// STDOUT_FILENO: 표준출력, 모니터를 통해 이루어짐
		if(write(STDOUT_FILENO,buf,count)!=count){
			perror("write failed");
			exit(1);
		}
	}
	exit(0);
}
