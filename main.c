#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int st_cnt;

typedef struct {
    char name[50];
    int age;
    float score;
    char num[9];
}STUDENTS;

int create_st() {
    do {
        printf("학생 수 : ");
        if (!scanf("%d", &st_cnt)){
            printf("숫자를 입력하세요 .. \n");
            while(getchar() != '\n');
            continue;
        }
        if (st_cnt>100){
            printf("값이 너무 큽니다. 다시 입력하세요..\n");
            while(getchar() != '\n');
            continue;
        }
        if (st_cnt <= 0){
            printf("값이 너무 작습니다. 다시 입력하세요..\n");
            while(getchar() != '\n');
            continue;
        }
        break;
    }while(1);
    return st_cnt;
}
void show(STUDENTS* stu1) {
    for (int i = 0; i < st_cnt; i++) {
        printf("%d. name : %s   age : %d    score : %0.2lf  number : %s\n",i+1, stu1[i].name, stu1[i].age,stu1[i].score, stu1[i].num);
    }
}
void search_name(STUDENTS *stu1) {
    char local_name[50];
    int isIn = 0;
    printf("이름으로 검색, 이름을 입력하세요 : ");
    scanf("%s", &local_name);
    for(int i=0; i < st_cnt; i++) {
        if (strcmp(stu1[i].name, local_name) == 0) {
            printf("%d. name : %s   age : %d    score : %0.2lf  number : %s\n",i+1, stu1[i].name, stu1[i].age,stu1[i].score, stu1[i].num);
            isIn  = 1;
        }
    }
    if(isIn == 0){
        printf("정보를 찾을 수 없습니다.\n");
    }

}
void search_num(STUDENTS *stu1){
    char lnum[9];
    int isIn = 0;
    printf("학번으로 검색, 학번을 입력하세요 : ");
    scanf("%s", &lnum);
    for(int i=0; i < st_cnt; i++) {
        if (strcmp(stu1[i].num, lnum) == 0) {
            printf("%d. name : %s   age : %d    score : %0.2lf  number : %s\n",i+1, stu1[i].name, stu1[i].age,stu1[i].score, stu1[i].num);
            isIn  = 1;
        }
    }
    if(isIn == 0){
        printf("정보를 찾을 수 없습니다.");
    }
}
STUDENTS enter_name(STUDENTS *stu1) {
    for (int i=0; i < st_cnt; i++){
        printf("enter %dth student name : ", i+1);
        scanf("%s", &stu1[i].name);
        while(getchar() != '\n');
    }
    return *stu1;
}

void enter_age(STUDENTS* stu1){
    for (int i=0; i < st_cnt; i++){
        printf("enter %dth student age : ", i+1);
        scanf("%d", &stu1[i].age);
        while(getchar() != '\n');
    }

}
void enter_score(STUDENTS* stu1) {
    for (int i=0; i < st_cnt; i++){
        printf("enter %dth student score : ", i+1);
        do{
            if (!scanf("%f", &stu1[i].score)){
                printf("실수를 입력하세요.. \n");
                continue;
            }
            if (stu1[i].score<0 || stu1[i].score>5){
                printf("올바른 수를 입력하세요..\n");
                continue;
            }
            break;
        }while(1);
    }

}
void enter_num(STUDENTS* stu1) {                                //학번 입력 --
    int num;
    for (int i=0; i < st_cnt; i++){
        do {
            printf("enter %dth student number : ", i + 1);
            scanf("%d", &num);
            sprintf(stu1[i].num, "%d", num);
            if (strlen(stu1[i].num) != 8) {
                printf("학번이 올바르지 않습니다.\n");
                continue;
            }
            break;
//            printf("%s", stu1[i].num);
        }while(1);
    }

}
int search_menu(STUDENTS* stu1) {
    int mode;

    do{
        mode = 0;
        printf("검색 메뉴를 선택하세요\n");
        printf("0 :     이름으로 검색\n"
               "1 :     학번으로 검색\n"
               "2 :     모두 보이기\n"
               "-1 :    메뉴로 나가기\n");
        if (!scanf("%d", &mode)) {
            printf("올바른 메뉴를 입력하세요.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (mode){
            case 0 : while(getchar() != '\n');
                search_name(stu1);
                continue;
            case 1 : while(getchar() != '\n');
                search_num(stu1);
                continue;
            case 2 : while(getchar() != '\n');
                show(stu1);
                continue;
            case -1 : while(getchar() != '\n');
                return 0;
        }

    }while (1);
}
int menu(STUDENTS* stu1) {
    int mode;

    do{
        mode = 4;
        printf("\n            메뉴를 선택하세요\n\n          ");
        printf(" 0                              나이 입력\n"
               " 1                              점수 입력\n"
               " 2                              학번 입력\n"
               " 3                              검색\n"
               "-1                              종료\n");
        if (!scanf("%d", &mode)) {
            printf("올바른 메뉴를 입력하세요.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (mode){
            case 0 : while(getchar() != '\n');enter_age(stu1);
                continue;
            case 1 : while(getchar() != '\n');enter_score(stu1);
                continue;
            case 2 : while(getchar() != '\n');enter_num(stu1);
                continue;
            case 3 :  while(getchar() != '\n');search_menu(stu1);
                continue;
            case -1 : while(getchar() != '\n');
                return 0;
        }
        printf("올바른 메뉴를 입력하세요.\n");
    }while (1);
}
int main()
{
    st_cnt = create_st();
    STUDENTS* stu = (STUDENTS*)malloc(sizeof(STUDENTS) * st_cnt);
    *stu = enter_name(stu);
    menu(stu);
}