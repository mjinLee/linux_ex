#include <stdio.h>
#include <stdlib.h>

// abort()를 이용해 assert() 구현
void my_assert(int expression);

int main(){
	my_assert(7==7);
	printf("yes\n");

	my_assert(3 == 5);
	printf("no\n");
}

void my_assert(int expression){
	if(!(expression)){	// expression이 거짓이면
		// __FILE__은 소스 파일, __LINE__은 현재 라인
		printf("%s:%d:Assertion failed.\n",__FILE__,__LINE__);
		abort();
	}
}
