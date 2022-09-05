// 메시지 큐(Message Queue)
// 메시지 큐에 메시지 전송
/* int msgget(key_t key, int msgflag); : 메시지 큐 생성
    - key값의 메시지 큐 생성 후 식별자 반환
    - key값의 메시지 큐 존재하면 기존 메시지 큐의 식별자 반환
    - IPC_PRIVATE : 유일한 메시지 큐 생성
    - msgflg 인수 값 및 의미)
     IPC_CREAT : key에 해당하는 메시지 큐가 없으면 큐를 새로 생성하는데 이 때 접근권한도 함께 부여해야 함. 그러나 메시지 큐가 있으면 이 옵션은 무시
     IPC_EXCL : 메시지 큐가 있으면 실패라는 의미로 -1을 반환. 이 값이 설정되지 않으면 기존 메시지 큐에 접근해 식별자를 반환 */
/* int msgsnd(int msqid, struct msgbuf *msgp, size_t msgsz, int msgflg); : 메시지 큐에 메시지 전송
    - msqid(메시지 큐 식별자), msgp(전송할 메시지), msgsz(메시지 크기), msgflg(동작 옵션)
    - msgflg 인수 값 및 의미)
     0으로 설정 가능(메시지 큐가 메시지를 저장할 수 있을 때까지 기다림
     IPC_NOWAIT : 메시지 큐가 가득 차 있어 메시지를 더 이상 저장할 수 없을 경우에 실패로 -1을 반환. 이 값을 설정하지 않으면 메시지 큐가 메시지를 저장할 수 있을 때까지 기다림 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h> // msgget(), msgsnd()
#include <sys/ipc.h> // msgget(), msgsnd()
#include <sys/msg.h> // msgget(), msgsnd()
#include <stdlib.h>
#define SIZE 124

// 메시지 저장하는 데이터형으로 첫 번째 멤버는 메시지 형식이어야 함
struct{
	long type; // 메시지 형식
	char data[SIZE]; // 메시지 데이터
} msg_data = {1,"Linux C Programming"};
int msqid;

int main(){
	// 1234 키를 갖는 메시지 큐를 생성하고 메시지 큐 식별자인 정수값을 반환. 만약 1234 키의 메시지 큐가 있으면 메시지 큐에 접근하여 식별자를 반환
	if(msqid = msgget((key_t)1234, IPC_CREAT | 0666)==-1){
		perror("msgget failed"); exit(1);
	}
	
	// msg_data 메시지를 msqid 메시지 큐에 전송
	if(msgsnd(msqid, &msg_data, strlen(msg_data.data),0)==-1){
		perror("msgsnd failed"); exit(1);
	}
}
