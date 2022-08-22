// getpwuid() 이용해 사용자 정보 출력
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	uid_t uid;
	struct passwd *pw;

	// 실제 사용자 ID를 얻어 옴
	uid = getuid();
	// uid에 대한 사용자 정보를 얻어 옴
	pw = getpwuid(uid);
	/* pw->pw_name은 사용자 계정
	   pw->pw_uid는 사용자 ID
	   pw->pw_gid는 사용자가 속한 그룹 ID
	   pw->pw_dir은 사용자의 홈 디렉토리를 의미 */
	printf("name: %s, uid: %d, gid: %d, home: %s\n", pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir);
	
	exit(0);
}
