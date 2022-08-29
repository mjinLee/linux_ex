// 링크 함수 이용해 파일 이름 변경
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	// argv[1]에 대한 링크 argv[2]를 생성하여 argv[1]과 argv[2]는 같은 파일이 됨
	if(link(argv[1],argv[2])==-1){
		perror("link failed"); exit(1);
	}
	// argv[1] 링크를 삭제하나 argv[2]는 지워지지 않음
	// 결국 argv[1]이 argv[2]로 이름이 변경
	if(unlink(argv[1])==-1){
		perror("unlink failed");
		unlink(argv[2]);
		exit(1);
	}
	printf("move %s to %s\n",argv[1],argv[2]);
	exit(0);
}
