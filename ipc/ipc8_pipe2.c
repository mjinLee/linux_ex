// 1) pipe() 이용해 하나의 프로세스가 데이터 쓰고/읽음
// pipe() : 파이프 생성
// 2) pipe() 이용해 두 프로세스가 데이터 쓰고/읽음
// 3) 2)에서, 부모, 자식 프로세스에서 사용하지 않는 파이프는 닫음

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 4

int main(){
	char *arg[3]={"abc","def","ghi"};
	char buffer[SIZE];
	int pipes[2], i;

	// 파이프 생성. pipes[0]은 파이프로부터 데이터를 읽어 들일 때 사용하는 파일 식별자가 되고, pipes[1]은 파이프에 데이터를 쓸 때 사용하는 파일 식별자가 됨
	if(pipe(pipes)==-1){
		perror("pipe failed"); exit(1);
	}
	/* for(i=0;i<3;i++){
		// 파이프로부터 데이터 읽기
		read(pipes[0],buffer,SIZE);
		printf("%s\n",buffer);
	} */
	
	// 자식 프로세스를 생성하고 부모 프로세스는
	if(fork()){
		// 3)파이프의 읽기 파일 식별자 닫기
		close(pipes[0]);
		
		for(i=0;i<3;i++){
			// 파이프에 arg[i]를 쓰기
			write(pipes[1],arg[i],SIZE);
			printf("parent process write to pipe: %s\n",arg[i]);
		}
	// 자식 프로세스는
	} else{
		for(i=0;i<3;i++){
			// 3)파이프의 쓰기 파일 식별자 닫기
			close(pipes[1]);
			
			// 파이프로부터 읽기
			read(pipes[0],buffer,SIZE);
			printf("child process read from pipe: %s\n",buffer);
		}
	}

	exit(0);
}

/* 1)
	abc
	def
	ghi
    2), 3)
	parent process write to pipe: abc
	parent process write to pipe: def
	parent process write to pipe: ghi
	child process read from pipe: abc
	child process read from pipe: def
	child process read from pipe: ghi
*/