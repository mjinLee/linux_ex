// 하나의 프로그램에서 동시에 열 수 있는 파일의 수에 제한이 있음(기본값 1024)
//	>ulimit -n
//	1024	// 한 번에 열 수 있는 최대 파일 수
// 하나의 프로그램에서 동시에 열 수 있는 파일의 수 출력
#include <stdio.h>
#include <fcntl.h>

int main(void){
	int i=0;

	while(open("a",O_WRONLY | O_CREAT,0644)!=-1)
		i++;
	printf("%d \n",i);
}
