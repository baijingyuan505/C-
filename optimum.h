#ifndef OPTIMUM_H
#define OPTIMUM_H
#include<iostream>
#include<vector>//#include"move函数所在头文件"
#endif

class optimum//最优解
{
public:
	int counter = 0;//计数器
	std::vector<int> nametable;//要移动棋子的记录表格
	std::vector<int> dirtable;//移动方向的记录表格
	int step = 0;//最优解的移动步数

	void Init(int n);//构造函数:生成以上3个成员变量，参数为关卡序号1-5

	int moveRole();
	int moveDir();

};