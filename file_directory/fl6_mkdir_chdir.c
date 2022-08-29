// 디렉토리 생성 후, 해당 디렉토리에 파일 저장
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // mkdir()
#include <sys/stat.h> // mkdir()
#include <fcntl.h> // mkdir()
#include <unistd.h> // mkdir(), chdir() 
#include <string.h> // strlen()

int main(int argc, char *argv[]){
	int fd;

	if(mkdir(argv[1],0755)==-1){ // argv[1] 디렉토리를 생성
		perror("mkdir failed"); exit(1);
	}
	if(chdir(argv[1])==-1){ // argv[1] 디렉토리로 이동
		perror("chdir failed"); exit(1);
	}

	// argv[2] 파일을 쓰기 전용으로 여는데 만약 파일이 없으면 생성
	if((fd=open(argv[2],O_WRONLY | O_CREAT,0644))==-1){
		perror("open failed"); exit(1);
	}

	// fd 파일에 argv[3] 문자열 쓰기
	write(fd, argv[3], strlen(argv[3]));

	close(fd);
	exit(0);
}
