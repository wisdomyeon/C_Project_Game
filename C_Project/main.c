#include "main.h"
#pragma warning (disable : 4996)
int num;

int main(void)
{
    mainPage();
    gotoxy(59, 32);
    printf("�޴��� �������ּ���: "); //���� ����� ����
    scanf_s("%d", &num);

    switch (num) {
    case 1: ShotingGame(); break;
    case 2: DisplayHighScores(); break;
    case 3: break;
    }
    return 0;
}