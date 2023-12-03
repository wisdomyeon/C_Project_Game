#include "game.h"s

PlayerInfo playerList[] = { {2,"지수"},{50,"철수"} ,{ 45,"영희"} ,{22,"맹구"} ,{ 55,"유리"} ,{ 1,"흰둥이"} ,{10,"짱아"} ,{60, "미선"} };
int arrLength = sizeof(playerList) / sizeof(playerList[0]); //추후 arrSize로 변경
int res;

void mainPage() {
    enum ColorType {
        BLACK,     //0
        darkBLUE,   //1
        darkSkyBlue,    //3
        DarkRed,     //4
        DarkPurple,   //5
        DarkYellow,   //6
        GRAY,      //7
        DarkGray,   //8
        BLUE,      //9
        GREEN,      //10
        SkyBlue,   //11
        RED,      //12
        PURPLE,      //13
        YELLOW,      //14
        WHITE      //15
    } COLOR;

    srand(time(NULL));
    system("mode con: cols=160 lines=700");
    CursorView(0);
    system("title SHOOTING GAME by nameaek");
    system("cls");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    printS(19, 6);
    textcolor(9);
    printH(32, 6);
    textcolor(6);
    printO(45, 6);
    textcolor(10);
    printO(58, 6);
    textcolor(11);
    printT(71, 6);
    textcolor(13);
    printI(85, 6);
    textcolor(14);
    printN(98, 6);
    textcolor(2);
    printG(112, 6);
    textcolor(2);      //SHOOTING
    printG(39, 16);    //GAME
    textcolor(15);
    printA(54, 16);
    textcolor(12);
    printM(70, 16);
    textcolor(6);
    printE(88, 16);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

    gotoxy(59, 28);
    printf("1>> GAME START\n");
    gotoxy(59, 29);
    printf("2>> RANK\n");
    gotoxy(59, 30);
    printf("3>> EXIT\n");
}

void printS(int x, int y)
{
    gotoxy(x, y);     printf(" ▣▣▣▣");
    gotoxy(x, y + 1); printf("▣      ");
    gotoxy(x, y + 2); printf("▣      ");
    gotoxy(x, y + 3); printf(" ▣▣▣▣");
    gotoxy(x, y + 4); printf("        ▣");
    gotoxy(x, y + 5); printf("        ▣");
    gotoxy(x, y + 6); printf(" ▣▣▣▣");
}

void printH(int x, int y)
{
    gotoxy(x, y);     printf("▣      ▣");
    gotoxy(x, y + 1); printf("▣      ▣");
    gotoxy(x, y + 2); printf("▣      ▣");
    gotoxy(x, y + 3); printf("▣▣▣▣▣");
    gotoxy(x, y + 4); printf("▣      ▣");
    gotoxy(x, y + 5); printf("▣      ▣");
    gotoxy(x, y + 6); printf("▣      ▣");
}

void printO(int x, int y)
{
    gotoxy(x, y);     printf(" ▣▣▣▣  ");
    gotoxy(x, y + 1); printf("▣      ▣");
    gotoxy(x, y + 2); printf("▣      ▣"); 
    gotoxy(x, y + 3); printf("▣      ▣");
    gotoxy(x, y + 4); printf("▣      ▣");
    gotoxy(x, y + 5); printf("▣      ▣");
    gotoxy(x, y + 6); printf(" ▣▣▣▣ ");
}

void printT(int x, int y)
{
    gotoxy(x, y);      printf("▣▣▣▣▣▣");
    gotoxy(x, y + 1);  printf("    ▣▣    ");
    gotoxy(x, y + 2);  printf("    ▣▣   ");
    gotoxy(x, y + 3);  printf("    ▣▣   ");
    gotoxy(x, y + 4);  printf("    ▣▣   ");
    gotoxy(x, y + 5);  printf("    ▣▣   ");
    gotoxy(x, y + 6);  printf("    ▣▣   ");
}

void printI(int x, int y)
{
    gotoxy(x, y);     printf("▣▣▣▣▣");
    gotoxy(x, y + 1);   printf("    ▣  ");
    gotoxy(x, y + 2);   printf("    ▣  ");
    gotoxy(x, y + 3);   printf("    ▣  ");
    gotoxy(x, y + 4);   printf("    ▣  ");
    gotoxy(x, y + 5);   printf("    ▣  ");
    gotoxy(x, y + 6); printf("▣▣▣▣▣");
}

    void printN(int x, int y)
    {
        gotoxy(x, y);     printf("▣      ▣");
        gotoxy(x, y + 1); printf("▣▣    ▣");
        gotoxy(x, y + 2); printf("▣ ▣   ▣");
        gotoxy(x, y + 3); printf("▣  ▣  ▣");
        gotoxy(x, y + 4); printf("▣   ▣ ▣");
        gotoxy(x, y + 5); printf("▣    ▣▣");
        gotoxy(x, y + 6); printf("▣      ▣");
    }

    void printG(int x, int y)
    {
        gotoxy(x, y);     printf(" ▣▣▣▣  ");
        gotoxy(x, y + 1); printf("▣      ");
        gotoxy(x, y + 2); printf("▣      ");
        gotoxy(x, y + 3); printf("▣   ▣▣▣");
        gotoxy(x, y + 4); printf("▣      ▣");
        gotoxy(x, y + 5); printf("▣      ▣");
        gotoxy(x, y + 6); printf(" ▣▣▣▣");
    }

    void printA(int x, int y)
    {
        gotoxy(x, y);      printf("     ▣    ");
        gotoxy(x, y + 1); printf("   ▣▣▣   ");
        gotoxy(x, y + 2); printf("  ▣    ▣  ");
        gotoxy(x, y + 3); printf(" ▣▣▣▣▣ ");
        gotoxy(x, y + 4); printf(" ▣      ▣");
        gotoxy(x, y + 5); printf(" ▣      ▣");
        gotoxy(x, y + 6); printf(" ▣      ▣");
    }

    void printM(int x, int y)
    {
        gotoxy(x, y);     printf("▣         ▣");
        gotoxy(x, y + 1); printf("▣▣     ▣▣");
        gotoxy(x, y + 2); printf("▣ ▣   ▣ ▣");
        gotoxy(x, y + 3); printf("▣  ▣ ▣  ▣");
        gotoxy(x, y + 4); printf("▣   ▣    ▣");
        gotoxy(x, y + 5); printf("▣         ▣");
        gotoxy(x, y + 6); printf("▣         ▣");
    }

void printE(int x, int y)
{
    gotoxy(x, y);     printf("▣▣▣▣▣");
    gotoxy(x, y + 1); printf("▣       ");
    gotoxy(x, y + 2); printf("▣");
    gotoxy(x, y + 3); printf("▣▣▣▣▣");
    gotoxy(x, y + 4); printf("▣       ");
    gotoxy(x, y + 5); printf("▣       ");
    gotoxy(x, y + 6); printf("▣▣▣▣▣");
}


void ShotingGame(){
    system("cls");
    //사용자 정보 받기
    printf("ENTER YOUR NAME: ");
    scanf_s("%s", currentPlayer, sizeof(currentPlayer));
    //fgets(playerInfo->name, sizeof(playerInfo->name), stdin);

    for (int i = 0; i < arrLength; i++) {
        res = strcmp(currentPlayer, playerList[i].name) == 0 ? 1 : 0;
    }
    if (res == 0) {
        //player[arrLength + 1].name[strcspn(player[arrLength+1].name, "\n")] = '\0';
        
        strcpy_s(playerList[arrLength].name, 20, currentPlayer);
        printf("%s", playerList[arrLength].name);
        printf("%d", arrLength);
    }

    for (int i = 0; i <= arrLength; i++) { //추후 보아야함
        printf("%s\n", playerList[i].name);
    }
  
    //게임시작
    while (1) {
        switch (currentRound) {
        case 1: RoundOne(); break;
        case 2: RoundTwo(); break;
        case 3: RoundThree(); break;
        }
        esc();
    }
}

void RoundOne() {
    system("cls");
    srand((unsigned)time(NULL));
    CursorView(0);

    while (1) {
        if (_kbhit() == 1) {
            ch = _getch();
            if (ch == 0xE0 || ch == 0X00)
            {
                _getch();
            }else
            { 
                switch (ch)
                {
                    case LEFT:
                    case RIGHT:
                         playerMove(ch); break;
                    case ESC:
                    esc();
                }
            }
        }
        Sleep(40);

        Score = 2;
        if (Score >= roundScoreThreshold) {
            currentRound++;
            roundScoreThreshold += 60;
            //EnemySpeed++;
            return 0;
        }
    }
}

void playerMove(unsigned char ch) {
    int moveFlag = 0;
    if (bx ==  -1) {
        bx = fx;
        by = 23;
        playerDraw(bx, by);
    }
    
    if (ch == LEFT) {
        if (fx > 6) {
            fx--;
            playerDraw(fx, 23);
            printf("%d %d", fx, 23);
            playerErase(fx+5, 23);
        }
    }
    if (ch == RIGHT) {
       if (fx < 72) {
            fx++;
            playerDraw(fx, 23);
            printf("%d %d", fx, 23);
            playerErase(fx-2, 23);
       }
    }
}

void playerDraw(int x, int y) {
    gotoxy(x, y);
    puts("<<A>>");

    gotoxy(0, 34);
    printf("점수 = %d  \n라운드 = %d", Score, currentRound);
}

void playerErase(int x, int y) {
    gotoxy(x, y);
    puts("  ");
}

void RoundTwo() {
    Score = 120;
    if (Score >= roundScoreThreshold) {
       currentRound++;
       roundScoreThreshold += 60;
       //EnemySpeed++;
       return 0;
    }
}

void RoundThree() {
    Score = 180;
    if (Score >= roundScoreThreshold) {
        currentRound++;
        esc();
    }
}

int compare(const void* a, const void* b)
{
    return ((PlayerInfo*)b)->score - ((PlayerInfo*)a)->score;
}


int esc() {
    system("cls");
    //gotoxy(30, 10);
    //printf("==========================GAMEOVER==========================\n\n");
    UpdateHighScores(Score, playerList);
    DisplayHighScores();  // ROUND / RANK / 이름 - 점수

    CursorView(0);
    getchar();
    return 0;
}

void UpdateHighScores(int newScore, PlayerInfo *player)
{
    for (int i = 0; i < MAXPLAYER; i++) {
        if (strcmp(currentPlayer, player[i].name) == 0) {
            player[i].score = newScore;
        }
    }
    qsort(player, arrLength+1, sizeof(player[0]), compare);

}//현재 플레이어의 순위 결정 함수

void DisplayHighScores()
{
    system("cls");
    printf("===== HIGH SCORES =====\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("<<Rank %d>>\n ROUND %d :: %s :: %d\n\n", 1+i, currentRound, playerList[i].name, playerList[i].score);
    }
}//끝날 때 ROUND / RANK / 이름 - 점수