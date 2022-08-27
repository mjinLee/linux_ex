// lseek() 이용해 파일 끝에서 뒤로 더 이동
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	int fd;
	if((fd=creat(argv[1],0644))==-1){
		perror("creat failed");
		exit(1);
	}
	write(fd, "abcdefghijklmnopqrstuvwxyz",26);
	// 파일의 끝보다 더 뒤의 위치를 지정하는 것도 가능하며 빈 공간은 NULL로 채워짐
	if(lseek(fd,30,SEEK_SET)==-1){
		perror("lseek failed");
		exit(1);
	}
	write(fd,"ABCD",4);
	close(fd);
	exit(0);
}

/* 	> ./a.out alphabet
	> od -c alphabet	// od 명령어: 8진수로 파일 보기
	0000000  a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p
	0000020  q  r  s  t  u  v  w  x  y  z \0 \0 \0 \0  A  B
	0000040	 C  D
	0000042

  -파일의 시작 지점보다 앞의 위치를 지정할 수 없다
  -lseek()는 변경된 읽기/쓰기 포인터를 반환한다. 따라서, 아래의 함수 사용 시
   파일의 크기를 알아낼 수 있다
	pos = lseek(fd,0,SEEK_END)
	pos는 읽기/쓰기 포인터의 위치를 의미하고, 위의 값에서는 파일의 끝을	     의미하므로 파일의 크기를 의미한다.
*/
