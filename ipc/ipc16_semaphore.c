// 세마포어(Semaphore) : 한정된 수의 자원을 이용할 때, 한정된 수의 프로세스만 이용할 수 있게 하는 방법
// 세 개의 자식 프로세스가 하나의 자원을 사용

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

void repeat(int semid);
void p(int semid);
void v(int semid);

int main(){
	int semid, i;
	union semun {
		int val; // SETVAL에서 사용
		struct semid_ds *buf; // IPC_STAT와 IPC_SET에서 사용
		unsigned short int *array; // GETALL과 SETALL에서 사용
	} arg;

	// 세마포어가 1개인 1234 키의 세마포어 집합 생성
	if(semid = semget((key_t)1234, 1, IPC_CREAT|0666)==-1){
		perror("semget failed"); exit(1);
	}

	// 세마포어 값을 1로 설정
	arg.val = 1;
	if(semctl(semid,0,SETVAL,arg)==-1){
		perror("semctl failed"); exit(1);
	}

	// 3개의 자식 프로세스 생성
	for(i=0;i<3;i++){
		if(!fork())
			repeat(semid);
	}
	
	// 10초간 정지
	sleep(10);
	// semid 세마포어 삭제
	if(semctl(semid,0,IPC_RMID,arg)==-1){
		perror("semctl failed"); exit(1);
	}
	exit(0);
}

void repeat(int semid){
	// 난수 초기화하기
	srand((unsigned int)getpid());
	p(semid);
	// getpid()는 현재 프로세스의 프로세스 ID 반환
	printf("%d process is using tool\n",getpid());
	// 난수를 5로 나눈 나머지 초 동안 정지
	sleep(rand()%5);
	printf("%d process is returning tool\n",getpid());
	v(semid);

	exit(0);
}

void p(int semid){
	struct sembuf pbuf;
	pbuf.sem_num =0;
	pbuf.sem_op=-1;
	// 프로세스 종료하면 세마포어 설정 원상 복귀
	pbuf.sem_flg=SEM_UNDO;
	// 현재 세마포어 값인 semval 1 감소하기
	if(semop(semid,&pbuf,1)==-1){
		perror("semop failed"); exit(1);
	}
}

void v(int semid){
	struct sembuf vbuf;
	vbuf.sem_num =0;
	vbuf.sem_op=1;
	vbuf.sem_flg=SEM_UNDO;
	// 현재 세마포어 값인 semval 1 증가하기
	if(semop(semid,&vbuf,1)==-1){
		perror("semop failed"); exit(1);
	}
}

/*
   1045 process is using tool
   1045 process is returning tool
   1046 process is using tool
   1046 process is returning tool
   1047 process is using tool
   1047 process is returning tool
*/
