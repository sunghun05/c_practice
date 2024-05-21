#define _CRT_SECURE_NO_WARNINGS
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
        scanf("%d", &a);
        if (a>100) {
            printf("학생 수가 너무 많습니다. (학생 수 <= 100)");
            continue;
        }
        STUDENTS students[a];
        break;
    }while(1);
    printf("%d", a);
    return 0;
}
int main()
{
    create_st();
}

