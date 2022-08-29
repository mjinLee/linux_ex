// 루트 디렉토리 변경
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	// 루트 디렉토리를 /home/Lee/book/linux/chap22로 변경
	if(chroot("/home/ubuntu/system_programming/file_directory")==-1){
		perror("chroot failed"); exit(1);
	}
	if(chdir("/")==-1){ // 루트 디렉토리로 이동
		perror("chdir failed"); exit(1);
	}
	if(mkdir("rootsub",0777)==-1){ // rootsub 디렉토리를 생성
		perror("mkdir failed"); exit(1);
	}
	exit(0);
}
