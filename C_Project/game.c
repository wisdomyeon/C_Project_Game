﻿#include "game.h"

PlayerInfo playerList[] = { {2,"지수"},{50,"철수"} ,{ 45,"영희"} ,{22,"맹구"} ,{ 55,"유리"} ,{ 1,"흰둥이"} ,{10,"짱아"} ,{60, "미선"} };
int arrLength = sizeof(playerList) / sizeof(playerList[0]); //추후 arrSize로 변경
int res;

DefaultBall defaultBall;
Enemy enemy[MAXENEMY];
EnemyBall enemyBall[MAXENEMYBALL];
Item item;
ItemBall itemBall;

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


void ShotingGame() {
    system("cls");
    //사용자 정보 받기
    printf("ENTER YOUR NAME: ");
    scanf_s("%s", currentPlayer, sizeof(currentPlayer));

    for (int i = 0; i < arrLength; i++) {
        res = strcmp(currentPlayer, playerList[i].name) == 0 ? 1 : 0;
    }
    if (res == 0) {
        strcpy_s(playerList[arrLength].name, 20, currentPlayer);
    }

    //게임시작
    while (1) {
        switch (currentRound) {
        case 1: RoundOne(); break;
        case 2: RoundTwo(); break;
        case 3: RoundThree(); break;
        case 4: esc(); return 0;
        }
    }
}

///////////////////라운드1_ROUND1/////////////////////////
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
            }
            else
            {
                switch (ch)
                {
                case LEFT:
                    if (fx > 6) {
                        fx--;
                    }
                    break;
                case RIGHT:
                    if (fx < 72)
                        fx++;
                    break;
                case SPACE:
                    defaultBall.x = fx + 2 ;
                    defaultBall.y = fy ;
                    defaultBall.exist = TRUE;
                    break;
                case ESC:
                    currentRound = 4;
                    return 0;
                }
            }
            if (!itemBall.isShooting) {
                if (ch == SPACE && itemBall.exist) {
                    itemBall.isShooting = TRUE;
                    itemBall.x = fx+1;
                    itemBall.y = fy-1;
                    shootingCount--;
                }
            }
        }
        drawPlayer(fx, fy, ch);
        moveAndPrintAllies();
        showEnemy();
        moveEnemy();
        showEnemyBall(); 
        showItem();
        Sleep(40);
        Score = 60;
        if (!shootingCount <= 0) {
            showItemBall();
        }

        if (currentRound == 4) {
            return 0;
        }

        if (Score >= roundScoreThreshold) {
            currentRound++;
            roundScoreThreshold += 60;
            enemySpeed+=0.01;
            shootingCount = 6;
            break;
        }
    }
}
///////////////////라운드2_ROUND2/////////////////////////
void RoundTwo() {
    system("cls");
    srand((unsigned)time(NULL));
    CursorView(0);

    while (1) {
        if (_kbhit() == 1) {
            ch = _getch();
            if (ch == 0xE0 || ch == 0X00)
            {
                _getch();
            }
            else
            {
                switch (ch)
                {
                case LEFT:
                    if (fx > 6) {
                        fx--;
                    }
                    break;
                case RIGHT:
                    if (fx < 72)
                        fx++;
                    break;
                case SPACE:
                    defaultBall.x = fx + 2;
                    defaultBall.y = fy;
                    defaultBall.exist = TRUE;
                    break;
                case ESC:
                    currentRound = 4;
                    return 0;
                }
            }
            if (!itemBall.isShooting) {
                if (ch == SPACE && itemBall.exist) {
                    itemBall.isShooting = TRUE;
                    itemBall.x = fx + 1;
                    itemBall.y = fy - 1;
                    shootingCount--;
                }
            }
        }
        drawPlayer(fx, fy, ch);
        moveAndPrintAllies();
        showEnemy();
        moveEnemy();
        showEnemyBall(); 
        showItem();
        Sleep(40);
        if (!shootingCount <= 0) {
            showItemBall();
        }
        if (currentRound == 4) {
            return 0;
        }
        if (Score >= roundScoreThreshold) {
            currentRound++;
            roundScoreThreshold += 60;
            enemySpeed+=0.01;
            shootingCount = 6;
            break;
        }
    }
}
///////////////////라운드3_ROUND3/////////////////////////
void RoundThree() {
    system("cls");
    srand((unsigned)time(NULL));
    CursorView(0);

    while (1) {
        if (_kbhit() == 1) {
            ch = _getch();
            if (ch == 0xE0 || ch == 0X00)
            {
                _getch();
            }
            else
            {
                switch (ch)
                {
                case LEFT:
                    if (fx > 6) {
                        fx--;
                    }
                    break;
                case RIGHT:
                    if (fx < 72)
                        fx++;
                    break;
                case SPACE:
                    defaultBall.x = fx + 2;
                    defaultBall.y = fy;
                    defaultBall.exist = TRUE;
                    break;
                case ESC:
                    currentRound = 4;
                    return 0;
                }
            }
            if (!itemBall.isShooting) {
                if (ch == SPACE && itemBall.exist) {
                    itemBall.isShooting = TRUE;
                    itemBall.x = fx + 1;
                    itemBall.y = fy - 1;
                    shootingCount--;
                }
            }
        }
        drawPlayer(fx, fy, ch);
        moveAndPrintAllies();
        showEnemy();
        moveEnemy();
        showEnemyBall(); 
        showItem();
        Sleep(40);
        
        if (!shootingCount <= 0) {
            showItemBall();
        }
        if (currentRound == 4) {
            return 0;
        }
        if (Score >= roundScoreThreshold) {
            currentRound++;
            break;
        }
        
    }
}
////////////////기본 총알_DefaultBall//////////////////
void moveAndPrintAllies()  //아군 총알 이동과 출력
{
    if (defaultBall.exist) {
        for (int i = 0; i < 18; i++) {}
        eraseDefaultBall();
        drawDefaultBall();
    }
    if (defaultBall.y <= 1) {
        defaultBall.exist = FALSE;
        eraseDefaultBall();
    }
}
void drawDefaultBall() {
    defaultBall.y--;
    gotoxy(defaultBall.x, defaultBall.y);
    printf("i");
}
void eraseDefaultBall() {
    gotoxy(defaultBall.x, defaultBall.y);
    printf(" ");
}
//////////////아이템 획득 후 바뀐 총알_ItemBall//////////////////////
void showItemBall() {
    if (itemBall.isShooting) {
        for (int i = 0; i < 21; i++) {}
        eraseItemBall();
        drawItemBall();
        if (itemBall.y <= 1) {
            itemBall.isShooting = FALSE;
            eraseItemBall();
        }
    }
}
void drawItemBall() {
    itemBall.y--;
    gotoxy(itemBall.x, itemBall.y);
    printf("iii");
}
void eraseItemBall() {
    gotoxy(itemBall.x, itemBall.y);
    printf("    ");
}

void drawPlayer(int x, int y, unsigned char ch) { 
    gotoxy(x, y);
    puts("<<A>>");

    if (ch == LEFT) {
        erasePlayer(x + 5, 23);
    }
    if (ch == RIGHT) {
        erasePlayer(x - 2, 23);
    }
    
    gotoxy(0, 34);
    printf("점수 = %d  \n라운드 = %d", Score, currentRound);
}

void erasePlayer(int x, int y) {
    gotoxy(x, y);
    puts("  ");
}

///////////////////적군_Enemy////////////////////////
void showEnemy() {
    int i, j, location, hieght;
    location = rand() % 2;
    hieght = rand() % 10 + 1;

    if (rand() % 50 == 0) {
        for (i = 0; i < MAXENEMY && enemy[i].exist == TRUE; i++) {}
        if (i != MAXENEMY) {
            if (location == 1) {
                enemy[i].x = 5;
                enemy[i].move = 1;
            }
            else {
                enemy[i].x = 75;
                enemy[i].move = -1;
            }
            for (;;) {
                enemy[i].y = rand() % 10 + 1;
                for (bFound = FALSE, j = 0; j < MAXENEMY; j++) {
                    if (enemy[j].exist == TRUE && enemy[j].y == enemy[i].y) {
                        bFound = TRUE;
                        break;
                    }
                }
                if (bFound == FALSE) {
                    break;
                }
            }
            enemy[i].nFrame = enemy[i].nStay = rand() % 6 + 1;
            enemy[i].type = rand() % 4;
            enemy[i].exist = TRUE;
            getEnemyHealth(i);
        }
    }
}
void moveEnemy() {
    int i;
    for (i = 0; i < MAXENEMY; i++) {
        if (enemy[i].exist == FALSE) continue;
        if (--enemy[i].nStay == 0) {
            enemy[i].nStay = enemy[i].nFrame;
            if (enemy[i].x > 75 || enemy[i].x < 5) {
                enemy[i].exist = FALSE;
                gotoxy(enemy[i].x, enemy[i].y);
                puts("      ");
            }
            else {
                enemy[i].x += enemy[i].move * enemySpeed;
                eraseEnemy(i);
                if (enemy[i].health == 1) {

                    gotoxy(enemy[i].x, enemy[i].y);
                    puts(arEnemy[enemy[i].type]);
                }
                else if (enemy[i].health <= 3 && enemy[i].health > 0) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
                    gotoxy(enemy[i].x, enemy[i].y);
                    puts(arEnemy[enemy[i].type]);
                    puts("        ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                }
                else if (enemy[i].health <= 5 && enemy[i].health > 0) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                    gotoxy(enemy[i].x, enemy[i].y);
                    puts(arEnemy[enemy[i].type]);
                    puts("        ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                }

            }
        }
        if (defaultBall.exist && defaultBall.y == enemy[i].y && abs(defaultBall.x - enemy[i].x) <= 4.5) {
            defaultBall.exist = FALSE;
            eraseDefaultBall();
            hitEnemy(i);
        }
        if (enemy[i].y == itemBall.y && abs(enemy[i].x - itemBall.x) <= 4.5) {
            itemBall.isShooting = FALSE;
            eraseItemBall();
            hitEnemy(i);
        }
    }
}
void eraseEnemy(int i) {
    if (enemy[i].move == 1) {
        gotoxy(enemy[i].x - enemySpeed, enemy[i].y);
        puts("         ");
    }
    else {
        gotoxy(enemy[i].x + enemySpeed, enemy[i].y);
        puts("         ");
    }
}
int getEnemyHealth(int i) {
    if (currentRound == 1) {
        enemy[i].health = 1;
    }
    else if (currentRound == 2) {
        enemy[i].health = (rand() % 2 == 0) ? 1 : 3;
    }
    else if (currentRound == 3) {
        enemy[i].health = (rand() % 2 == 0) ? 3 : 5;
    }
}

void hitEnemy(int i) {
    switch (enemy[i].health) {
    case 1:
        enemy[i].exist = FALSE;
        gotoxy(enemy[i].x, enemy[i].y);
        printf("       ");
        Score += 7 - enemy[i].nFrame;
        break;
    case 2:
    case 3: 
        enemy[i].health--;
        break;
    case 4:
    case 5:
        enemy[i].health--;
        break;
    }
}
///////////////////적군 총알_EnemyBall////////////////////////
void showEnemyBall() {
    int i;
    int r = rand() % 100 + 1;
    for (i = 0; i < MAXENEMYBALL && enemyBall[i].exist == TRUE; i++) {}
    if (i != MAXENEMYBALL && enemy[r].exist == TRUE) {
        enemyBall[i].x = enemy[r].x;
        enemyBall[i].y = enemy[r].y;
        enemyBall[i].nFrame = enemyBall[i].nStay = enemy[i].nFrame * 6;
        enemyBall[i].exist = TRUE;
    }
    moveEnemyBall();
}
void drawEnemyBall(int i) {
    gotoxy(enemyBall[i].x, enemyBall[i].y);
    printf("*");
}
void eraseEnemyBall(int i) {
    gotoxy(enemyBall[i].x, enemyBall[i].y);
    printf(" ");
}
void moveEnemyBall() { 
    int i;
    for (i = 0; i < MAXENEMYBALL; i++)
    {
        enemyBall[i].nStay = enemyBall[i].nFrame;
        gotoxy(enemyBall[i].x, enemyBall[i].y); printf(" ");
        if (enemyBall[i].exist == TRUE) {
            eraseEnemyBall(i);
            if (enemyBall[i].y >= 23) {
                enemyBall[i].exist = FALSE;
            }
            else {
                enemyBall[i].y++;
                drawEnemyBall(i);
            }
        }
        if (enemyBall[i].exist == FALSE) {
            continue;
        }
        if (enemyBall[i].y == 23 && abs(enemyBall[i].x - fx) <= 5) {
            hitPlayer(i);
        }
        return 0;
    }
}
void hitPlayer(int i) {
    enemyBall[i].exist = FALSE;
    gotoxy(fx - 2, 21); puts("   .   ");
    gotoxy(fx - 2, 22); puts(" .  . .");
    gotoxy(fx - 2, 23); puts("..:V:..");
    currentRound = 4;
}
//////////////////////아이템_Item//////////////////////////
void showItem() {
    if (rand() % 200 == 0) { // 아이템 나올 확률
        item.x = rand() % 40 + 5;
        item.y = 2;
        item.exist = TRUE;
    }
    if (item.exist == TRUE) {
        static clock_t lastDropTime = 0;
        clock_t currentTime = clock();

        if (currentTime - lastDropTime >= CLOCKS_PER_SEC / ITEM_DROP_SPEED) {
            lastDropTime = currentTime;
            eraseItem();
            moveItem();
        }
    }
}
void moveItem() {
    if (item.y < 24) {
        eraseItem();
        drawItem();
        if (item.y == fy && abs(item.x - fx) <= 3) {
            shootingCount = 6;
            gotoxy(25, 30);
            printf("아이템 획득!");
            itemBall.exist = TRUE;
            defaultBall.exist = FALSE;
            itemBall.isShooting = FALSE;
        }
    }else {
        item.exist = FALSE;
        eraseItem();
    }
}
void drawItem() {
    item.y++;
    gotoxy(item.x, item.y);
    printf("&");
}
void eraseItem() {
    gotoxy(item.x, item.y);
    printf(" ");
}
///////////////////점수_Score//////////////////////////////
int compare(const void* a, const void* b)
{
    return ((PlayerInfo*)b)->score - ((PlayerInfo*)a)->score;
}
void esc() {
    system("cls");
    DisplayHighScores();  // ROUND / RANK / 이름 - 점수
    CursorView(0);
    return 0;
}

void UpdateHighScores(int newScore, PlayerInfo* player)
{
    for (int i = 0; i < MAXPLAYER; i++) {
        if (strcmp(currentPlayer, player[i].name) == 0) {
            player[i].score = newScore;
        }
    }
    qsort(player, arrLength + 1, sizeof(player[0]), compare);

}//현재 플레이어의 순위 결정 함수

void DisplayHighScores()
{
    system("cls");
    UpdateHighScores(Score, playerList);
    printf("===== HIGH SCORES =====\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("<<Rank %d>>\n %s :: %d점\n\n", 1 + i, playerList[i].name, playerList[i].score);
    }
}//끝날 때 RANK / 이름 - 점수