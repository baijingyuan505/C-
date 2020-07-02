#include"Role.h"
#include"Stage.h"
#include"Sound.h"
#include "optimum.h"
#include "Interface.h"
#include "Logic.h"
#include<iostream>

void end();//结束函数

int main()
{
	Role* CaoCao;
	Role* ZhangFei;
	Role* ZhaoYun;
	Role* GuanYu;
	Role* MaChao;
	Role* HuangZhong;
	Role* S1;
	Role* S2;
	Role* S3;
	Role* S4;
	Stage level;//

	Interface scene;

	Interface::Option operation;//枚举 选择的操作

	string code;//帮助提示的代号
	int logicx, logicy;//点击的点的逻辑坐标（不是左上角）
	int stage;//关卡号

	scene.Begin();//开始界面
	stage = scene.Select();//选关界面
	switch (stage)
	{//根据选择的关卡对角色进行实例化：棋子的代号，棋子初始x，初始y坐标
	case 1:
	{
		CaoCao = new Boss{ 1,1,0 };
		GuanYu = new General_1{ 2, 1, 4 };
		ZhaoYun = new General_1{ 3, 2, 3 };
		MaChao = new General_1{ 4, 0, 2 };
		HuangZhong = new General_1{ 5, 2, 2 };
		ZhangFei = new General_1{ 6, 0, 3 };
		S1 = new Soldier{ 7 ,0,0 };
		S2 = new Soldier{ 8 ,3,0 };
		S3 = new Soldier{ 9 ,0,1 };
		S4 = new Soldier{ 10,3,1 };
		level.Stage1();
		break;
	}

	case 2:
	{
		CaoCao = new Boss{ 1,1,0 };
		GuanYu = new General_1{ 2, 2, 2 };
		ZhaoYun = new General_1{ 3, 1, 4 };
		MaChao = new General_2{ 4, 1, 2 };
		HuangZhong = new General_2{ 5, 0, 2 };
		ZhangFei = new General_1{ 6, 2, 3 };
		S1 = new Soldier{ 7 ,0,0 };
		S2 = new Soldier{ 8 ,3,0 };
		S3 = new Soldier{ 9 ,0,1 };
		S4 = new Soldier{ 10,3,1 };
		level.Stage2();


		break;
	}

	case 3:
	{
		CaoCao = new Boss{ 1,1,0 };
		GuanYu = new General_1{ 2, 1, 4 };
		ZhaoYun = new General_2{ 3, 3, 0 };
		MaChao = new General_2{ 4, 2, 2 };
		HuangZhong = new General_2{ 5, 1, 2 };
		ZhangFei = new General_2{ 6, 0, 0 };
		S1 = new Soldier{ 7 ,0,3 };
		S2 = new Soldier{ 8 ,3,3 };
		S3 = new Soldier{ 9 ,0,4 };
		S4 = new Soldier{ 10,3,4 };
		level.Stage3();


		break;
	}

	case 4:
	{
		CaoCao = new Boss{ 1,1,0 };
		GuanYu = new General_1{ 2, 0, 4 };
		ZhaoYun = new General_2{ 3, 0, 0 };
		MaChao = new General_2{ 4, 1, 2 };
		HuangZhong = new General_2{ 5, 3, 0 };
		ZhangFei = new General_1{ 6, 2, 4 };
		S1 = new Soldier{ 7 ,0,2 };
		S2 = new Soldier{ 8 ,3,2 };
		S3 = new Soldier{ 9 ,0,3 };
		S4 = new Soldier{ 10,3,3 };
		level.Stage4();


		break;
	}

	case 5:
	{
		CaoCao = new Boss{ 1,1,0 };
		GuanYu = new General_1{ 2, 1, 3 };
		ZhaoYun = new General_2{ 3, 3, 0 };
		MaChao = new General_1{ 4, 0, 2 };
		HuangZhong = new General_1{ 5, 2, 2 };
		ZhangFei = new General_2{ 6, 0, 3 };
		S1 = new Soldier{ 7 ,0,0 };
		S2 = new Soldier{ 8 ,3,0 };
		S3 = new Soldier{ 9 ,0,1 };
		S4 = new Soldier{ 10,3,1 };
		level.Stage5();


		break;
	}
	}

	//选关后初始化
	optimum route(stage);
    const int steps = route.step;
	Logic<steps> logic;//待调试
	//logic.Load(static_cast<int>(route.nametable), static_cast<int>(route.dirtable));
	logic.Load(route.nametable, route.dirtable);//类型转化 问王磊
	scene.GameInit(stage);//棋盘初始化
	while (true) {//正式游戏
		operation=scene.Click();
		switch (operation) {
		case Interface::Option::move:
			logicx = scene.MovePoint.x - 1;
			logicy = scene.MovePoint.y - 1;
			//接口,待实现
			//第一次点击棋盘的逻辑坐标
			//
			break;
		case Interface::Option::help:
			code=logic.Help();
			scene.Help(code);//帮助功能发现bug,等我明天修改
			break;
		case Interface::Option::revoke:
			if (logic.Revoke())
				scene.Revoke();//回退功能完整
			break;
		case Interface::Option::music:
			//音乐的接口
			//设想的是先点击环境，再弹出三个音乐的选项
		case Interface::Option::exit:
			//具体的退出操作
		}
		if (logic.Examine())
			scene.UselesStep();
		//需要记录这一步走的角色和方向
		logic.Record(3, 2);//调用示例
		logic.Value();
		scene.stepwrite(logic.Cnt);
		scene.lifewrite(logic.score);
	}


}

void end()//结束游戏后调用的函数
{
	/*
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

	*/
}