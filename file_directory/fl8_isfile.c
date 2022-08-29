// 디렉토리에 파일 존재 여부 검사
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

int find_file(char *dir, char *file);

int main(int argc, char *argv[]){
	if(find_file(argv[1],argv[2])){ 
		// argv[1] 디렉토리에 argv[2] 파일이 있으면
		printf("found %s\n",argv[2]);
	} else // 없으면
		printf("not found %s\n",argv[2]);
	exit(0);
}

// dir 디렉토리에 file 파일이 있으면 1을 반환하는 함수
int find_file(char *dir, char *file){
	DIR *dp; // 디렉토리 정보에 대한 포인터
	struct dirent *drip; // 디렉토리의 한 항목의 정보에 대한 포인터

	if((dp=opendir(dir))==NULL){ // dir 디렉토리 열기
		perror("opendir failed"); exit(1);
	}
	// dp 디렉토리의 항목을 하나씩 읽어 동작
	while(drip=readdir(dp)){ 
	// 항목 이름(d_name)이 file과 같으면 1을 반환
		if(!strcmp(drip->d_name,file)){
			closedir(dp);
			return 1;
		}
	}
	closedir(dp); // dp 디렉토리 닫기
	return 0; // 발견하지 못하면 0을 반환
}
