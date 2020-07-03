#pragma once


/******************************************
Role.h/cpp文件定义了棋子在逻辑棋盘上移动的函数
*******************************************/



int LogicPanel[5][4] = { 0 };//逻辑棋盘
int getState(int x, int y);
/*
State表示:
0=空 1=曹操 2=关 3=赵 4=马 5=黄 6=张 7~10=小兵1~4
*/



//以下为4种角色.将军横着竖着算2种
//move系列函数包含判断,移动,增加人物步数
//move函数参数顺序为人物标记State, 初始x1,y2 ,3个int

class Role
{
public:
	static enum move_result { fail = 0, up, down, left, right };
	int State=0;
	int Stride = 0;//记录各人物的步数
	int x, y;//人物的坐标
	virtual move_result move(int, int, int) = 0;
};
//曹操
class Boss :public Role
{
public:
	int State=0;
	int Stride = 0;
	int x, y;//人物左上的点的坐标
	Boss(int State_, int x_, int y_)
	{
		State = State_;
		x = x_;
		y = y_;
	}
	move_result move(int State, int x1, int y1);
};
//将军
class General:public Role
{
public:
	int State=0;
	int Form=0;
	int Stride = 0;
	int x, y;//人物左边的点的坐标

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



