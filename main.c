//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//최대 100명 학생 저장     이름, 나이, 학번 및 학점
//학생 이름 최대 50글자까지
//프로그램의 기능 : 학생 정보 추가,, 모든 학생 정보 출력,, 아이디로 학생 찾기,, 종료 등

int a;
typedef struct {
    char name[50];
    int age;
    int score;
    char num[8];
}STUDENTS;
int create_st() {
    do {
        printf("학생 수 : ");
        if (!scanf("%d", &a)){
            printf("숫자를 입력하세요 .. \n");
            while(getchar() != '\n');
            continue;
        }
        if (a>100){
            printf("값이 너무 큽니다. 다시 입력하세요..\n");
            while(getchar() != '\n');
            continue;
        }
        if (a <= 0){
            printf("값이 너무 작습니다. 다시 입력하세요..\n");
            while(getchar() != '\n');
            continue;
        }
        break;
    }while(1);
    STUDENTS students[a];
    return 0;
}
int enter_name() {
    for (int i; i <= a; i++){
        do {
            printf("%d",i, "번 학생의 이름");
            if (!scanf("%s", &students[i].name)){
                printf("문자를 입력하세요 .. \n");
                while(getchar() != '\n');
                continue;
            }
            if (a>50){
                printf("값이 너무 큽니다. 다시 입력하세요..\n");
                while(getchar() != '\n');
                continue;
            }
            if (a <= 0){
                printf("값이 너무 작습니다. 다시 입력하세요..\n");
                while(getchar() != '\n');
                continue;
            }
            break;
        }while(1);
    }
    return 0;
}
int main()
{
    create_st();
    enter_name();
}

