// putenv() 사용해 환경 변수 변경
#include <stdio.h>
#include <stdlib.h> // getenv(), putenv()

int main(){
	char *home_dir;

	// HOME 환경 변수 값을 얻어 와서 출력
	if((home_dir = getenv("HOME")) != NULL)
		printf("home directory : %s\n", home_dir);

	// HOME 환경 변수 값을 /home/ 로 설정
	putenv("HOME=/home/");

	if((home_dir = getenv("HOME")) != NULL)
		printf("home directory : %s\n", home_dir);
}
