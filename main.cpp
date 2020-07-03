#include"Stage.h"
#include "Role.h"
#include "Interface.h"
#include "Logic.h"
#include<iostream>
int LogicPanel[5][4] = { 0 };

int main()
{
	Role* roles[10];
	Stage level;//

	Interface scene;

	Interface::Option operation;//枚举 选择的操作

	int RoleCode = 0, DirCode=0;
	Role::move_result moveCode;
	//代号
	int code;//帮助提示的代号
	int logicx, logicy;//点击的点的逻辑坐标（不是左上角）
	int stage;//关卡号

	scene.Begin();//开始界面
	stage = scene.Select();//选关界面
	
	int  InitBoss[5][2] = { {1,0},{1,0},{1,0},{1,0},{1,0} };
	int  InitGeneral[5][5][3] = {
	{ {1,0,3}, {1,2,3}, {2,0,0}, {1,2,4}, {2,0,3} },
	{ {1,2,3}, {1,1,4}, {2,3,0}, {2,0,0}, {2,3,0} },
	{ {1,1,4}, {1,2,2}, {1,1,4}, {1,0,4}, {1,1,3} },
	{ {1,0,2}, {2,1,2}, {2,2,2}, {2,1,2}, {1,0,2} },
	{ {1,2,2}, {2,0,2}, {2,1,2}, {2,3,0}, {1,2,2} } };
	int InitSoldier[4][5][3] = {
	{ {0,0}, {0,0}, {0,3}, {0,2}, {0,0} },
	{ {3,0}, {3,0}, {3,3}, {3,2}, {3,0} },
	{ {0,1}, {0,1}, {0,4}, {0,3}, {0,1} },
	{ {3,1}, {3,1}, {3,4}, {3,3}, {3,1} } };

	int InitLocate[10][2] = { 0 };
	int Initx=0, Inity=0,InitForm=0;
	int i = 0;
	    Initx=InitLocate[0][0] = InitBoss[stage - 1][0];
	    Inity=InitLocate[0][1] = InitBoss[stage - 1][1];
		roles[0] = new Boss(i+1, Initx, Inity);
		++i;
	for ( ; i < 6; ++i) {
		InitForm = InitGeneral[i-1][stage - 1][0];
		Initx=InitLocate[i][0]= InitGeneral[i-1][stage - 1][1];
		Inity=InitLocate[i][1] = InitGeneral[i-1][stage - 1][2];
		roles[i] = new General(i+1 , InitForm, Initx, Inity);
	}
	for ( ; i < 10; ++i) {
		Initx=InitLocate[i][0] = InitSoldier[i-6][stage - 1][0];
		Inity=InitLocate[i][1] = InitSoldier[i-6][stage - 1][1];
		roles[i] = new Soldier(i + 1, Initx, Inity);
	}
	//选关后初始化
	level.Select(stage);
	optimum route(stage);
	Logic logic(stage);
	logic.Load(route.nametable, route.dirtable);//在logic中装载最优解
	scene.GameInit(stage,InitLocate);//棋盘初始化
	while (true) {//正式游戏
		operation = scene.Click();
		switch (operation) {
		case Interface::Option::move:
			//第一次的逻辑坐标
			logicx = scene.MovePoint.x - 1;
			logicy = scene.MovePoint.y - 1;
			RoleCode = getState(logicx, logicy);
			break;
		case Interface::direction:
			//第二次的逻辑坐标
			logicx = scene.MovePoint.x - 1;
			logicy = scene.MovePoint.y - 1;
			moveCode = roles[RoleCode + 1]->move(RoleCode, logicx, logicy);
			switch (moveCode) {
			case Role::move_result::up:
				DirCode = 1;
				break;
			case Role::move_result::down:
				DirCode = 2;
				break;
			case Role::move_result::left:
				DirCode = 3;
				break;
			case Role::move_result::right:
				DirCode = 4;
				break;
			default:
				break;
			}
			if (moveCode != Role::move_result::fail) {
				scene.BoardReflesh(RoleCode, roles[RoleCode - 1]->x, roles[RoleCode - 1]->y);
				logic.Record(RoleCode, DirCode);
			}
			break;
		case Interface::Option::help:
			code = logic.Help();
			scene.Help(code);//帮助功能发现bug,等我明天修改
			break;
		case Interface::Option::revoke:
			if (logic.Revoke())
				scene.Revoke();//回退功能完整
			break;
		case Interface::Option::music:
			//音乐的接口
			//设想的是先点击环境，再弹出三个音乐的选项
			break;
		case Interface::Option::exit:
			//具体的退出操作	
			break;
		}
		if (logic.Examine())
			scene.UselesStep();

		logic.Value();
		scene.stepwrite(logic.Cnt);
		scene.lifewrite(logic.score);
	}

	for (auto role : roles)
		delete role;
}
