#include "main.h"

#define ESC 27
#define SPACE 0x20
#define LEFT 0x4b
#define RIGHT 0x4d //추후 자리 조정 util.h로
//#define COLOR GetStdHandle(STD_OUTPUT_HANDLE);
//#define PURPLE SetConsoleTextAttribute(COLOR, 0x0005);
//#define GREEN SetConsoleTextAttribute(COLOR, 0x0002);
//#define WHITE SetConsoleTextAttribute(COLOR, 0x0007);

#define MAXPLAYER 10
#define MAXENEMY 5
#define MAXBALL 15 
#define MAXSCORES 5
#define MAXENEMYBALL 15
#define MAXDEFAULTBALL 10
#define ITEM_DROP_SPEED 15

int Score = 0;
int count = 0;
int fx = 40;
int fy = 23;
char ch;
int bx = -1;
int by;
BOOL bFound;
int roundScoreThreshold = 60; //추후 60으로 변경
int currentRound = 1;
char currentPlayer[20];
int isShooting = 0; // 총 쐈다는 변수
int enemySpeed = 1; // 초기 이동 속도
int shootingCount;

void start();
void printS(int x, int y);
void printH(int x, int y);
void printO(int x, int y);
void printT(int x, int y);
void printI(int x, int y);
void printN(int x, int y);
void printG(int x, int y);
void printA(int x, int y);
void printM(int x, int y);
void printE(int x, int y);

typedef struct 
{
    int score;
    //int rank;
    char name[20];
}PlayerInfo; // 플레이어 정보 구조체 

typedef struct
{
    BOOL exist;
    int x, y;
}DefaultBall; // 플레이어 기본 총알 구조체

typedef struct 
{
    BOOL exist;
    BOOL hit;
    int type;
    int x, y;
    int move;
    int nFrame;
    int nStay;
    int health;
}Enemy; // 적군 구조체

typedef struct 
{
    BOOL exist;
    int x, y;
    int nFrame;
    int nStay;
}EnemyBall; // 적군 총알 구조체

typedef struct {
    BOOL exist;
    int x, y;
}Item; // 떨어지는 아이템 구조체

typedef struct {
    BOOL exist;
    BOOL isShooting;
    int x, y;
}ItemBall; // 아이템 획득후 플레이어 총알 구조체

const char* arEnemy[] = { " ;:^:; "," zZWZz ", " oO@Oo ", " <-=-> " };

void ShotingGame();
void RoundOne();
void RoundTwo();
void RoundThree();
void drawPlayer(int x, int y, unsigned char ch); //drawPlayer로 수정
void erasePlayer(int x, int y); //erasePlayer로 수정
void hitPlayer(int i);
void moveAndPrintAllies();
void drawDefaultBall();
void eraseDefaultBall();
void showEnemy();
void moveEnemy();
void showEnemyBall();
void drawEnemyBall(int i);
void eraseEnemyBall(int i);
void moveEnemyBall();
int getEnemyHealth();
void showItem();
void moveItem();
void drawItem();
void eraseItem();
void showItemBall();
void moveItemBall();
void drawItemBall();
void eraseItemBall();
void getItemPlayer(int x, int y);
void eraseEnemy(int i);
void hitEnemy(int i);
//int keyControl();
//int ascending_comp(const void* a, const void* b);
int compare(const void* a, const void* b);
void UpdateHighScores(int newScore, PlayerInfo* player);
void DisplayHighScores();
void esc();
