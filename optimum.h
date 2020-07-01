#ifndef ZUIYOUJIESHENGCHENG_H
#define ZUIYOUJIESHENGCHENG_H
#include<iostream>
#include<vector>//#include"move函数所在头文件"
#endif

class optimum//最优解
{
	enum name{空=0,曹,关,张,赵,马,黄,兵,卒,丁,勇};//枚举定义:棋子名字,值为1-10
	enum direction{上=0,下,左,右};//枚举定义:移动方向,值为0-3

	std::vector<name> nametable;//要移动棋子的记录表格
	std::vector<direction> dirtable;//移动方向的记录表格
	int step;//最优解的移动步数
	optimum(int n);//构造函数:用于在对象中生成以上两个表格，参数为关卡序号1-5

	void movebyoptimum(void)const;//主体函数:根据预先录入的最优解移动棋子至通关（不包含对棋盘的初始化）
	//void optimumsave(void)const;//预留函数:生成并保存一份最优解副本，用于实现提示功能（暂不使用）

	friend void movewhichwhere(name n,direction d);//友元函数:通过传入的name和direction分析调用哪个move函数
};
//构造函数初始化
optimum::optimum(int n){
	nametable.clear();
	dirtable.clear();
	name Stage1_Name[48] = {
		关,赵,黄,勇,勇,卒,卒,曹,丁,丁,马,张,关,赵,赵,黄,勇,卒,曹,丁,
		丁,兵,兵,马,张,关,赵,黄,黄,勇,卒,曹,张,张,关,赵,黄,勇,勇,卒,
		卒,曹,赵,赵,黄,卒,卒,曹 };
	direction Stage1_Dir[48] = {
		左,下,下,下,左,下,下,右,右,上,上,上,上,左,左,下,下,下,下,右,
		右,右,右,上,上,上,上,左,左,下,下,下,右,右,上,上,上,左,左,左,
		左,下,右,右,上,上,左,左 };
	//《过五关》37步

	name Stage2_Name[59] = {
		赵,黄,马,丁,丁,兵,兵,曹,勇,勇,关,丁,丁,兵,兵,曹,勇,勇,卒,卒,
		关,兵,兵,曹,黄,马,张,赵,丁,丁,兵,兵,曹,黄,马,张,赵,兵,兵,曹,
		关,卒,卒,勇,勇,马,黄,张,赵,兵,兵,丁,丁,曹,张,赵,丁,丁,曹 };
	direction Stage2_Dir[59] = {
		右,下,下,下,右,下,下,左,左,上,上,右,右,右,右,下,左,左,左,左,
		上,上,右,右,上,左,左,左,下,下,下,下,右,右,上,左,左,左,下,下,
		下,右,右,右,右,上,上,上,上,左,左,左,左,下,右,上,上,左,左 };
	//《层层设防》44步

	name Stage3_Name[88] = {
		兵,丁,关,勇,卒,赵,赵,曹,张,兵,兵,丁,丁,黄,张,曹,赵,马,勇,勇,
		卒,卒,关,关,黄,张,勇,勇,曹,兵,兵,丁,丁,勇,勇,黄,黄,张,卒,卒,
		曹,兵,兵,赵,马,马,曹,兵,兵,丁,勇,黄,张,卒,兵,曹,马,马,赵,勇,
		丁,黄,张,张,曹,丁,丁,勇,勇,赵,马,马,丁,丁,关,兵,兵,卒,卒,曹,
		勇,勇,丁,丁,关,卒,卒,曹 };
	direction Stage3_Dir[88] = {
		上,上,左,左,下,下,下,右,右,上,上,上,上,左,下,左,上,右,上,上,
		左,上,右,右,下,下,左,左,下,右,右,上,右,上,上,上,上,左,左,下,
		下,下,左,左,上,上,右,下,下,下,右,上,上,左,下,左,下,下,右,右,
		右,右,上,上,左,下,下,下,下,左,上,上,右,上,上,右,右,右,右,下,
		左,左,左,左,上,上,左,右 };
	//《左右布兵》62步

	name Stage4_Name[124] = {
		卒,勇,黄,黄,曹,马,马,丁,丁,关,张,张,黄,卒,勇,丁,兵,关,赵,赵,
		马,曹,卒,卒,丁,丁,兵,兵,关,勇,勇,张,赵,关,兵,兵,关,关,赵,张,
		兵,勇,赵,马,马,曹,丁,丁,关,黄,勇,兵,张,张,马,赵,曹,丁,丁,卒,
		卒,关,勇,勇,曹,马,马,赵,兵,兵,曹,卒,卒,丁,丁,关,关,勇,勇,黄,
		黄,曹,丁,丁,马,赵,赵,丁,丁,马,卒,勇,关,赵,马,曹,黄,黄,关,勇,
		卒,赵,马,马,曹,卒,勇,黄,张,兵,兵,丁,丁,曹,马,赵,关,勇,卒,黄,
		张,丁,丁,曹 };
	direction Stage4_Dir[124] = {
		左,左,下,下,右,上,上,右,上,上,左,左,下,右,下,右,右,右,下,下,
		左,左,上,上,右,上,右,右,上,上,左,右,下,左,左,下,右,右,上,左,
		下,右,右,下,下,左,左,上,上,上,上,上,右,右,下,下,下,左,左,左,
		左,上,上,右,右,上,上,左,左,下,下,下,右,右,下,左,左,上,左,上,
		上,右,下,下,右,上,上,左,下,下,左,下,右,上,左,左,下,下,右,右,
		右,右,上,上,左,下,左,上,上,右,右,右,右,下,下,下,上,上,上,上,
		上,上,右,右 };
	//《插翅难飞》90步

	name Stage5_Name[176] = {
		关,卒,卒,勇,勇,关,卒,勇,黄,马,马,兵,勇,丁,卒,黄,卒,勇,马,卒,
		卒,黄,关,关,丁,丁,兵,兵,张,张,曹,赵,卒,马,勇,丁,兵,张,勇,马,
		卒,赵,曹,勇,勇,张,张,丁,兵,黄,关,卒,卒,赵,赵,曹,勇,张,丁,兵,
		关,卒,赵,马,丁,丁,马,赵,卒,关,兵,张,张,勇,丁,曹,赵,赵,卒,卒,
		关,兵,张,马,卒,赵,赵,曹,丁,丁,马,张,兵,关,赵,卒,曹,丁,丁,勇,
		勇,马,卒,卒,曹,丁,丁,勇,勇,马,马,卒,卒,张,张,兵,兵,黄,关,赵,
		丁,丁,勇,勇,曹,兵,张,卒,马,马,曹,赵,勇,丁,关,关,黄,张,卒,兵,
		赵,勇,勇,曹,马,马,卒,兵,张,赵,黄,关,关,勇,丁,曹,马,兵,兵,卒,
		卒,张,赵,黄,关,勇,勇,丁,丁,曹,黄,黄,关,丁,丁,曹 };
	direction Stage5_Dir[176] = {
		下,左,左,上,左,右,下,左,下,右,右,上,上,上,上,下,右,下,左,右,
		上,上,右,右,下,右,下,下,下,下,左,左,上,右,上,上,右,下,左,左,
		下,右,右,上,上,上,上,左,左,左,左,下,下,下,下,右,右,上,上,上,
		左,左,下,右,右,上,左,上,右,右,下,下,下,左,左,左,上,上,上,上,
		右,右,下,左,左,下,下,右,右,上,上,上,左,左,下,左,下,右,右,右,
		右,上,上,左,左,下,下,右,下,右,右,上,右,上,上,上,上,左,左,左,
		下,下,下,下,右,右,下,下,左,左,上,上,上,上,右,右,下,下,左,上,
		左,左,下,下,右,右,上,上,上,上,上,左,左,下,下,下,下,右,右,右,
		右,上,上,上,上,左,左,左,左,下,右,右,上,上,左,左 };
	//《小燕出巢》131步

	switch (n){
		case 1:
			step = 48;
			for (int i = 0; i < step; ++i) {
				nametable.push_back(Stage1_Name[i]);
				dirtable.push_back(Stage1_Dir[i]);
			}
			break;
		case 2:
			step = 59;
			for (int i = 0; i < step; ++i) {
				nametable.push_back(Stage2_Name[i]);
				dirtable.push_back(Stage2_Dir[i]);
			}
			break;
		case 3:
			step = 88;
			for (int i = 0; i < step; ++i) {
				nametable.push_back(Stage3_Name[i]);
				dirtable.push_back(Stage3_Dir[i]);
			}
			break;
		case 4:
			step = 124;
			for (int i = 0; i < step; ++i) {
				nametable.push_back(Stage4_Name[i]);
				dirtable.push_back(Stage4_Dir[i]);
			}
			break;
		default:
			step = 176;
			for (int i = 0; i < step; ++i) {
				nametable.push_back(Stage5_Name[i]);
				dirtable.push_back(Stage5_Dir[i]);
			}
			break;
	}
}

void optimum::movebyoptimum(void)const
{
	for(int i = 0; i<step; ++i)
	{
		movewhichwhere(nametable[i], dirtable[i]);//移动一次
		//本行留空，请白同学补充“在图形化界面显示移动操作”的函数
	}	
}

/*void optimum::optimumsave(void)const 
{
	for (int i = 0; i < step; ++i) {
		movewhichwhere(nametable[i], dirtable[i]);//移动一次
		//本行留空，用于保存当前棋盘状态
	}
}
*/

void movewhichwhere(optimum::name n,optimum::direction d)
{
	int i;

	if		(n == optimum::曹)	i = 1;//将name类型的n转化为int类型
	else if (n == optimum::关)	i = 2;
	else if (n == optimum::张)	i = 3;
	else if (n == optimum::赵)	i = 4;
	else if (n == optimum::马)	i = 5;
	else if (n == optimum::黄)	i = 6;
	else if (n == optimum::兵)	i = 7;
	else if (n == optimum::卒)	i = 8;
	else if (n == optimum::丁)	i = 9;
	else						i = 10;
	//等待设定移动函数同学补充
	//假定对象指针的名字为  role[i],i∈[1,10];//用direction类型的d选择执行的移动
	if		(d == optimum::上)		role[i]->move_up();
	else if	(d == optimum::下)		role[i]->move_down();
	else if	(d == optimum::左)		role[i]->move_left();
	else if	(d == optimum::右)		role[i]->move_right();
	
}
