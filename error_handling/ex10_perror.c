#include <stdio.h> // perror()
#include <stdlib.h>

int main(){
	FILE *fp;
	
	if((fp = fopen("nodata","r"))==NULL){
		perror("ERROR");
		exit(1);
	}
	exit(0);
}

// 프로그램 실행 시, 
//  Error: No such file or directory 출력
