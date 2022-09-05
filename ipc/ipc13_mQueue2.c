// 메시지 큐(Message Queue)
// 메시지 큐에 메시지 전송
/* ssize_t msgrcv(int msqid, sttuct msgbuf *msgp, size_t msgsz, long msgtyp, int msgflg); : 메시지 큐에 있는 메시지 수신
    - msgp는 msgsnd의 msgp와 동일한 메시지 형식
    - msgsz는 msgsnd의 msgsz와 동일
    - msqid(메시지 큐 식별자), msgp(메시지 수신할 곳), masgsz(수신 가능한 메시지 크기), msgtyp(수신할 메시지 선택 조건), msgflg(동작 옵션)
    - msgtyp 인수 값 및 의미)
     0 : 메시지 큐에서 첫 번째 메시지를 수신
     양수 : 이 값과 메시지의 메시지 형식(mtype)이 일치하는 메시지를 수신
     음수 : 이 값의 절대값과 같거나 작은 메시지 형식(mtype)을 갖는 메시지 중에서 가장 작은 메시지 형식을 갖는 메시지를 수신. (예-세 개의 메시지 형식이 각각 5, 1, 9. msgtyp가 -10이라면 -10의 절대값인 10보다 작거나 같은 메시지 형식을 갖는 메시지는 모두 해당. 이 중 가장 작은 1을 메시지 형식으로 갖고 있는 메시지를 수신함)
    - msgflg 인수 값 및 의미
     0으로 설정 가능
     IPC_NOWAIT : 메시지 큐에 메시지가 없으면 실패로 -1을 반환. 이 값을 설정하지 않으면 메시지가 메시지 큐에 도착할 때까지 기다림
     MSG_NOERROR : 메시지 크기가 msgsz보다 클 때 초과되는 부분을 자름. 이 값을 설정하지 않으면 실패로 -1을 반환 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h> // msgrcv()
#include <sys/ipc.h> // msgrcv()
#include <sys/msg.h> // msgrcv()
#include <signal.h>
#include <stdlib.h>
#define SIZE 124

struct{
	long type;
	char data[SIZE];
} msg_data;

int main(){
	int msqid;
	struct msqid_ds msg_stat;

	// 1234 키의 메시지 큐가 있으면 접근해서 식별자 받음
	if(msqid = msgget((key_t)1234, IPC_CREAT | 0666)==-1){
		perror("msgget failed"); exit(1);
	}

	// msqid 메시지 큐에서 메시지 읽어 msg_data에 저장
	if(msgrcv(msqid,&msg_data,SIZE,0,0)==-1){
		perror("msgrcv failed"); exit(1);
	}
	printf("dat read from message queue : %s\n",msg_data.data);

	exit(0);
}
