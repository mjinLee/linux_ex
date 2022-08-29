// 현재 디렉토리의 항목 출력
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> // opendir(), readdir(), closedir()
#include <dirent.h> // opendir(), readdir(), closedir()

int main(){
	DIR *dp; // 디렉토리 정보에 대한 포인터
	struct dirent *dirp; // 디렉토리의 한 항목의 정보에 대한 포인터

	if((dp=opendir("."))==NULL){ // 현재(.) 디렉토리 열기
		perror("opendir failed"); exit(1);
	}
	// dp 디렉토리의 항목들을 하나씩 읽어서 항목 이름을 출력. 더 이상 읽을 항목이 없으면 NULL이 반환됨
	while(dirp=readdir(dp)){
		printf("%s ",dirp->d_name);
	}
	printf("\n");
	closedir(dp); // dp 디렉토리 닫기
	exit(0);
}
