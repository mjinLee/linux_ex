#include <stdio.h>
#include <stdlib.h>

// cat 유사 프로그램 만들기
void output_file(FILE *fp);

int main(int argc, char *argv[]){
	FILE *fp;

	if(argc == 1){
		// 인수를 잘못 주어 실행하면
		printf("Usage: a.out filename...\n");
		exit(1);
	}
	
	// 여러 개의 파일을 처리할 수 있도록 반복
	while(*++argv){
		printf("\n[filename: %s]\n\n", *argv);
		// 명령라인 인수에 해당되는 파일을 엶
		if((fp = fopen(*argv,"r"))==NULL){
			perror("fopen failed");
			exit(2);
		}
		output_file(fp);
		fclose(fp);
	}
	exit(0);
}

void output_file(FILE *fp){
	int ch;
	
	// 한 글자씩 읽어서 화면으로 출력
	while((ch=getc(fp)) != EOF)	// EOF : 프로그램의 끝인지 아닌지
		putc(ch, stdout);
}
