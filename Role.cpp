#include"Role.h"
#include<iostream>



/******************************************
Role.h/cpp�ļ��������������߼��������ƶ��ĺ���
*******************************************/

/*BOSS*/
void Boss::move_up(int State)
{
	if (y == 0 || LogicPanel[x][y - 1] !=0  || LogicPanel[x + 1][y - 1] != 0)
	{
		//��ӡ"�����ƶ�"
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
		//�����ƶ�
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


/*General1,��������*/
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

/*General2,��������*/
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

/*С��*/
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