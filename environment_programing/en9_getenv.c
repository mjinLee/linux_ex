// getenv() 사용해 환경 변수 값 출력
// 환경 변수 HOME, PWD, LINUX 값 출력
#include <stdio.h>
#include <stdlib.h> // getenv() 정의

int main(){
	char *home_dir, *work_dir, *tmp;

	// getenv를 이용해 HOME에 대한 환경 변수 값 얻어 옴
	if((home_dir = getenv("HOME")) != NULL)
		printf("home directory : %s\n", home_dir);

	// getenv를 이용해 PWD에 대한 환경 변수 값 얻어 옴
	if((work_dir = getenv("PWD")) != NULL)
		printf("working directory : %s\n", work_dir);
	
	// LINUX라는 환경 변수가 없으므로 NULL을 반환
	if((tmp = getenv("LINUX")) != NULL)
		printf("temp : %s\n", tmp);
}
