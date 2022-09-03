// 전달 받은 환경 변수 출력
#include <stdio.h>
#include <stdlib.h>

// environ에 환경 변수 정보 저장
extern char **environ;

int main(int argc, char *argv[]){
	char **env = environ;

	printf("my environment variables are :\n");

	while(*env)
		printf("%s\n",*(env++));

	exit(0);
}
