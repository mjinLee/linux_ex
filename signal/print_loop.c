// 프로그램 무한 반복, 백그라운드로 실행
#include <stdio.h>
#include <unistd.h>

int main(){
	// 무한 반복
	while(1){
		printf("running\n");
		sleep(5);
	}
}
