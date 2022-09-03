// exec 함수들을 이용해 ls 명령어 실행
/* exec : 프로세스 대체
    하나의 프로세스 실행 시, 다른 프로세스를 생성 후 자신은 종료
    프로세스 A가 실행 중 exec 함수를 호출해 프로세스 B로 대체 가능 */
/* - execl* 함수들은 NULL ((char *)0)로 끝나는 리스트가 인수가 됨. 이는 더 이상 인수가 없다는 것을 의미
   - execv* 함수들은 문자열 배열이 두 번째 인수임
   - 함수 끝 이름이 p인 경우, 경로가 아닌 프로그램(파일) 이름. 이때 프로그램 이름은 PATH 환경 변수에 의해 지정된 디렉토리에서 찾음
   - 함수 끝 이름이 e인 경우, envp 인수 추가. 이를 통해 환경 정보를 임의로 설정 가능. 다른 함수들은 호출하는 프로세스의 환경 정보가 전달 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // execl(),execlp(),execle(),execv(),execvp(),execve()

// 환경 변수 설정
char *envp[] = {"USER=Lee","PATH=/tmp",(char *)0}; // execle(),execve()

int main(){
	// 인수 리스트를 내용으로 하는 문자열 배열
	char *arg[] = {"ls",(char *)0}; // execv(),execvp(),execve()

	//printf("Running ls with execl\n");
	//printf("Running ls with execlp\n");
	//printf("Running ls with execle\n");
	//printf("Running ls with execv\n");
	//printf("Running ls with execvp\n");
	printf("Running ls with execve\n");

	/* 첫 번째 인수가 경로이름이고 명령라인 인수들을 나열. (char *)0은 인수가 더 이상 없음을 의미
	execl("/bin/ls","ls",(char *)0); */

	/* 첫 번째 인수가 파일이름이고 명령라인 인수들을 나열. 프로그램 ls는 PATH 환경 변수에 의해 지정된 디렉토리에서 찾음
	execlp("ls","ls",(char *)0); */

	/* 첫 번째인수가 경로이름이고 명령라인 인수들을 나열. 환경변수넘겨줌
	execle("/bin/ls","ls",(char *)0,envp); */
	
	/* 첫 번째인수가 경로이름이고 명령라인 인수는 인수들의 배열 
	execv("/bin/ls",arg); */

	/* 첫 번째인수가 파일이름이고 명령라인 인수는 인수들의 배열. 프로그램 ls는 PATH 환경변수에 의해 지정된 디렉토리에서 찾음
	execvp("ls",arg); */

	/* 첫 번째 인수가 경로이름이고 명령라인 인수는 인수들의 배열. 환경변수넘겨줌 */
	execve("/bin/ls",arg,envp);

	// 이후 문장은 실행되지 않음
	//printf("execl failed to run ls\n");
	//printf("execlp failed to run ls\n");
	//printf("execle failed to run ls\n");
	//printf("execv failed to run ls\n");
	//printf("execvp failed to run ls\n");
	printf("execve failed to run ls\n");

	exit(0);
}
