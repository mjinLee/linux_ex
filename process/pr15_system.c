/* system 이용해 ls 명령어 실행
#include <stdio.h>
#include <stdlib.h> //system()

int main(){
	printf("Running ls with system\n");

	// system 이용해 ls 명령어 실행
	system("ls");

	printf("Done\n");

	exit(0);
} */

// system 이용해 명령라인에 입력한 명령어 실행
#include <stdio.h>
#include <stdlib.h> // system()
#include <string.h>

int main(int argc,char *argv[]){
	char str[256];
	int i=1;
	printf("Running %s with system\n",argv[1]);
	// 명령라인의 인수들을 연결해서 str에 저장
	while(argc > i){
		strcat(str,argv[i++]);
		strcat(str," ");
	}

	// system 이용해 str에 저장된 명령어 실행
	system(str);
	printf("Done\n");
	exit(0);
}
