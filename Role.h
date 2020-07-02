#pragma once


/******************************************
Role.h/cpp文件定义了棋子在逻辑棋盘上移动的函数
*******************************************/




int LogicPanel[4][5] = { 0 };//逻辑棋盘
/*
State表示:
0=空 1=曹操 2=关 3=赵 4=马 5=黄 6=张 7~10=小兵1~4
*/
int Stride = 0;//总步数


//以下为4种角色.将军横着竖着算2种
//move系列函数包含判断,移动,语音播放
class Role
{
public:
	int State;
	int Stride = 0;//记录各人物的步数
	int x, y;//人物的坐标
	
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
	int x, y;//人物左上的点的坐标
	
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
//横条将军
class General_1 :public Role
{
public:
	int State;
	int Stride = 0;
	int x, y;//人物左边的点的坐标
	
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

//竖条将军
class General_2 :public Role
{
public:
	int State;
	int Stride = 0;
	int x, y;//人物上边的点的坐标
	
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



