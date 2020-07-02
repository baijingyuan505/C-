#pragma once


/******************************************
Role.h/cpp�ļ��������������߼��������ƶ��ĺ���
*******************************************/




int LogicPanel[5][4] = { 0 };//�߼�����
/*
State��ʾ:
0=�� 1=�ܲ� 2=�� 3=�� 4=�� 5=�� 6=�� 7~10=С��1~4
*/
int total_Stride = 0;//�ܲ���


//����Ϊ4�ֽ�ɫ.��������������2��
//moveϵ�к��������ж�,�ƶ�,�������ﲽ��
//move��������˳��Ϊ������State, ��ʼx1,y2 ,3��int

class Role
{
public:
	int State;
	int Stride = 0;//��¼������Ĳ���
	int x, y;//���������
	
	virtual void move(int,int,int)=0;

};

class Boss :public Role
{
public:
	int State;
	int Stride=0;
	int x, y;//�������ϵĵ������
	
	Boss() {}
	Boss(int State_, int x_, int y_)
	{
		State = State_;
		x = x_;
		y = y_;
	}
	void move(int State,int x1,int y1) ;


};
//��������
class General_1 :public Role
{
public:
	int State;
	int Stride = 0;
	int x, y;//������ߵĵ������
	
	General_1(){}
	General_1(int State_, int x_, int y_)
	{
		State = State_;
		x = x_;
		y = y_;
	}
	void move(int State, int x1, int y1);
};

//��������
class General_2 :public Role
{
public:
	int State;
	int Stride = 0;
	int x, y;//�����ϱߵĵ������
	
	General_2(){}
	General_2(int State_, int x_, int y_)
	{
		State = State_;
		x = x_;
		y = y_;
	}
	void move(int State, int x1, int y1);

};


class Soldier :public Role
{
public:
	int State;
	int x, y;
	int Stride = 0;
	Soldier() {}
	Soldier(int State_, int x_, int y_)
	{
		State = State_;
		x = x_;
		y = y_;
	}
	void move(int State, int x1, int y1);

};



