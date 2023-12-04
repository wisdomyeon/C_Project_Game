#include "main.h"

#define ESC 27
#define SPACE 0x20
#define LEFT 0x4b
#define RIGHT 0x4d //���� �ڸ� ���� util.h��
//#define COLOR GetStdHandle(STD_OUTPUT_HANDLE);
//#define PURPLE SetConsoleTextAttribute(COLOR, 0x0005);
//#define GREEN SetConsoleTextAttribute(COLOR, 0x0002);
//#define WHITE SetConsoleTextAttribute(COLOR, 0x0007);

#define MAXPLAYER 10
#define MAXENEMY 10
#define MAXBALL 15 //BALL ���� MISSILE�� ����
#define MAXSCORES 5
#define MAXENEMYBALL 15

int Score = 0;
int count = 0;
int fx = 60;
char ch;
int bx = -1;
int by;

char currentPlayer[20];
int roundScoreThreshold = 60;
int currentRound = 1;

BOOL bFound;
int enemySpeed = 1; // �ʱ� �̵� �ӵ�

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
}PlayerInfo; // �÷��̾� ���� ����ü 

typedef struct 
{
    BOOL exist;
    int type;
    int x, y;
    int move;
    int nFrame;
    int nStay;
    int health;
}Enemy; // ���� ����ü

typedef struct 
{
    BOOL exist;
    int x, y;
    int nFrame;
    int nStay;
}EnemyBall; // ���� �Ѿ� ����ü

typedef struct {
    BOOL exist;
    int x, y;
}Item;

const char* arEnemy[] = { " ;:^:; "," zZWZz ", " oO@Oo ", " <-=-> " };

void ShotingGame();
void RoundOne();
void playerMove(unsigned char ch);
void playerDraw(int x, int y);
void playerErase(int x, int y);
void showEnemy();
void moveEnemy();
void showEnemyBall();
void drawEnemyBall(int i);
void eraseEnemyBall(int i);
void moveEnemyBall();
int getEnemyHealth();
void hitPlayer(int i);
void showItem();
void moveItem();
void drawItem();
void eraseItem();
void getItemPlayer();
void RoundTwo();
void RoundThree();
//int keyControl();
int ascending_comp(const void* a, const void* b);
int descending_comp(const void* a, const void* b);
void UpdateHighScores(int newScore, PlayerInfo* player);
void DisplayHighScores();
void esc();