#include "game.h"

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
    //fgets(playerInfo->name, sizeof(playerInfo->name), stdin);

    for (int i = 0; i < arrLength; i++) {
        res = strcmp(currentPlayer, playerList[i].name) == 0 ? 1 : 0;
    }
    if (res == 0) {
        //player[arrLength + 1].name[strcspn(player[arrLength+1].name, "\n")] = '\0';
        strcpy_s(playerList[arrLength].name, 20, currentPlayer);
    }

    //게임시작
    while (1) {
        switch (currentRound) {
        case 1: RoundOne(); break;
        case 2: RoundTwo(); break;
        case 3: RoundThree(); break;
        }
    }
}

// 라운드1
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
                    //playerMove(ch);
                    break;
                case SPACE:
                    defaultBall.x = fx + 2 ;
                    defaultBall.y = fy ;
                    defaultBall.exist = TRUE;
                    break;
                case ESC:
                    esc();
                    break;
                }
            }
            if (item.y == fy && abs(item.x - fx) <= 6) {
                gotoxy(25, 30);
                printf("아이템 획득!");
                itemBall.exist = TRUE;
                defaultBall.exist = FALSE;
            }
            if (!itemBall.isShooting) {
                if (ch == SPACE && itemBall.exist) {
                    itemBall.isShooting = TRUE;
                    itemBall.x = fx+1;
                    itemBall.y = 23-1;
                }
            }
        }
        playerDraw(fx, fy, ch);
        moveAndPrintAllies();
        showEnemy();
        moveEnemy();
        //showEnemyBall(); 
        showItem();
        showItemBall();

        Sleep(40);

        if (currentRound == 0) {
            esc();
            break;
        }

        if (Score >= roundScoreThreshold) {
            currentRound++;
            roundScoreThreshold += 60;
            enemySpeed++;
            return 0;
        }
    }
}
///////////////////////기본 총알//////////////////////////////
void moveAndPrintAllies()  //아군 총알 이동과 출력
{
    itemBall.exist = FALSE;
    if (defaultBall.y <= 1) {
        defaultBall.exist = FALSE;
        eraseDefaultBall();
    }
    if (defaultBall.exist && itemBall.exist == FALSE) {
        for (int i = 0; i < 18; i++) {}
        eraseDefaultBall();
        drawDefaultBall();
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
//////////////아이템 획득 후 바뀐 총알//////////////////////
void showItemBall() {
    if (defaultBall.exist == FALSE && itemBall.isShooting == TRUE) {
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

///////////////////라운드2/////////////////////////
void RoundTwo() {
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
                case RIGHT:
                    //playerMove(ch);
                    break;
                case ESC:
                    esc();
                    break;
                }
            }
        }
        showEnemy();
        moveEnemy();
        showEnemyBall();
        showItem();

        Sleep(50);

        if (currentRound == 0) {
            esc();
            break;
        }
        if (Score >= roundScoreThreshold) {
            currentRound++;
            roundScoreThreshold += 60;
            enemySpeed++;
        }
    }
}
// 라운드3
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
                case RIGHT:
                    //playerMove(ch);
                    break;
                case ESC:
                    esc();
                    break;
                }
            }
        }
        showEnemy();
        moveEnemy();
        showEnemyBall();
        showItem();
        //Sleep(3000);
        
        Sleep(50);
        if (currentRound == 0) {
            esc();
            break;
        }
        if (Score >= roundScoreThreshold) {
            currentRound++;
        }
    }
}


/*void playerMove() { //movePlayer수정
    if (ch == LEFT) {
        if (bx > 6) {
            bx--;
            playerDraw(bx, 23);
            playerErase(bx + 5, 23);
        }
    }
    if (ch == RIGHT) {
        if (bx < 72) {
            bx++;
            playerDraw(bx, 23);
            playerErase(bx - 2, 23);
        }
    }
}*/

void playerDraw(int x, int y, unsigned char ch) { //Drawplayer수정
    gotoxy(x, y);
    puts("<<A>>");

    if (ch == LEFT) {
        playerErase(x + 5, 23);
    }
    if (ch == RIGHT) {
        playerErase(x - 2, 23);
    }
    
    gotoxy(0, 34);
    printf("점수 = %d  \n라운드 = %d", Score, currentRound);
}

void playerErase(int x, int y) {
    gotoxy(x, y);
    puts("  ");
}

//Enemy function
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
        if (enemy[i].y == itemBall.y && abs(enemy[i].x - itemBall.x) <= 6) {
            enemy[i].exist = FALSE;
            itemBall.isShooting = FALSE;
            eraseItemBall();
            hitEnemy(i);
        }
    }
}

void eraseEnemy(int i) {
    if (enemy[i].move == 1) {
        gotoxy(enemy[i].x - enemySpeed, enemy[i].y);
        puts("       ");
    }
    else {
        gotoxy(enemy[i].x + enemySpeed, enemy[i].y);
        puts("       ");
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
    gotoxy(bx, by);
    printf("     ");
    gotoxy(enemy[i].x, enemy[i].y);
    puts("       ");
    enemy[i].hit = TRUE;
    if (enemy[i].hit == TRUE) {
        Score += 7 - enemy[i].nFrame;
    }
}


//EnemyBall function
void showEnemyBall() {
    int i;
    int r = rand() % 100 + 1;
    for (i = 0; i < MAXENEMYBALL && enemyBall[i].exist == TRUE; i++) {}
    if (i != MAXENEMYBALL && enemy[r].exist == TRUE) {
        enemyBall[i].x = enemy[r].x;
        enemyBall[i].y = enemy[r].y;
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
void moveEnemyBall() { //추후 총알 속도만 느리게
    int i;
    for (i = 0; i < MAXENEMYBALL; i++)
    {
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
    currentRound = 0;
}
//////////////////////아이템//////////////////////////
void showItem() {
    if (rand() % 200 == 0) { // 아이템 나올 확률
        item.x = 30; //rand() % 40 + 5;
        item.y = 2;
        item.exist = TRUE;
    }
    if (item.exist == TRUE) {
        eraseItem();
        moveItem();
    }
}

void moveItem() {
    if (item.y >= 23) {
        item.exist = FALSE;
        eraseItem();
    }else {
        eraseItem();
        drawItem();
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

int compare(const void* a, const void* b)
{
    return ((PlayerInfo*)b)->score - ((PlayerInfo*)a)->score;
}

void esc() {
    system("cls");
    //gotoxy(30, 10);
    //printf("==========================GAMEOVER==========================\n\n");
    DisplayHighScores();  // ROUND / RANK / 이름 - 점수
    CursorView(0);
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
        printf("<<Rank %d>>\n ROUND %d :: %s :: %d\n\n", 1 + i, currentRound, playerList[i].name, playerList[i].score);
    }
}//끝날 때 ROUND / RANK / 이름 - 점수