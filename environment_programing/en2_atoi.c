#include <stdio.h>
#include <stdlib.h> // atoi()

int max(int num1, int num2);

int main(int argc, char *argv[]){
	// 인수를 잘못 주고 실행시켰을 때
	if(argc !=3){
		printf("Usage: a.out number1 number2\n");
		exit(1);	
	}
	// atoi()는 정수 형태의 문자열을 정수로 변환
	printf("max number: %d\n", max( atoi(argv[1]), atoi(argv[2]) ));
	exit(0);
}

int max(int num1, int num2){
	if(num1 > num2)
		return num1;
	else
		return num2;
}

/* 출력
	> ./en2_atoi
	Usage: a.out number1 number2
	> ./en2_atoi 3 4
	max number: 4
*/
