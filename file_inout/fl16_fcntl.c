// F_GETFL을 이용해 파일의 접근 모드 알아내기
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // fcntl()
#include <sys/types.h>
#include <unistd.h> // fcntl()

int filestatus(int fd, char *file);

int main(int argc, char *argv[]){
	int fd, newfd, mode;

	//argv[2]에 저장되어 있는 정수 형태의 문자열을 정수로 변환하여 mode에 저장
	mode = atoi(argv[2]);
	if((fd=open(argv[1],mode))==-1){
		perror("open failed");
		exit(1);
	}	
	if(filestatus(fd,argv[1])==-1){
		exit(2);
	}
	close(fd);
	exit(0);
}

int filestatus(int fd, char *file){
	int flag;

	// 파일의 상태 정보를 알아내 flag에 저장
	// 가장 우측 두 개의 비트는 00, 01, 또는 10
	if((flag=fcntl(fd,F_GETFL))==-1){
		perror("fcntl failed"); exit(1);
	}
	/* O_ACCMODE는 3이므로 flag & O_ACCMODE 결과는 flag의 가장 우측
	   O_ACCMODE : 어떤 플래그를 가지고 있는지 확인
	   두 개의 비트가 00이면 0, 01이면 1, 10이면 2가 됨
		     flag        ??? ... 10
		O_ACCMODE        000 ... 11
		---------------------------
		flag & O_ACCMODE 000 ... 10
	*/
	switch(flag & O_ACCMODE){
		case O_RDONLY: // O_RDONLY는 0으로 정의
			printf("%s is read only file\n",file);
			break;
		case O_WRONLY: // O_WRONLY는 1로 정의
			printf("%s is write only file\n",file);
			break;
		case O_RDWR: // O_RDWR는 2로 정의
			printf("%s is read-write file\n",file);
			break;
		default:
			printf("no such mode\n");
	}
	return 0;
}

/* O_RDONLY = 0
   O_WRONLY = 1
   O_RDWR = 2
	> ./a.out Lee 0
	Lee is read only file
	> ./a.out Lee 1
	Lee is write only file
	> ./a.out Lee 2
	Lee is read-write file
*/
