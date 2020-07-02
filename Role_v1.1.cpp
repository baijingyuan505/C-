#include"Role.h"
#include<iostream>



/******************************************
Role.h/cpp文件定义了棋子在逻辑棋盘上移动的函数
*******************************************/

/*BOSS*/
void Boss::move(int State, int x1, int y1)
{
	if (y1 < y && (x == x1 || x1 - 1 == x))//up
	{

		if (LogicPanel[y - 1][x] != 0 || LogicPanel[y - 1][x + 1] != 0)
		{
			//打印"不能移动"
		}
		else
		{
			LogicPanel[y + 1][x] = 0;
			LogicPanel[y + 1][x + 1] = 0;
			LogicPanel[y - 1][x] = State;
			LogicPanel[y - 1][x + 1] = State;
			y -= 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (y1 > this->y && (this->x == x1 || x1 - 1 == this->x))//down
	{
		if (LogicPanel[y + 2][x] != 0 || LogicPanel[y + 2][x + 1] != 0)
		{
			//不能移动
		}
		else
		{
			LogicPanel[y + 2][x] = State;
			LogicPanel[y + 2][x + 1] = State;
			LogicPanel[y][x] = 0;
			LogicPanel[y][x + 1] = 0;
			y += 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (x1 > this->x && (this->y == y1 || y1 - 1 == this->y))//right
	{
		if (LogicPanel[y][x + 2] != 0 || LogicPanel[y + 1][x + 2] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y][x] = 0;
			LogicPanel[y+1][x] = 0;
			LogicPanel[y][x + 2] = State;
			LogicPanel[y + 1][x + 2] = State;
			x += 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (x1 < this->x && (this->y == y1 || y1 - 1 == this->y))//left
	{
		if (LogicPanel[y][x - 1] != 0 || LogicPanel[y + 1][x - 1] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y][x + 1] = 0;
			LogicPanel[y + 1][x + 1] = 0;
			LogicPanel[y][x - 1] = State;
			LogicPanel[y + 1][x - 1] = State;
			x -= 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else
	{
		//啥也不干
	}
}



/*General1,横条将军*/

void General_1::move(int State, int x1, int y1)
{
	if (y1 < this->y && (this->x == x1 || x1 - 1 == this->x))//up
	{
		if (LogicPanel[y - 1][x] != 0 || LogicPanel[y - 1][x + 1] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y - 1][x] = State;
			LogicPanel[y - 1][x + 1] = State;
			LogicPanel[y][x] = 0;
			LogicPanel[y][x + 1] = 0;
			y -= 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (y1 > this->y && (this->x == x1 || x1 - 1 == this->x))//down
	{
		if (LogicPanel[y + 1][x] != 0 || LogicPanel[y + 1][x + 1] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y + 1][x] = State;
			LogicPanel[y + 1][x + 1] = State;
			LogicPanel[y][x] = 0;
			LogicPanel[y][x + 1] = 0;
			y += 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (x1 > this->x && this->y == y1 )//right
	{
		if (LogicPanel[y][x + 2] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y][x + 2] = State;
			LogicPanel[y][x] = 0;
			x += 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (x1 < this->x && this->y == y1)//left
	{
		if (LogicPanel[y][x - 1] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y][x - 1] = State;
			LogicPanel[y][x + 1] = 0;
			x -= 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else
	{
		//啥也不干
	}
}


/*General2,竖条将军*/
void General_2::move(int State, int x1, int y1)
{
	if (y1 < this->y && this->x == x1)//up
	{
		if (LogicPanel[y - 1][x] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y - 1][x] = State;
			LogicPanel[y + 1][x] = 0;
			y -= 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (y1 > this->y && this->x == x1)//down
	{
		if (LogicPanel[y + 2][x] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y + 2][x] = State;
			LogicPanel[y][x] = 0;
			y += 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (x1 > this->x && (this->y == y1 || y1 - 1 == this->y))//right
	{
		if (LogicPanel[y][x + 1] != 0 || LogicPanel[y + 1][x + 1] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y][x + 1] = State;
			LogicPanel[y + 1][x + 1] = State;
			LogicPanel[y][x] = 0;
			LogicPanel[y + 1][x] = 0;
			x += 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (x1 < this->x && (this->y == y1 || y1 - 1 == this->y))//left
	{
		if (LogicPanel[y][x - 1] != 0 || LogicPanel[y + 1][x - 1] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y][x - 1] = State;
			LogicPanel[y + 1][x - 1] = State;
			LogicPanel[y][x] = 0;
			LogicPanel[y + 1][x] = 0;
			x -= 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else
	{
		//啥也不干
	}
}



/*小兵*/
void Soldier::move(int State, int x1, int y1)
{
	if (y1 < this->y && this->x == x1)//up
	{
		if (LogicPanel[y - 1][x] != 0)
		{
			//
		}
		else
		{

			LogicPanel[y][x] = 0;
			LogicPanel[y - 1][x] = State;
			y -= 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (y1 > this->y && this->x == x1 )//down
	{
		if (LogicPanel[y + 1][x] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y][x] = 0;
			LogicPanel[y + 1][x] = State;
			y += 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (x1 > this->x && this->y == y1)//right
	{
		if (LogicPanel[y][x + 1] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y][x] = 0;
			LogicPanel[y][x + 1] = State;
			x += 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else if (x1 < this->x && this->y == y1)//left
	{
		if (LogicPanel[y][x - 1] != 0)
		{
			//
		}
		else
		{
			LogicPanel[y][x] = 0;
			LogicPanel[y][x - 1] = State;
			x -= 1;
			Stride += 1;
			total_Stride += 1;
		}
	}
	else
	{
		//啥也不干
	}
}

