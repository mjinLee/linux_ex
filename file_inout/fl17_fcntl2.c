// F_SETFL 이용해 파일 끝에 학생 데이터 추가
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	int fd, flag;
	struct{
		char name[15];
		char phone[15];
	} student;

	if((fd=open(argv[1],O_RDWR|O_CREAT,0644))==-1){
		perror("open failed"); exit(1);
	}
	// 파일 상태 정보를 알아내 flag에 저장
	if((flag=fcntl(fd,F_GETFL))==-1){
		perror("fcntl failed"); exit(1);
	}
	// 상태정보가 저장되어 있는 flag에 O_APPEND 추가
	flag |= O_APPEND;
	// fd 파일의 상태정보를 flag로 설정
	if((fcntl(fd,F_SETFL,flag))==-1){
		perror("fcntl failed"); exit(1);
	}
	
	while(1){
		printf("input name => ");
		scanf("%s", student.name);
		// strcmp: 문자열 비교
		if(!strcmp(student.name,"quit"))
			break;
		int name_len, phone_len;
		name_len = strlen(student.name);
		printf("input phone number => ");
		scanf("%s", student.phone);
		phone_len = strlen(student.phone);
		write(fd, (char *)student.name,name_len);
		write(fd, (char *)student.phone,phone_len);
		write(fd, (char *)"\n",1);
	}
	close(fd);
	exit(0);
}

/*	> ./a.out student
	input name => test
	input phone number => 123-456
	input name => abc
	input phone number => 78-12
	input name => quit
	> cat student
	test123-456
	abc78-12
*/
