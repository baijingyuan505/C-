#ifndef OPTIMUM_H
#define OPTIMUM_H
#include<iostream>
#include<vector>//#include"move函数所在头文件"
#endif

class optimum//最优解
{
	enum class name { 空 = 0, 曹, 关, 赵, 马, 黄, 张, 兵, 卒, 丁, 勇 };//枚举定义:棋子名字,值为1-10
	enum class dir { 上 = 0, 下, 左, 右 };//枚举定义:移动方向,值为0-3

	std::vector<name> nametable;//要移动棋子的记录表格
	std::vector<dir> dirtable;//移动方向的记录表格
	int step;//最优解的移动步数
	optimum(int n);//构造函数:生成以上3个成员变量，参数为关卡序号1-5

	void movebyoptimum(void)const;//主体函数:根据预先录入的最优解移动棋子至通关（不包含对棋盘的初始化）用于实现最优解演示功能
	//void optimumsave(void)const;//预留函数:生成并保存一份最优解副本，用于实现提示功能

	friend void movewhichwhere(name n, dir d);//友元函数:通过n和d分析如何调用move函数，用于实现最优解演示、提示功能
};

optimum::optimum(int n) {
	nametable.clear();
	dirtable.clear();

	//记录了最优解操作的表，格式为每20个操作单字换一行，即一行20个元素
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

	switch (n) {//构造函数的主体部分
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
	case 5:
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
		//本行留空，请补充“在图形化界面显示移动操作”的函数
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
	switch (n)
	{
		int i = static_cast<int>(n);
	case optimum::name::曹:
		if (d == optimum::dir::上)			CaoCao->move(i, CaoCao->x, (CaoCao->y - 1));
		else if (d == optimum::dir::下)		CaoCao->move(i, CaoCao->x, (CaoCao->y + 1));
		else if (d == optimum::dir::左)		CaoCao->move(i, (CaoCao->x - 1), CaoCao->y);
		else					/*右*/		CaoCao->move(i, (CaoCao->x + 1), CaoCao->y);
		break;
	case optimum::name::关:
		if (d == optimum::dir::上)			GuanYu->move(i, GuanYu->x, (GuanYu->y - 1));
		else if (d == optimum::dir::下)		GuanYu->move(i, GuanYu->x, (GuanYu->y + 1));
		else if (d == optimum::dir::左)		GuanYu->move(i, (GuanYu->x - 1), GuanYu->y);
		else					/*右*/		GuanYu->move(i, (GuanYu->x + 1), GuanYu->y);
		break;
	case optimum::name::赵:
		if (d == optimum::dir::上)			ZhaoYun->move(i, ZhaoYun->x, (ZhaoYun->y - 1));
		else if (d == optimum::dir::下)		ZhaoYun->move(i, ZhaoYun->x, (ZhaoYun->y + 1));
		else if (d == optimum::dir::左)		ZhaoYun->move(i, (ZhaoYun->x - 1), ZhaoYun->y);
		else					/*右*/		ZhaoYun->move(i, (ZhaoYun->x + 1), ZhaoYun->y);
		break;
	case optimum::name::马:
		if (d == optimum::dir::上)			MaChao->move(i, MaChao->x, (MaChao->y - 1));
		else if (d == optimum::dir::下)		MaChao->move(i, MaChao->x, (MaChao->y + 1));
		else if (d == optimum::dir::左)		MaChao->move(i, (MaChao->x - 1), MaChao->y);
		else					/*右*/		MaChao->move(i, (MaChao->x + 1), MaChao->y);
		break;
	case optimum::name::黄:
		if (d == optimum::dir::上)			HuangZhong->move(i, HuangZhong->x, (HuangZhong->y - 1));
		else if (d == optimum::dir::下)		HuangZhong->move(i, HuangZhong->x, (HuangZhong->y + 1));
		else if (d == optimum::dir::左)		HuangZhong->move(i, (HuangZhong->x - 1), HuangZhong->y);
		else					/*右*/		HuangZhong->move(i, (HuangZhong->x + 1), HuangZhong->y);
		break;
	case optimum::name::张:
		if (d == optimum::dir::上)			ZhangFei->move(i, ZhangFei->x, (ZhangFei->y - 1));
		else if (d == optimum::dir::下)		ZhangFei->move(i, ZhangFei->x, (ZhangFei->y + 1));
		else if (d == optimum::dir::左)		ZhangFei->move(i, (ZhangFei->x - 1), ZhangFei->y);
		else					/*右*/		ZhangFei->move(i, (ZhangFei->x + 1), ZhangFei->y);
		break;
	case optimum::name::兵:
		if (d == optimum::dir::上)			S1->move(i, S1->x, (S1->y - 1));
		else if (d == optimum::dir::下)		S1->move(i, S1->x, (S1->y + 1));
		else if (d == optimum::dir::左)		S1->move(i, (S1->x - 1), S1->y);
		else					/*右*/		S1->move(i, (S1->x + 1), S1->y);
		break;
	case optimum::name::卒:
		if (d == optimum::dir::上)			S2->move(i, S2->x, (S2->y - 1));
		else if (d == optimum::dir::下)		S2->move(i, S2->x, (S2->y + 1));
		else if (d == optimum::dir::左)		S2->move(i, (S2->x - 1), S2->y);
		else					/*右*/		S2->move(i, (S2->x + 1), S2->y);
		break;
	case optimum::name::丁:
		if (d == optimum::dir::上)			S3->move(i, S3->x, (S3->y - 1));
		else if (d == optimum::dir::下)		S3->move(i, S3->x, (S3->y + 1));
		else if (d == optimum::dir::左)		S3->move(i, (S3->x - 1), S3->y);
		else					/*右*/		S3->move(i, (S3->x + 1), S3->y);
		break;
	case optimum::name::勇:
		if (d == optimum::dir::上)			S4->move(i, S4->x, (S4->y - 1));
		else if (d == optimum::dir::下)		S4->move(i, S4->x, (S4->y + 1));
		else if (d == optimum::dir::左)		S4->move(i, (S4->x - 1), S4->y);
		else					/*右*/		S4->move(i, (S4->x + 1), S4->y);
		break;
	}
}
