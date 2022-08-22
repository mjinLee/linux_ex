#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // getopt() //+

// cat 유사 프로그램 만들기
// -n 옵션(라인 넘버 출력) 추가 => '//+' 표시
void output_file(FILE *fp);
int flag = 0; //+

int main(int argc, char *argv[])
{
    FILE *fp;
    int opt; //+

    if (argc == 1)
    {
        // 인수를 잘못 주어 실행하면
        // printf("Usage: a.out filename...\n");
        // 명령라인에서 입력을 잘못하면 //+
        printf("Usage: a.out [-n] filename...\n"); //+
        exit(1);
    }

    // 명령라인의 n 옵션 처리 //+(22~37 lines)
    while ((opt = getopt(argc, argv, "n")) != -1)
    {
        switch (opt)
        {
        // n 옵션이면 flag에 1을 저장
        case 'n':
            flag = 1;
            break;
        // 인식되지 않는 옵션이면 오류 메시지 출력
        default:
            printf("unknown option: %c\n", optopt);
        }
    }
    // 명령라인 인수가 2가 아니라는 것은 -n 옵션이 있다는 의미이므로
    // 파일이름을 얻기 위해 argv를 1 증가
    if (argc != 2)
        argv++;

    // 여러 개의 파일을 처리할 수 있도록 반복
    while (*++argv)
    {
        printf("\n[filename: %s]\n\n", *argv);
        // 명령라인 인수에 해당되는 파일을 엶
        if ((fp = fopen(*argv, "r")) == NULL)
        {
            perror("fopen failed");
            exit(2);
        }
        output_file(fp);
        fclose(fp);
    }
    exit(0);
}

void output_file(FILE *fp)
{
    /*
    int ch;
    int line=0; //+

    // flag가 1이면 라인 번호 1 출력 //+
    if(flag) //+
        printf("%-4d",++line); //+

    // 파일 내용을 화면으로 출력 //+
    // 한 글자씩 읽어서 화면으로 출력
    while((ch=getc(fp)) != EOF) {	// EOF : 프로그램의 끝인지 아닌지
        putc(ch, stdout);

        // flag가 1이고 ch가 '\n'이면 라인 번호 출력 //+
        if(flag && ch == '\n') //+
            printf("%-4d",++line); //+
    // '%-4d' : 정수를 4자리수로 출력하되, 정수를 왼쪽에 붙여서 출력
    }
    */

    // 마지막 라인의 라인넘버 출력 방지하도록 프로그램 수정
    int ch, line = 1;

    if (flag)
        printf("1  ");
    while ((ch = getc(fp)) != EOF)
    {
        if (flag && ch == '\n')
        {
            // 다음 문자가 EOF면 출력하지 않고 빠져 나옴
            if ((ch = getc(fp)) == EOF)
                break;
            // ch를 fp 파일로 되돌림
            ungetc(ch, fp);
            // ungetc() 안 하면, 다음 문장부터 한 자씩 빠지고 출력
            printf("\n%-4d", ++line);
        }
        else
            putc(ch, stdout);
    }
    printf("\n");
}
/* 프로그램 실행 시,
	> ./en6_cat_output_line -n en6_cat_output.c
*/