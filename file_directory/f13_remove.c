// 파일 또는 디렉토리 삭제
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	if(remove(argv[1])==-1){ // argv[1]을 삭제
		perror("remove failed"); exit(1);
	}
	printf("remove %s\n",argv[1]);
	exit(0);
}
