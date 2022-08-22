#include <stdio.h>
#include <stdlib.h>

// envp 인수를 사용해 현재 설정된 환경 변수 출력
// envp에 환경 변수 정보 저장
int main(int argc, char *argv[], char *envp[]){
	while(*envp)
		printf("%s\n", *envp++);
}
