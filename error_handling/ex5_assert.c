#include <stdio.h>
#include <stdlib.h>
// #define NDEBUG  // assert() 호출 방지
#include <assert.h> // assert() 정의하는 헤더 파일

int main(){
	// yesdata는 있고, nodata는 없다고 가정
	FILE *fp;

	fp = fopen("yesdata","r");
	// fp가 참이므로 아무 일 하지 않고 다음 문장 실행
	assert(fp);
	printf("yesdata exit\n");
	fclose(fp); // fp 닫음
	
	fp = fopen("nodata","r");
	// nodata 없으므로 NULL 반환
	assert(fp);
	// fp가 거짓이므로 오류 메시지 출력, 코어 덤프하고 종료
	// 이후 문장 실행되지 않음
	printf("nodata exit\n");
	fclose(fp);
	exit(0);
}

/* 실행 시, nodata가 없어 코어 덤프 후 프로그램 종료
   yesdata exist
   main: Assertion 'fp' failed.
   중지됨 (core dumped) */

/* assert 함수를 사용해 테스트 및 디버깅
   프로그램 개발 완료 시, assert 함수 삭제해야 컴파일과 실행 시간 감소
	#define NDEBUG 
	#include <assert.h>
   // assert 함수 호출 방지

   프로그램 종료 되나, 코어라는 파일은 존재하지 않음 */
