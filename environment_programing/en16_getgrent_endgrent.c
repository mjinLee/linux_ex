// getgrent() 와 endgrent() 사용해 그룹에 속한 사용자 계정 출력
#include <stdio.h>
#include <stdlib.h>
#include <grp.h>
#include <sys/types.h>

int main(){
	struct group *pg;
	int i;

	// 그룹 파일로부터 그룹 정보를 차례로 읽어 출력
	while(pg=getgrent()){
		printf("group name: %s\n member: ", pg->gr_name);
		// 그룹에 속한 사용자 계정 전부 출력
		for(i=0; pg->gr_mem[i]!=NULL; i++)
			printf("%s", pg->gr_mem[i]);
		printf("\n\n");
	}
	// 사용이 끝난 그룹 파일을 닫음
	endgrent();
	exit(0);
}
