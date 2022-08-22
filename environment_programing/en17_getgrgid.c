// getgrgid() 이용해 그룹 정보 출력
#include <stdio.h>
#include <stdlib.h>
#include <grp.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	gid_t gid;
	struct group *pg;
	int i;

	// 그룹 ID를 얻음
	gid = getgid();
	// 그룹 정보를 얻음
	pg = getgrgid(gid);
	// pg->gr_name은 그룹 이름
	printf("group name: %s\n", pg->gr_name);
	
	exit(0);
}
