#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
	int fd;
	
	/* Lee 파일을 읽기 전용으로 열기
	   만약 호출에 실패하게 되면 -1이 반환되므로
	   if 조건이 참이 됨 
	if((fd=open("Lee",O_RDONLY))==-1){ */

	/* 현재 디렉토리에 Lee 파일이 있으면 읽기전용으로 열고,
	   없으면 현재 디렉토리에 0바이트 크기의 Lee을 생성하고 이를 연다
	   생성된 파일의 접근 권한 정보는 0644 
		O_CREAT 플래그 이용해 파일 열기 (파일 없으면 생성)
	if((fd=open("Lee",O_RDONLY | O_CREAT,0644))==-1){ */

	/* 현재 디렉토리에 Lee파일이 있으면 open 함수 호출에 실패하여
	   -1을 반환하고, 만약 없다면 현재 디렉토리에 Lee를 생성하고
	   읽기 전용으로 연다 
		O_EXCL 플래그 옵션: 파일 존재 시, open() 호출 실패
	if((fd=open("Lee",O_RDONLY | O_CREAT | O_EXCL,0644))==-1){ */

	/* Lee 파일이 있으면 파일을 쓰기 전용으로 열어 0바이트로 자르고,
	   만약 없다면 0바이트 크기의 Lee을 생성하고 쓰기전용으로 연다
		O_TRUNC: 파일 존재 시, 파일의 길이(크기)를 0으로 설정(파일 내용 삭제) */
	if((fd=open("Lee",O_WRONLY | O_CREAT | O_TRUNC,0644))==-1){ 
		perror("open failed");
		exit(1);
	}
	// fd 파일 닫기
	close(fd);
	exit(0);
}

// Lee 파일 삭제 시, open 함수 호출 실패해, 에러 메시지 출력

/* O_TRUNC 플래그 이용해 파일 열기(파일 존재 시, 파일 크기 0으로 만듦)
 	> ls -l Lee
	-rw-r--r-- 1 ... 10 ...
	> ./fl2_open
	> ls -l Lee
	-rw-r--r-- 1 ... 0 ...
*/
	
