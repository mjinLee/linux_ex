// 두 프로세스 간 통신을 위해 두 개의 파이프 생성해 통신

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define SIZE 256

int main(){
	int pipes1[2], pipes2[2], length;
	char read_buffer[SIZE],write_buffer[SIZE];

	// 두 개의 파이프 생성
	if(pipe(pipes1)==-1 || pipe(pipes2)==-1){
		perror("pipe failed");
		exit(1);
	}
	// 부모 프로세스는
	if(fork()){
		// pipes1의 쓰기 파일 식별자 닫기
		close(pipes1[1]);
		// pipes2의 읽기 파일 식별자 닫기
		close(pipes2[0]);

		// pipes1 파이프로부터 데이터 읽기
		if((length=read(pipes1[0],read_buffer,SIZE))==-1){
			perror("read failed"); exit(1);
		}
		write(STDOUT_FILENO,"receive message: ",strlen("receive message: "));
		write(STDOUT_FILENO, read_buffer,length);

		sprintf(write_buffer,"Hi client!\n");
		// pipes2 파이프에 데이터 쓰기
		write(pipes2[1],write_buffer,strlen(write_buffer));

		// 자식 프로세스가 종료되기를 기다림
		wait(NULL);
	// 자식 프로세스는
	} else{
		// pipes1의 읽기 파일 식별자 닫기
		close(pipes1[0]);
		// pipes2의 쓰기 파일 식별자 닫기
		close(pipes2[1]);

		sprintf(write_buffer,"Hi server!\n");
		// pipes1 파이프에 데이터 쓰기
		write(pipes1[1],write_buffer,strlen(write_buffer));

		// pipes2 파이프로부터 데이터 읽기
		if((length=read(pipes2[0],read_buffer,SIZE))==-1){
			perror("read failed"); exit(1);
		}

		write(STDOUT_FILENO,"receive message: ",strlen("receive message: "));
		write(STDOUT_FILENO,read_buffer,length);
	}
	exit(0);
}

/*
   - 두 개의 파이프를 생성한 상태에서 자식 프로세스 생성
   - 부모 프로세스는 pipes1[1]과 pipes2[0]을 제거(pipes1의 쓰기, pipes2의 읽기)
   - 자식 프로세스는 pipes1[0]과 pipes2[1]을 제거(pipes1의 읽기, pipes2의 쓰기)
   - 부모 프로세스가 pipes2[1]을 통해 파이프에 쓰면 자식 프로세스는 pipes2[0]을 통해 읽음
   - 자식 프로세스가 pipes1[1]을 통해 파이프에 쓰면 부모 프로세스는 pipes1[0]을 통해 읽음
*/
