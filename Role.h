#pragma once


/******************************************
Role.h/cpp�ļ��������������߼��������ƶ��ĺ���
*******************************************/



int LogicPanel[5][4] = { 0 };//�߼�����
int getState(int x, int y);
/*
State��ʾ:
0=�� 1=�ܲ� 2=�� 3=�� 4=�� 5=�� 6=�� 7~10=С��1~4
*/



//����Ϊ4�ֽ�ɫ.��������������2��
//moveϵ�к��������ж�,�ƶ�,�������ﲽ��
//move��������˳��Ϊ������State, ��ʼx1,y2 ,3��int

class Role
{
public:
	static enum move_result { fail = 0, up, down, left, right };
	int State=0;
	int Stride = 0;//��¼������Ĳ���
	int x, y;//���������
	virtual move_result move(int, int, int) = 0;
};
//�ܲ�
class Boss :public Role
{
public:
	int State=0;
	int Stride = 0;
	int x, y;//�������ϵĵ������
	Boss(int State_, int x_, int y_)
	{
		State = State_;
		x = x_;
		y = y_;
	}
	move_result move(int State, int x1, int y1);
};
//����
class General:public Role
{
public:
	int State=0;
	int Form=0;
	int Stride = 0;
	int x, y;//������ߵĵ������

	General(int State_, int Idx,int x_, int y_)
	{
		State = State_;
		Form = Idx;
		x = x_;
		y = y_;
	}
	move_result move(int State, int x1, int y1);
};

class Soldier :public Role
{
public:
	int State=0;
	int x, y;
	int Stride = 0;
	Soldier() {}
	Soldier(int State_, int x_, int y_)
	{
		State = State_;
		x = x_;
		y = y_;
	}
	move_result move(int State, int x1, int y1);
};



