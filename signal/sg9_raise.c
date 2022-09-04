// raise() 이용해 자기 자신에게 SIGINT 시그널 전송
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
	int count =0;

	while(1){
		printf("Halo Worl\n");
		count++;
		if(count == 3){
			raise(SIGINT);
		}
		sleep(2); // 2초 동안 정지
	}
}

