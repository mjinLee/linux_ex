// 파이프(pipe) 기반 통신
// 1) argv[1] 프로세스 결과를 파이프를 통해 수신 후 출력
// 2) 프로세스 결과를 파이프를 통해 argv[1] 프로세스에게 송신

#include <stdio.h> // popen(), pclose()
#include <stdlib.h>

int main(int argc, char *argv[]){
	//FILE *read_fp;
	FILE *write_fp;
	char buffer[256];

	/* argv[1] 프로세스를 실행하고 읽기용 파이프를 생성, read_fp는 파이프를 가리킴
	if((read_fp=popen(argv[1],"r"))==NULL){ */
	// argv[1] 프로세스를 실행하고 쓰기용 파이프를 생성
	if((write_fp=popen(argv[1],"w"))==NULL){
		perror("popen failed"); exit(1);
	}

	/* read_fp 파이프로부터 데이터를 입력받아 출력
	while(fgets(buffer,sizeof(buffer),read_fp)){
		fputs(buffer,stdout);
	} */

	sprintf(buffer,"Linux C Programming\n");
	//buffer에 저장된 데이터를 파이프에 씀. 파이프에 쓴 데이터는 argv[1] 명령어의 입력으로 전달
	fprintf(write_fp,buffer);

	// read_fp 파이프를 닫음
	//pclose(read_fp);
	
	//write_fp 파이프를 닫음
	pclose(write_fp);

	exit(0);
}
