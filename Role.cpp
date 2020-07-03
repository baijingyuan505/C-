#include"Role.h"
#include<iostream>

extern int LogicPanel[5][4];

int getState(int x, int y) {
	return LogicPanel[y][x];
}
/******************************************
Role.h/cpp文件定义了棋子在逻辑棋盘上移动的函数
*******************************************/

/*BOSS*/
Role::move_result Boss::move(int State, int x1, int y1)
{
	if (y1 < y && (x == x1 || x1 - 1 == x))//up
	{

		if (LogicPanel[y - 1][x] != 0 || LogicPanel[y - 1][x + 1] != 0)
		{
			return move_result::fail;
		}
		else
		{
			LogicPanel[y + 1][x] = 0;
			LogicPanel[y + 1][x + 1] = 0;
			LogicPanel[y - 1][x] = State;
			LogicPanel[y - 1][x + 1] = State;
			y -= 1;
			Stride += 1;
			return move_result::up;

		}
	}
	else if (y1 > this->y && (this->x == x1 || x1 - 1 == this->x))//down
	{
		if (LogicPanel[y + 2][x] != 0 || LogicPanel[y + 2][x + 1] != 0)
		{
			return move_result::fail;
		}
		else
		{
			LogicPanel[y + 2][x] = State;
			LogicPanel[y + 2][x + 1] = State;
			LogicPanel[y][x] = 0;
			LogicPanel[y][x + 1] = 0;
			y += 1;
			Stride += 1;
			return move_result::down;

		}
	}
	else if (x1 > this->x && (this->y == y1 || y1 - 1 == this->y))//right
	{
		if (LogicPanel[y][x + 2] != 0 || LogicPanel[y + 1][x + 2] != 0)
		{
			return move_result::fail;
		}
		else
		{
			LogicPanel[y][x] = 0;
			LogicPanel[y + 1][x] = 0;
			LogicPanel[y][x + 2] = State;
			LogicPanel[y + 1][x + 2] = State;
			x += 1;
			Stride += 1;
			return move_result::right;
		}
	}
	else if (x1 < this->x && (this->y == y1 || y1 - 1 == this->y))//left
	{
		if (LogicPanel[y][x - 1] != 0 || LogicPanel[y + 1][x - 1] != 0)
		{
			return move_result::fail;
		}
		else
		{
			LogicPanel[y][x + 1] = 0;
			LogicPanel[y + 1][x + 1] = 0;
			LogicPanel[y][x - 1] = State;
			LogicPanel[y + 1][x - 1] = State;
			x -= 1;
			Stride += 1;
			return move_result::left;
		}
	}
	else
	{
		return move_result::fail;
	}
}

Role::move_result General::move(int State, int x1, int y1)
{
	x = 0, y = 0;
	switch (Form) {
	case 1://横条
		if (y1 < this->y && (this->x == x1 || x1 - 1 == this->x))//up
		{
			if (LogicPanel[y - 1][x] != 0 || LogicPanel[y - 1][x + 1] != 0)
			{
				return move_result::fail;
			}
			else
			{
				LogicPanel[y - 1][x] = State;
				LogicPanel[y - 1][x + 1] = State;
				LogicPanel[y][x] = 0;
				LogicPanel[y][x + 1] = 0;
				y -= 1;
				Stride += 1;
				return move_result::up;
			}
		}
		else if (y1 > this->y && (this->x == x1 || x1 - 1 == this->x))//down
		{
			if (LogicPanel[y + 1][x] != 0 || LogicPanel[y + 1][x + 1] != 0)
			{
				return move_result::fail;
			}
			else
			{
				LogicPanel[y + 1][x] = State;
				LogicPanel[y + 1][x + 1] = State;
				LogicPanel[y][x] = 0;
				LogicPanel[y][x + 1] = 0;
				y += 1;
				Stride += 1;
				return move_result::down;
			}
		}
		else if (x1 > this->x && this->y == y1)//right
		{
			if (LogicPanel[y][x + 2] != 0)
			{
				return move_result::fail;
			}
			else
			{
				LogicPanel[y][x + 2] = State;
				LogicPanel[y][x] = 0;
				x += 1;
				Stride += 1;
				return move_result::right;
			}
		}
		else if (x1 < this->x && this->y == y1)//left
		{
			if (LogicPanel[y][x - 1] != 0)
			{
				return move_result::fail;
			}
			else
			{
				LogicPanel[y][x - 1] = State;
				LogicPanel[y][x + 1] = 0;
				x -= 1;
				Stride += 1;
				return move_result::left;
			}
		}
		else
		{
			return move_result::fail;
		}
		break;
	case 2://竖条
		if (y1 < this->y && this->x == x1)//up
		{
			if (LogicPanel[y - 1][x] != 0)
			{
				return move_result::fail;
			}
			else
			{
				std::cout << "up";
				LogicPanel[y - 1][x] = State;
				LogicPanel[y + 1][x] = 0;
				y -= 1;
				Stride += 1;
				return move_result::up;
			}
		}
		else if (y1 > this->y && this->x == x1)//down
		{
			if (LogicPanel[y + 2][x] != 0)
			{
				return move_result::fail;
			}
			else
			{
				LogicPanel[y + 2][x] = State;
				LogicPanel[y][x] = 0;
				y += 1;
				Stride += 1;
				std::cout << "down";
				return move_result::down;
			}
		}
		else if (x1 > this->x && (this->y == y1 || y1 - 1 == this->y))//right
		{
			if (LogicPanel[y][x + 1] != 0 || LogicPanel[y + 1][x + 1] != 0)
			{
				return move_result::fail;
			}
			else
			{
				LogicPanel[y][x + 1] = State;
				LogicPanel[y + 1][x + 1] = State;
				LogicPanel[y][x] = 0;
				LogicPanel[y + 1][x] = 0;
				x += 1;
				Stride += 1;
				std::cout << "right";
				return move_result::right;
			}
		}
		else if (x1 < this->x && (this->y == y1 || y1 - 1 == this->y))//left
		{
			if (LogicPanel[y][x - 1] != 0 || LogicPanel[y + 1][x - 1] != 0)
			{
				return move_result::fail;
			}
			else
			{
				LogicPanel[y][x - 1] = State;
				LogicPanel[y + 1][x - 1] = State;
				LogicPanel[y][x] = 0;
				LogicPanel[y + 1][x] = 0;
				x -= 1;
				Stride += 1;
				std::cout << "left";
				return move_result::left;
			}
		}
		else
		{
			return move_result::fail;
		}
		break;
	default:
		return move_result::fail;
		break;
	}
}


/*小兵*/
Role::move_result Soldier::move(int State, int x1, int y1)
{
	if (y1 < this->y && this->x == x1)//up
	{
		if (LogicPanel[y - 1][x] != 0)
		{
			return move_result::fail;
		}
		else
		{

			LogicPanel[y][x] = 0;
			LogicPanel[y - 1][x] = State;
			y -= 1;
			Stride += 1;
			return move_result::up;
		}
	}
	else if (y1 > this->y && this->x == x1)//down
	{
		if (LogicPanel[y + 1][x] != 0)
		{
			return move_result::fail;
		}
		else
		{
			LogicPanel[y][x] = 0;
			LogicPanel[y + 1][x] = State;
			y += 1;
			Stride += 1;
			return move_result::down;
		}
	}
	else if (x1 > this->x && this->y == y1)//right
	{
		if (LogicPanel[y][x + 1] != 0)
		{
			return move_result::fail;
		}
		else
		{
			LogicPanel[y][x] = 0;
			LogicPanel[y][x + 1] = State;
			x += 1;
			Stride += 1;
			return move_result::right;
		}
	}
	else if (x1 < this->x && this->y == y1)//left
	{
		if (LogicPanel[y][x - 1] != 0)
		{
			return move_result::fail;
		}
		else
		{
			LogicPanel[y][x] = 0;
			LogicPanel[y][x - 1] = State;
			x -= 1;
			Stride += 1;
			return move_result::left;
		}
	}
	else
	{
		return move_result::fail;
	}
}