#include"Role.h"
#include<iostream>



/******************************************
Role.h/cpp�ļ��������������߼��������ƶ��ĺ���
*******************************************/

/*BOSS*/
void Boss::move(int State, int x1, int y1)
{
	if (y1 < y && (x == x1 || x1 - 1 == x))//up
	{

		if (LogicPanel[y - 1][x] != 0 || LogicPanel[y - 1][x + 1] != 0)
		{
			//��ӡ"�����ƶ�"
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
			//�����ƶ�
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
		//ɶҲ����
	}
}



/*General1,��������*/

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
		//ɶҲ����
	}
}


/*General2,��������*/
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
		//ɶҲ����
	}
}



/*С��*/
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
		//ɶҲ����
	}
}

