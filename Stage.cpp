#include"Stage.h"
#include"Role.h"
#include<iostream>

//Stage.h/cpp文件用于逻辑棋盘的初始化,以及结束函数
/*
State表示这一格属于谁:
0=空 1=曹操 2=关 3=赵 4=马 5=黄 6=张 7~10=小兵1~4
General1为横条 2为竖条
*/
//以下是每一关的逻辑棋盘初始化.
void Stage::Stage1()
{

	LogicPanel[0][0] = 7;
	LogicPanel[1][0] = 1;
	LogicPanel[2][0] = 1;
	LogicPanel[3][0] = 8;
	LogicPanel[0][1] = 9;
	LogicPanel[1][1] = 1;
	LogicPanel[2][1] = 1;
	LogicPanel[3][1] = 10;
	LogicPanel[0][2] = 4;
	LogicPanel[1][2] = 4;
	LogicPanel[2][2] = 5;
	LogicPanel[3][2] = 5;
	LogicPanel[0][3] = 6;
	LogicPanel[1][3] = 6;
	LogicPanel[2][3] = 3;
	LogicPanel[3][3] = 3;
	LogicPanel[0][4] = 0;
	LogicPanel[1][4] = 2;
	LogicPanel[2][4] = 2;
	LogicPanel[3][4] = 0;


}

void Stage::Stage2()
{
	
	LogicPanel[0][0] = 7;
	LogicPanel[1][0] = 1;
	LogicPanel[2][0] = 1;
	LogicPanel[3][0] = 8;
	LogicPanel[0][1] = 9;
	LogicPanel[1][1] = 1;
	LogicPanel[2][1] = 1;
	LogicPanel[3][1] = 10;
	LogicPanel[0][2] = 5;
	LogicPanel[1][2] = 4;
	LogicPanel[2][2] = 2;
	LogicPanel[3][2] = 2;
	LogicPanel[0][3] = 5;
	LogicPanel[1][3] = 4;
	LogicPanel[2][3] = 6;
	LogicPanel[3][3] = 6;
	LogicPanel[0][4] = 0;
	LogicPanel[1][4] = 3;
	LogicPanel[2][4] = 3;
	LogicPanel[3][4] = 0;

}

void Stage::Stage3()
{
	
	LogicPanel[0][0] = 6;
	LogicPanel[1][0] = 1;
	LogicPanel[2][0] = 1;
	LogicPanel[3][0] = 3;
	LogicPanel[0][1] = 6;
	LogicPanel[1][1] = 1;
	LogicPanel[2][1] = 1;
	LogicPanel[3][1] = 3;
	LogicPanel[0][2] = 0;
	LogicPanel[1][2] = 5;
	LogicPanel[2][2] = 4;
	LogicPanel[3][2] = 0;
	LogicPanel[0][3] = 7;
	LogicPanel[1][3] = 5;
	LogicPanel[2][3] = 4;
	LogicPanel[3][3] = 8;
	LogicPanel[0][4] = 9;
	LogicPanel[1][4] = 2;
	LogicPanel[2][4] = 2;
	LogicPanel[3][4] = 10;

}

void Stage::Stage4()
{
	
	LogicPanel[0][0] = 3;
	LogicPanel[1][0] = 1;
	LogicPanel[2][0] = 1;
	LogicPanel[3][0] = 5;
	LogicPanel[0][1] = 3;
	LogicPanel[1][1] = 1;
	LogicPanel[2][1] = 1;
	LogicPanel[3][1] = 5;
	LogicPanel[0][2] = 7;
	LogicPanel[1][2] = 4;
	LogicPanel[2][2] = 0;
	LogicPanel[3][2] = 8;
	LogicPanel[0][3] = 9;
	LogicPanel[1][3] = 4;
	LogicPanel[2][3] = 0;
	LogicPanel[3][3] = 10;
	LogicPanel[0][4] = 2;
	LogicPanel[1][4] = 2;
	LogicPanel[2][4] = 6;
	LogicPanel[3][4] = 6;

}

void Stage::Stage5()
{
	
	LogicPanel[0][0] = 6;
	LogicPanel[1][0] = 1;
	LogicPanel[2][0] = 1;
	LogicPanel[3][0] = 3;
	LogicPanel[0][1] = 6;
	LogicPanel[1][1] = 1;
	LogicPanel[2][1] = 1;
	LogicPanel[3][1] = 3;
	LogicPanel[0][2] = 4;
	LogicPanel[1][2] = 4;
	LogicPanel[2][2] = 5;
	LogicPanel[3][2] = 5;
	LogicPanel[0][3] = 7;
	LogicPanel[1][3] = 2;
	LogicPanel[2][3] = 2;
	LogicPanel[3][3] = 8;
	LogicPanel[0][4] = 9;
	LogicPanel[1][4] = 0;
	LogicPanel[2][4] = 0;
	LogicPanel[3][4] = 10;

}

void end()//结束游戏后调用的函数
{
	delete CaoCao;
	delete ZhangFei;
	delete ZhaoYun;
	delete GuanYu;
	delete MaChao;
	delete HuangZhong;
	delete S1;
	delete S2;
	delete S3;
	delete S4;//删除new出来的对象

	//接下来显示选关界面(图形化界面的内容)
}


