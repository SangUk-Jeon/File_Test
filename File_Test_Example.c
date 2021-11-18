#define _CRT_SECURE_NO_WARNINGS // Visual Studio 경우
#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>

char Email[20];
char Password[25];
int Wallets;

int main() {
    printf("File_Test Project\n");
    printf("User_Wallet.txt, User_Email.txt, User_Password.txt 파일 생성 및 이메일, 비밀번호 저장\n\n");
    printf("이메일 : ");
    scanf("%s", Email);
    User_Info(1);
    printf("비밀번호 : ");
    scanf("%s", Password);
    User_Info(2);
    Wallet();
    system("cls");
    printf("* 3초 뒤에 자동으로 종료됩니다. *\n");
    printf("값 : ");
    Read();
    // My_Wallet();
    Sleep(3000);
    return 0;
}

int Wallet() {
    srand((unsigned int)time(NULL));
    FILE* fp = fopen("User_Wallet.txt", "w");   
    fprintf(fp, "%d-", rand() % 1000);
    fprintf(fp, "%d-", rand() % 1000);
    fprintf(fp, "%d", rand() % 1000);
    fclose(fp);
}

int Read() {
    FILE* fp = fopen("User_Wallet.txt", "r");
    char string[255];

    fscanf(fp, "%s", string);
    printf("%s", string);
}

//int My_Wallet() {
//    FILE* fp = fopen("My_Wallet.txt", "w");  
//    fprintf(fp, "0");
//    fclose(fp);
//}

int User_Info(int value) {
    if (value == 1) {
        FILE* fp = fopen("User_Email.txt", "w");  
        fprintf(fp, Email);
        fclose(fp);
    }
    else if (value == 2) {
        FILE* fp = fopen("User_Password.txt", "w");   
        fprintf(fp, Password);
        fclose(fp);
    }
}
