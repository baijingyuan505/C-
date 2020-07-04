#include"Stage.h"
#include<iostream>

extern int LogicPanel[5][4];
//Stage.h/cpp�ļ������߼����̵ĳ�ʼ��,�Լ���������
/*
State��ʾ��һ������˭:
0=�� 1=�ܲ� 2=�� 3=�� 4=�� 5=�� 6=�� 7~10=С��1~4
General1Ϊ���� 2Ϊ����
*/
//������ÿһ�ص��߼����̳�ʼ��.

void Stage::Select(int num)
{
	switch (num) {
	case 1:
		Stage1();
		break;
	case 2:
		Stage2();
		break;
	case 3:
		Stage3();
		break;
	case 4:
		Stage4();
		break;
	case 5:
		Stage5();
		break;
	}
}
void Stage::Stage1()
{

	LogicPanel[0][0] = 7;
	LogicPanel[0][1] = 1;
	LogicPanel[0][2] = 1;
	LogicPanel[0][3] = 8;
	LogicPanel[1][0] = 9;
	LogicPanel[1][1] = 1;
	LogicPanel[1][2] = 1;
	LogicPanel[1][3] = 10;
	LogicPanel[2][0] = 5;
	LogicPanel[2][1] = 5;
	LogicPanel[2][2] = 6;
	LogicPanel[2][3] = 6;
	LogicPanel[3][0] = 2;
	LogicPanel[3][1] = 2;
	LogicPanel[3][2] = 3;
	LogicPanel[3][3] = 3;
	LogicPanel[4][0] = 0;
	LogicPanel[4][1] = 4;
	LogicPanel[4][2] = 4;
	LogicPanel[4][3] = 0;


}

void Stage::Stage2()
{

	LogicPanel[0][0] = 7;
	LogicPanel[0][1] = 1;
	LogicPanel[0][2] = 1;
	LogicPanel[0][3] = 8;
	LogicPanel[1][0] = 9;
	LogicPanel[1][1] = 1;
	LogicPanel[1][2] = 1;
	LogicPanel[1][3] = 10;
	LogicPanel[2][0] = 6;
	LogicPanel[2][1] = 5;
	LogicPanel[2][2] = 4;
	LogicPanel[2][3] = 4;
	LogicPanel[3][0] = 6;
	LogicPanel[3][1] = 5;
	LogicPanel[3][2] = 2;
	LogicPanel[3][3] = 2;
	LogicPanel[4][0] = 0;
	LogicPanel[4][1] = 3;
	LogicPanel[4][2] = 3;
	LogicPanel[4][3] = 0;

}

void Stage::Stage3()
{

	LogicPanel[0][0] = 2;
	LogicPanel[0][1] = 1;
	LogicPanel[0][2] = 1;
	LogicPanel[0][3] = 3;
	LogicPanel[1][0] = 2;
	LogicPanel[1][1] = 1;
	LogicPanel[1][2] = 1;
	LogicPanel[1][3] = 3;
	LogicPanel[2][0] = 0;
	LogicPanel[2][1] = 6;
	LogicPanel[2][2] = 5;
	LogicPanel[2][3] = 0;
	LogicPanel[3][0] = 7;
	LogicPanel[3][1] = 6;
	LogicPanel[3][2] = 5;
	LogicPanel[3][3] = 8;
	LogicPanel[4][0] = 9;
	LogicPanel[4][1] = 4;
	LogicPanel[4][2] = 4;
	LogicPanel[4][3] = 10;

}

void Stage::Stage4()
{

	LogicPanel[0][0] = 3;
	LogicPanel[0][1] = 1;
	LogicPanel[0][2] = 1;
	LogicPanel[0][3] = 6;
	LogicPanel[1][0] = 3;
	LogicPanel[1][1] = 1;
	LogicPanel[1][2] = 1;
	LogicPanel[1][3] = 6;
	LogicPanel[2][0] = 7;
	LogicPanel[2][1] = 5;
	LogicPanel[2][2] = 0;
	LogicPanel[2][3] = 8;
	LogicPanel[3][0] = 9;
	LogicPanel[3][1] = 5;
	LogicPanel[3][2] = 0;
	LogicPanel[3][3] = 10;
	LogicPanel[4][0] = 4;
	LogicPanel[4][1] = 4;
	LogicPanel[4][2] = 2;
	LogicPanel[4][3] = 2;

}

void Stage::Stage5()
{

	LogicPanel[0][0] = 2;
	LogicPanel[0][1] = 1;
	LogicPanel[0][2] = 1;
	LogicPanel[0][3] = 3;
	LogicPanel[1][0] = 2;
	LogicPanel[1][1] = 1;
	LogicPanel[1][2] = 1;
	LogicPanel[1][3] = 3;
	LogicPanel[2][0] = 5;
	LogicPanel[2][1] = 5;
	LogicPanel[2][2] = 6;
	LogicPanel[2][3] = 6;
	LogicPanel[3][0] = 7;
	LogicPanel[3][1] = 4;
	LogicPanel[3][2] = 4;
	LogicPanel[3][3] = 8;
	LogicPanel[4][0] = 9;
	LogicPanel[4][1] = 0;
	LogicPanel[4][2] = 0;
	LogicPanel[4][3] = 10;

}



