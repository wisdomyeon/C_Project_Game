#include "main.h"

#define ESC 27
#define SPACE 0x20
#define LEFT 0x4b
#define RIGHT 0x4d //���� �ڸ� ���� util.h��

#define MAXPLAYER 10
#define MAXENEMY 10
#define MAXBALL 15
#define MAXSCORES 5
#define MAXENEMYBALL 10

int Score = 0;
int count = 0;
int fx = 60;
char ch;
int bx = -1;
int by;
char currentPlayer[20];
int enemySpeed = 1; // �ʱ� �̵� �ӵ�
int roundScoreThreshold = 60; // ���尡 ���������� ������ �Ӱ谪 �ʱ�ȭ =====> ������ 60�� ����
int currentRound = 1;

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

typedef struct // �÷��̾� ���� ����ü 
{
    int score;
    //int rank;
    char name[20];
}PlayerInfo;

void ShotingGame();
void RoundOne();
void playerMove(unsigned char ch);
void playerDraw(int x, int y);
void playerErase(int x, int y);
void RoundTwo();
void RoundThree();
//int keyControl();
int ascending_comp(const void* a, const void* b);
int descending_comp(const void* a, const void* b);
void UpdateHighScores(int newScore, PlayerInfo *player);
void DisplayHighScores();
int esc();