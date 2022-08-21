#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int main(){
	int fd;
	
	if((fd=open("nodata",O_RDONLY))==-1){
		// ENOENT 는 '그와 같은 파일 또는 디렉토리가 없다'는 의미의 매크로
		if(errno == ENOENT)
			printf("nodata is not exist\n");
		else
			printf("unexpected error: errno = %d\n",errno);
		exit(1);
	}
	exit(0);
}

// open() 호출 실패 시, errno 값이 ENOENT와 같은지 확인
// 출력 결과: nodata is not exist
