#include "main.h"
#pragma warning (disable : 4996)
int num;

int main(void)
{
    mainPage();
    gotoxy(59, 32);
    printf("메뉴를 선택해주세요: "); //추후 영어로 변경
    scanf_s("%d", &num);

    switch (num) {
    case 1: ShotingGame(); break;
    case 2: DisplayHighScores(); break;
    case 3: break;
    }
    return 0;
}