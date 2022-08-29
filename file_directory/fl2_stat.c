// 두 개의 파일 중 최근에 수정된 파일을 출력
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // stat()
#include <sys/stat.h> // stat()
#include <unistd.h> // stat()

int main(int argc, char *argv[]){
	struct stat st1, st2;

	if(stat(argv[1],&st1)==-1){
		perror("stat failed"); exit(1);
	}
	if(stat(argv[2],&st2)==-1){
		perror("stat failed"); exit(1);
	}
	// st1.st_mtime이 크면 argv[1]이 선택되고, 그렇지 않으면 argv[2]가 선택
	printf("%s is up-to-date file\n",(st1.st_mtime > st2.st_mtime)?argv[1]:argv[2]);
	exit(0);
}
