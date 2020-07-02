#pragma once


/******************************************
Role.h/cpp�ļ��������������߼��������ƶ��ĺ���
*******************************************/




int LogicPanel[4][5] = { 0 };//�߼�����
/*
State��ʾ:
0=�� 1=�ܲ� 2=�� 3=�� 4=�� 5=�� 6=�� 7~10=С��1~4
*/
int Stride = 0;//�ܲ���


//����Ϊ4�ֽ�ɫ.��������������2��
//moveϵ�к��������ж�,�ƶ�,��������
class Role
{
public:
	int State;
	int Stride = 0;//��¼������Ĳ���
	int x, y;//���������
	
	virtual void move_up(int)=0;
	virtual void move_down(int) = 0;
	virtual void move_right(int) = 0;
	virtual void move_left(int) = 0;
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
	void move_up(int State) ;
	void move_down(int State) ;
	void move_right(int State) ;
	void move_left(int State) ;

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
	void move_up(int State);
	void move_down(int State);
	void move_right(int State);
	void move_left(int State);
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
	void move_up(int State);
	void move_down(int State);
	void move_right(int State);
	void move_left(int State);

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
	void move_up(int State);
	void move_down(int State);
	void move_right(int State);
	void move_left(int State);

};



