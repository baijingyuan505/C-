#ifndef OPTIMUM_H
#define OPTIMUM_H
#include<iostream>
#include<vector>//#include"move函数所在头文件"
#endif

class optimum//最优解
{
	enum class name { 空 = 0, 曹, 关, 张, 赵, 马, 黄, 兵, 卒, 丁, 勇 };//枚举定义:棋子名字,值为1-10
	//enum class name { 空 = 0, 曹, 关, 赵, 马, 黄, 张, 兵, 卒, 丁, 勇 };//按照关赵马黄张顺序定义的enum表
	enum class dir { 上 = 0, 下, 左, 右 };//枚举定义:移动方向,值为0-3

	std::vector<name> nametable;//要移动棋子的记录表格
	std::vector<dir> dirtable;//移动方向的记录表格
	int step;//最优解的移动步数
	optimum(int n);//构造函数:用于在对象中生成以上两个表格，参数为关卡序号1-5

	void movebyoptimum(void)const;//主体函数:根据预先录入的最优解移动棋子至通关（不包含对棋盘的初始化）
	//void optimumsave(void)const;//预留函数:生成并保存一份最优解副本，用于实现提示功能（暂不使用）

	friend void movewhichwhere(name n, dir d);//友元函数:通过传入的name和dir分析调用哪个move函数
};
//构造函数初始化
optimum::optimum(int n) {
	nametable.clear();
	dirtable.clear();

	//最优解操作的记录表，格式为每20个操作单字换一行，即一行20个元素
	name Stage1_Name[48] = {
		name::关,name::赵,name::黄,name::勇,name::勇,name::卒,name::卒,name::曹,name::丁,name::丁,name::马,name::张,name::关,name::赵,name::赵,name::黄,name::勇,name::卒,name::曹,name::丁,
		name::丁,name::兵,name::兵,name::马,name::张,name::关,name::赵,name::黄,name::黄,name::勇,name::卒,name::曹,name::张,name::张,name::关,name::赵,name::黄,name::勇,name::勇,name::卒,
		name::卒,name::曹,name::赵,name::赵,name::黄,name::卒,name::卒,name::曹 };
	dir Stage1_Dir[48] = {
		dir::左,dir::下,dir::下,dir::下,dir::左,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::下,dir::下,dir::右,
		dir::右,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::左,dir::左,dir::左,
		dir::左,dir::下,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左 };
	//《过五关》37步

	name Stage2_Name[62] = {
		name::赵,name::黄,name::马,name::丁,name::丁,name::兵,name::兵,name::曹,name::勇,name::勇,name::关,name::丁,name::丁,name::兵,name::兵,name::曹,name::勇,name::勇,name::卒,name::卒,
		name::关,name::兵,name::兵,name::曹,name::黄,name::黄,name::马,name::张,name::赵,name::丁,name::丁,name::兵,name::兵,name::曹,name::黄,name::马,name::马,name::张,name::赵,name::兵,
		name::兵,name::曹,name::关,name::卒,name::卒,name::勇,name::勇,name::马,name::黄,name::张,name::赵,name::兵,name::兵,name::丁,name::丁,name::曹,name::张,name::张,name::赵,name::丁,
		name::丁,name::曹 };
	dir Stage2_Dir[62] = {
		dir::右,dir::下,dir::下,dir::下,dir::右,dir::下,dir::下,dir::左,dir::左,dir::上,dir::上,dir::右,dir::右,dir::右,dir::右,dir::下,dir::左,dir::左,dir::左,dir::左,
		dir::上,dir::上,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左,dir::左,dir::下,dir::下,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左,dir::左,
		dir::下,dir::下,dir::下,dir::右,dir::右,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::左,dir::左,dir::下,dir::右,dir::上,dir::上,dir::上,
		dir::左,dir::左 };
	//《层层设防》44步
	//修改内容（注意，行列号均从1开始计，列号可能有偏差但不影响）：
	//原第2行第5列“黄上”操作从执行一次改为执行两次
	//原第2行第15列“马上”操作从执行一次改为执行两次
	//原第3行第15列“张右”操作从执行一次改为执行两次

	name Stage3_Name[90] = {
		name::兵,name::丁,name::关,name::勇,name::卒,name::赵,name::赵,name::曹,name::张,name::兵,name::兵,name::丁,name::丁,name::黄,name::张,name::张,name::曹,name::赵,name::赵,name::马,
		name::勇,name::勇,name::卒,name::卒,name::关,name::关,name::黄,name::张,name::勇,name::勇,name::曹,name::兵,name::兵,name::丁,name::丁,name::勇,name::勇,name::黄,name::黄,name::张,
		name::卒,name::卒,name::曹,name::兵,name::兵,name::赵,name::马,name::马,name::曹,name::兵,name::兵,name::丁,name::勇,name::黄,name::张,name::卒,name::兵,name::曹,name::马,name::马,
		name::赵,name::勇,name::丁,name::黄,name::张,name::张,name::曹,name::丁,name::丁,name::勇,name::勇,name::赵,name::马,name::马,name::丁,name::丁,name::关,name::兵,name::兵,name::卒,
		name::卒,name::曹,name::勇,name::勇,name::丁,name::丁,name::关,name::卒,name::卒,name::曹 };
	dir Stage3_Dir[90] = {
		dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::下,dir::下,dir::左,dir::上,dir::上,dir::右,
		dir::上,dir::上,dir::左,dir::上,dir::右,dir::右,dir::下,dir::下,dir::左,dir::左,dir::下,dir::右,dir::右,dir::上,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,
		dir::左,dir::下,dir::下,dir::下,dir::左,dir::左,dir::上,dir::上,dir::右,dir::下,dir::下,dir::下,dir::右,dir::上,dir::上,dir::左,dir::下,dir::左,dir::下,dir::下,
		dir::右,dir::右,dir::右,dir::右,dir::上,dir::上,dir::左,dir::下,dir::下,dir::下,dir::下,dir::左,dir::上,dir::上,dir::右,dir::上,dir::上,dir::右,dir::右,dir::右,
		dir::右,dir::下,dir::左,dir::左,dir::左,dir::左,dir::上,dir::上,dir::右,dir::右 };
	//《左右布兵》62步
	//修改内容（注意，行列号均从1开始计，列号可能有偏差但不影响）：
	//原第1行第15列“张下”操作从执行一次改为执行两次
	//原第2行第17列“赵上”操作从执行一次改为执行两次
	//原第5行第7列“卒左”操作改为“卒右”

	name Stage4_Name[125] = {
		name::卒,name::勇,name::黄,name::黄,name::曹,name::马,name::马,name::丁,name::丁,name::关,name::张,name::张,name::黄,name::卒,name::勇,name::丁,name::兵,name::关,name::赵,name::赵,
		name::马,name::曹,name::卒,name::卒,name::丁,name::丁,name::兵,name::兵,name::关,name::勇,name::勇,name::张,name::赵,name::关,name::兵,name::兵,name::关,name::关,name::赵,name::张,
		name::兵,name::勇,name::赵,name::马,name::马,name::曹,name::丁,name::丁,name::关,name::黄,name::勇,name::兵,name::张,name::张,name::马,name::赵,name::曹,name::丁,name::丁,name::卒,
		name::卒,name::关,name::勇,name::勇,name::曹,name::马,name::马,name::赵,name::兵,name::兵,name::曹,name::卒,name::卒,name::丁,name::丁,name::关,name::关,name::勇,name::勇,name::黄,
		name::黄,name::曹,name::丁,name::丁,name::马,name::赵,name::赵,name::丁,name::丁,name::马,name::卒,name::勇,name::关,name::赵,name::马,name::曹,name::黄,name::黄,name::关,name::勇,
		name::卒,name::赵,name::马,name::马,name::曹,name::卒,name::勇,name::黄,name::张,name::兵,name::兵,name::丁,name::丁,name::曹,name::马,name::赵,name::关,name::关,name::勇,name::卒,
		name::黄,name::张,name::丁,name::丁,name::曹 };
	dir Stage4_Dir[125] = {
		dir::左,dir::左,dir::下,dir::下,dir::右,dir::上,dir::上,dir::右,dir::上,dir::上,dir::左,dir::左,dir::下,dir::右,dir::下,dir::右,dir::右,dir::右,dir::下,dir::下,
		dir::左,dir::左,dir::上,dir::上,dir::右,dir::上,dir::右,dir::右,dir::上,dir::上,dir::左,dir::右,dir::下,dir::左,dir::左,dir::下,dir::右,dir::右,dir::上,dir::左,
		dir::下,dir::右,dir::右,dir::下,dir::下,dir::左,dir::左,dir::上,dir::上,dir::上,dir::上,dir::上,dir::右,dir::右,dir::下,dir::下,dir::下,dir::左,dir::左,dir::左,
		dir::左,dir::上,dir::上,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::下,dir::右,dir::右,dir::下,dir::左,dir::左,dir::上,dir::左,dir::上,
		dir::上,dir::右,dir::下,dir::下,dir::右,dir::上,dir::上,dir::左,dir::下,dir::下,dir::左,dir::下,dir::右,dir::上,dir::左,dir::左,dir::下,dir::下,dir::右,dir::右,
		dir::右,dir::右,dir::上,dir::上,dir::左,dir::下,dir::左,dir::上,dir::上,dir::右,dir::右,dir::右,dir::右,dir::下,dir::下,dir::下,dir::左,dir::左,dir::上,dir::上,
		dir::上,dir::上,dir::上,dir::右,dir::右 };
	//《插翅难飞》90步
	//修改内容（注意，行列号均从1开始计，列号可能有偏差但不影响）：
	//原第6行第17列“关上”操作改为“关左”操作，这个“关左”执行两次

	name Stage5_Name[178] = {
		name::关,name::卒,name::卒,name::勇,name::勇,name::关,name::卒,name::勇,name::黄,name::马,name::马,name::兵,name::勇,name::丁,name::卒,name::关,name::关,name::黄,name::卒,name::勇,
		name::马,name::卒,name::卒,name::黄,name::关,name::关,name::丁,name::丁,name::兵,name::兵,name::张,name::张,name::曹,name::赵,name::卒,name::马,name::勇,name::丁,name::兵,name::张,
		name::勇,name::马,name::卒,name::赵,name::曹,name::勇,name::勇,name::张,name::张,name::丁,name::兵,name::黄,name::关,name::卒,name::卒,name::赵,name::赵,name::曹,name::勇,name::张,
		name::丁,name::兵,name::关,name::卒,name::赵,name::马,name::丁,name::丁,name::马,name::赵,name::卒,name::关,name::兵,name::张,name::张,name::勇,name::丁,name::曹,name::赵,name::赵,
		name::卒,name::卒,name::关,name::兵,name::张,name::马,name::卒,name::赵,name::赵,name::曹,name::丁,name::丁,name::马,name::张,name::兵,name::关,name::赵,name::卒,name::曹,name::丁,
		name::丁,name::勇,name::勇,name::马,name::卒,name::卒,name::曹,name::丁,name::丁,name::勇,name::勇,name::马,name::马,name::卒,name::卒,name::张,name::张,name::兵,name::兵,name::黄,
		name::关,name::赵,name::丁,name::丁,name::勇,name::勇,name::曹,name::兵,name::张,name::卒,name::马,name::马,name::曹,name::赵,name::勇,name::丁,name::关,name::关,name::黄,name::张,
		name::卒,name::兵,name::赵,name::勇,name::勇,name::曹,name::马,name::马,name::卒,name::兵,name::张,name::赵,name::黄,name::关,name::关,name::勇,name::丁,name::曹,name::马,name::兵,
		name::兵,name::卒,name::卒,name::张,name::赵,name::黄,name::关,name::勇,name::勇,name::丁,name::丁,name::曹,name::黄,name::黄,name::关,name::丁,name::丁,name::曹 };
	dir Stage5_Dir[178] = {
		dir::下,dir::左,dir::左,dir::上,dir::左,dir::右,dir::下,dir::左,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::下,dir::右,dir::下,
		dir::左,dir::右,dir::上,dir::上,dir::右,dir::右,dir::下,dir::右,dir::下,dir::下,dir::下,dir::下,dir::左,dir::左,dir::上,dir::右,dir::上,dir::上,dir::右,dir::下,
		dir::左,dir::左,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::左,dir::左,dir::下,dir::下,dir::下,dir::下,dir::右,dir::右,dir::上,
		dir::上,dir::上,dir::左,dir::左,dir::下,dir::右,dir::右,dir::上,dir::左,dir::上,dir::右,dir::右,dir::下,dir::下,dir::下,dir::左,dir::左,dir::左,dir::上,dir::上,
		dir::上,dir::上,dir::右,dir::右,dir::下,dir::左,dir::左,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::左,dir::左,dir::下,dir::左,dir::下,dir::右,
		dir::右,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::右,dir::下,dir::右,dir::右,dir::上,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,
		dir::左,dir::左,dir::下,dir::下,dir::下,dir::下,dir::右,dir::右,dir::下,dir::下,dir::左,dir::左,dir::上,dir::上,dir::上,dir::上,dir::右,dir::右,dir::下,dir::下,
		dir::左,dir::上,dir::左,dir::左,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::下,dir::下,dir::右,
		dir::右,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::左,dir::左,dir::下,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左 };
	//《小燕出巢》131步
	//修改内容（注意，行列号均从1开始计，列号可能有偏差但不影响）：
	//原第1行第16列“黄下”操作前增加“关左”操作，这个关左执行两次

	switch (n) {
	case 1:
		step = 48;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage1_Name[i]);
			dirtable.push_back(Stage1_Dir[i]);
		}
		break;
	case 2:
		step = 62;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage2_Name[i]);
			dirtable.push_back(Stage2_Dir[i]);
		}
		break;
	case 3:
		step = 90;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage3_Name[i]);
			dirtable.push_back(Stage3_Dir[i]);
		}
		break;
	case 4:
		step = 125;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage4_Name[i]);
			dirtable.push_back(Stage4_Dir[i]);
		}
		break;
	default:
		step = 178;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage5_Name[i]);
			dirtable.push_back(Stage5_Dir[i]);
		}
		break;
	}
}

void optimum::movebyoptimum(void)const
{
	for (int i = 0; i < step; ++i)
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

void movewhichwhere(optimum::name n, optimum::dir d)
{
	int i=static_cast<int>(n);

	//等待设定移动函数同学补充
	//假定对象指针的名字为  role[i],i∈[1,10];//用dir类型的d选择执行的移动
	if (d == optimum::dir::上)			role[i]->move_up();
	else if (d == optimum::dir::下)		role[i]->move_down();
	else if (d == optimum::dir::左)		role[i]->move_left();
	else if (d == optimum::dir::右)		role[i]->move_right();

}
