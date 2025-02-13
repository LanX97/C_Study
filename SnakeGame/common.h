#ifndef _COMMON_H
#define _COMMON_H

#define WIDE 60
#define HIGH 20

/*�������Ͷ���*/

struct BODY					//ÿ����������
{
	int x;
	int y;
};

struct SNAKE				//һ����
{
	struct BODY body[WIDE * HIGH];
	int size;
}snake;

struct FOOD					//ʳ������
{
	int x;
	int y;
}food;

enum State { GetFood, NotGetFood };

/*ȫ�ֱ�������*/

FILE* fp;
COORD coord;
struct SNAKE snake;
struct FOOD food;
enum State SnakeState;		                                   //��ǰ��״̬
int speed = 200;                                               //�ٶ�
int score = 0, *pscore = &score;				               //�÷�
char key = 'D', currentstate = 'D', userinput;				   //��ǰ�ƶ�״̬
int kx = 0, ky = 0;											   //��ͷ������ƶ�����
int SnakeTail_x = 0, SnakeTail_y = HIGH + 1;	   			   //��β����
int historyrecord = 0, *phistoryrecord = &historyrecord;	   //��¼��ʷ��¼


/*��������*/

void WelcomeToGame(void);			//�����ʼ����
void reset(void);					//���ò���
void UIinfo(void);					//���ͼ�ν���
void SCCP(int x, int y);			//���ù��λ�ú���
void SCCI(void);					//���ù����Ϣ
void initSnake(void);				//��ʼ����λ��
void initFood(void);				//��ʼ��ʳ��λ��
void initUISnake(void);				//�����ͼ��
void initUIFood(void);				//���ʳ��ͼ��
void PlayGame(void);				//��Ϸ���������
void Control();						//�ƶ�����
void GetHistoryRecord(void);		//��ȡ�ļ��е���ʷ��¼
void WriteistoryRecord(void);		//д����ʷ��¼���ļ�
void Gameover(void);				//��Ϸ�������жϼ������滹�ǽ�������

#endif
