#ifndef OPTIMUM_H
#define OPTIMUM_H
#include<iostream>
#include<vector>//#include"move函数所在头文件"
#endif
enum name { 空 = 0, 曹, 关, 赵, 马, 黄, 张, 兵, 卒, 丁, 勇 };//枚举定义:棋子名字,值为1-10
enum dir { 上 = 0, 下, 左, 右 };//枚举定义:移动方向,值为0-3


class optimum//最优解
{
public:

	std::vector<name> nametable;//要移动棋子的记录表格
	std::vector<dir> dirtable;//移动方向的记录表格
	int step=0;//最优解的移动步数
	optimum(int n);//构造函数:生成以上3个成员变量，参数为关卡序号1-5

	//void movebyoptimum(Role* CaoCao, Role* GuanYu, Role* ZhaoYun, Role* MaChao, Role* HuangZhong, Role* ZhangFei, Role* S1, Role* S2, Role* S3, Role* S4)const;
	//可能没用的函数

};



/*void optimum::movebyoptimum(Role* CaoCao, Role* GuanYu, Role* ZhaoYun, Role* MaChao, Role* HuangZhong, Role* ZhangFei, Role* S1, Role* S2, Role* S3, Role* S4)const
{
	for (int i = 0; i < step; ++i)
	{
		movewhichwhere(nametable[i], dirtable[i], CaoCao, GuanYu, ZhaoYun, MaChao, HuangZhong, ZhangFei, S1, S2, S3, S4);//移动一次
		//本行留空，请补充“在图形化界面显示移动操作”的函数
	}
}*/

//movewhichwhere(route.nametable[i], route.dirtable[i], CaoCao, GuanYu, ZhaoYun, MaChao, HuangZhong, ZhangFei, S1, S2, S3, S4);//调用示例
