#include"Role.h"
#include<iostream>



/******************************************
Role.h/cpp文件定义了棋子在逻辑棋盘上移动的函数
*******************************************/

/*BOSS*/
void Boss::move_up(int State)
{
	if (y == 0 || LogicPanel[x][y - 1] !=0  || LogicPanel[x + 1][y - 1] != 0)
	{
		//打印"不能移动"
	}
	else
	{
		LogicPanel[x][y + 1] = 0;
		LogicPanel[x + 1][y + 1] = 0;
		LogicPanel[x][y - 1] = State;
		LogicPanel[x + 1][y - 1] = State;
		y -= 1;
		Stride += 1;
	}
}

void Boss::move_down(int State)
{
	if (y >= 3 || LogicPanel[x][y + 1] != 0 || LogicPanel[x + 1][y + 1] != 0)
	{
		//不能移动
	}
	else
	{
		LogicPanel[x][y + 2] = State;
		LogicPanel[x + 1][y + 2] = State;
		LogicPanel[x][y] = 0;
		LogicPanel[x + 1][y] = 0;
		y += 1;
		Stride += 1;
	}
}

void Boss::move_left(int State)
{
	if (x == 0 || LogicPanel[x - 1][y] != 0 || LogicPanel[x - 1][y + 1] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x+1][y] = 0;
		LogicPanel[x + 1][y + 1] = 0;
		LogicPanel[x-1][y] = State;
		LogicPanel[x - 1][y+1] = State;
		x -= 1;
		Stride += 1;
	}
}

void Boss::move_right(int State)
{
	if (x >= 2 || LogicPanel[x + 2][y] != 0 || LogicPanel[x + 2][y + 1] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x][y] = 0;
		LogicPanel[x + 1][y] = 0;
		LogicPanel[x + 2][y] = State;
		LogicPanel[x + 2][y + 1] = State;
		x += 1;
		Stride += 1;
	}
}


/*General1,横条将军*/
void General_1::move_down(int State)
{
	if (y == 4 || LogicPanel[x][y + 1] != 0 || LogicPanel[x + 1][y + 1] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x][y + 1] = State;
		LogicPanel[x + 1][y + 1] = State;
		LogicPanel[x][y] = 0;
		LogicPanel[x + 1][y] = 0;
		y += 1;
		Stride += 1;
	}
}

void General_1::move_up(int State)
{
	if (y == 0 || LogicPanel[x][y - 1] != 0 || LogicPanel[x + 1][y - 1] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x][y - 1] = State;
		LogicPanel[x + 1][y - 1] = State;
		LogicPanel[x][y] = 0;
		LogicPanel[x + 1][y] = 0;
		y -= 1;
		Stride += 1;
	}
}

void General_1::move_right(int State)
{
	if (x >= 2 || LogicPanel[x + 2][y] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x + 2][y] = State;
		LogicPanel[x][y] = 0;
		x += 1;
		Stride += 1;
	}
}

void General_1::move_left(int State)
{
	if (x == 0 || LogicPanel[x - 1][y] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x - 1][y] = State;
		LogicPanel[x + 1][y] = 0;
		x -=1;
		Stride += 1;
	}
}

/*General2,竖条将军*/
void General_1::move_down(int State)
{
	if (y >= 3 || LogicPanel[x][y + 2] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x][y + 2] = State;
		LogicPanel[x][y] = 0;
		y += 1;
		Stride += 1;
	}
}

void General_1::move_up(int State)
{
	if (y == 0 || LogicPanel[x][y - 1] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x][y - 1] = State;
		LogicPanel[x][y+1] = 0;
		y -= 1;
		Stride += 1;
	}
}

void General_1::move_right(int State)
{
	if (x == 3 || LogicPanel[x + 1][y] != 0 || LogicPanel[x+1][y+1] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x + 1][y] = State;
		LogicPanel[x + 1][y + 1] = State;
		LogicPanel[x][y] = 0;
		LogicPanel[x][y + 1] = 0;
		x += 1;
		Stride += 1;
	}
}

void General_1::move_left(int State)
{
	if (x == 0 || LogicPanel[x - 1][y] != 0 || LogicPanel[x - 1][y + 1] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x - 1][y] = State;
		LogicPanel[x - 1][y + 1] = State;
		LogicPanel[x][y] = 0;
		LogicPanel[x][y + 1] = 0;
		x -= 1;
		Stride += 1;
	}
}

/*小兵*/
void Soldier::move_down(int State)
{
	if (y == 4 || LogicPanel[x][y + 1] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x][y] = 0;
		LogicPanel[x][y + 1] = State;
		y += 1;
		Stride += 1;
	}
}

void Soldier::move_up(int State)
{
	if (y == 0 || LogicPanel[x][y - 1] != 0)
	{
		//
	}
	else
	{
		
		LogicPanel[x][y] = 0;
		LogicPanel[x][y - 1] = State;
		y -= 1;
		Stride += 1;
	}
}

void Soldier::move_left(int State)
{
	if (x == 0 || LogicPanel[x-1][y] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x][y] = 0;
		LogicPanel[x-1][y] = State;
		x -= 1;
		Stride += 1;
	}
}

void Soldier::move_right(int State)
{
	if (x == 3 || LogicPanel[x + 1][y] != 0)
	{
		//
	}
	else
	{
		LogicPanel[x][y] = 0;
		LogicPanel[x + 1][y] = State;
		x += 1;
		Stride += 1;
	}
}