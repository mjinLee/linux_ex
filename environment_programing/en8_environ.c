#include <stdio.h>
#include <stdlib.h> // environ 변수 선언

// envp 인수를 사용한 프로그램과 동일한 동작 수행(환경변수 출력)
// environ에 환경 변수 정보 저장
extern char **environ;

int main(){
	while(*environ)
		printf("%s\n",*environ++);
}
