#include <stdio.h>
#include <stdlib.h>
#include <math.h> // sqrt() 정의하는 헤더 파일
#include <errno.h> // errno 변수 선언하는 헤더 파일

int main(){
	double y;
	errno = 0; // initializing
	
	y = sqrt(-1);
	// sqrt()의 인수로 음수 값이 올 수 없으므로 호출 오류 발생

	// errno가 0이 아니라는 것은 오류가 발생했음을 의미
	if(errno != 0){
		printf("errno = %d\n", errno);
		exit(1);
	}
	exit(0);
	return 0;
}

// 프로그램 실행 시, errno=33 출력

/* math함수 gcc 오류
  => 컴파일 할 때 '-lm' 추가해 라이브러리 링크
    > gcc ex3_errno.c -o ex3_errno -lm
    > gdb ex3_errno
  또는
    > gcc -g ex3_errno.c -o ex3_errno -lm
    > ./ex3_errno */
