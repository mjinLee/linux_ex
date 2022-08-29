// atexit() 이용해 func1, func2, func3 함수 등록
#include <stdio.h>
#include <stdlib.h>

void func1(void);
void func2(void);
void func3(void);

int main(){
	// exit 함수 호출 때 실행될 함수를 func1,func2,func3 순으로 등록
	atexit(func1);
	atexit(func2);
	atexit(func3);

	exit(0);
}

void func1(void){
	printf("run function1\n");
}
void func2(void){
	printf("run function2\n");
}
void func3(void){
	printf("run function3\n");
}

/* 비정상 종료 - about, 시그널(signal)에 의한 종료
   정상 종료 - exit, return에 의한 종료
   abort - 현재 상태 코어 덤프 & 프로세스 비정상 종료
   비정상 종료 시에는 atexit에 의해 등록함. 함수가 실행되지 않음
*/
