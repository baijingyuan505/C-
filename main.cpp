#include"Stage.h"
#include "Role.h"
#include "Interface.h"
#include "Logic.h"
#include <Windows.h>
#include <iostream>
int LogicPanel[5][4] = { 0 };

int main()
{	
	int RoleCode = 0, DirCode=0;//人物代号1-10 方向代号1-4
	int code;//帮助提示的代号
	int logicx, logicy;//界面上点击的点的逻辑坐标
	int stage;//关卡号
	Interface::Mode process=Interface::start;//游戏流程控制
	Interface::Option operation;//枚举 选择的操作
	Role::move_result moveCode;//棋子移动的代号

	//初始化各棋子的位置
	int InitLocate[10][2] = { 0 };//存储棋子左上角坐标 用于界面初始化
	int i = 0;//初始化计数器
	int Initx = 0, Inity = 0, InitForm = 0;//中间变量
	int tempx=0, tempy=0;//中间变量
	//Boss为曹操，四格的棋子
	int  InitBoss[5][2] = { {1,0},{1,0},{1,0},{1,0},{1,0} };
	//General为五个将，用数字1或2代表横棋还是竖棋
	int  InitGeneral[5][5][3] = {
	{ {1,0,3}, {1,2,3}, {2,0,0}, {1,2,4}, {2,0,3} },
	{ {1,2,3}, {1,1,4}, {2,3,0}, {2,0,0}, {2,3,0} },
	{ {1,1,4}, {1,2,2}, {1,1,4}, {1,0,4}, {1,1,3} },
	{ {1,0,2}, {2,1,2}, {2,2,2}, {2,1,2}, {1,0,2} },
	{ {1,2,2}, {2,0,2}, {2,1,2}, {2,3,0}, {1,2,2} } };
	//Soldier分别为
	int InitSoldier[4][5][2] = {
	{ {0,0}, {0,0}, {0,3}, {0,2}, {0,0} },
	{ {3,0}, {3,0}, {3,3}, {3,2}, {3,0} },
	{ {0,1}, {0,1}, {0,4}, {0,3}, {0,1} },
	{ {3,1}, {3,1}, {3,4}, {3,3}, {3,1} } };//

	//以下仅为展示人物顺序
	int Init_CaoCao[5][2] = { {1,0},{1,0},{1,0},{1,0},{1,0} };
	int Init_ZhangFei[5][3] = { {1,0,3}, {1,2,3}, {2,0,0}, {1,2,4}, {2,0,3} };
	int Init_ZhaoYun[5][3] = { {1,2,3}, {1,1,4}, {2,3,0}, {2,0,0}, {2,3,0} };
	int Init_GuanYu[5][3] = { {1,1,4}, {1,2,2}, {1,1,4}, {1,0,4}, {1,1,3} };
	int Init_MaChao[5][3] = { {1,0,2}, {2,1,2}, {2,2,2}, {2,1,2}, {1,0,2} };
	int Init_HuangZhong[5][3] = { {1,2,2}, {2,0,2}, {2,1,2}, {2,3,0}, {1,2,2} };
	int Init_S1[5][2] = { {0,0}, {0,0}, {0,3}, {0,2}, {0,0} };
	int Init_S2[5][2] = { {3,0}, {3,0}, {3,3}, {3,2}, {3,0} };
	int Init_S3[5][2] = { {0,1}, {0,1}, {0,4}, {0,3}, {0,1} };
	int Init_S4[5][2] = { {3,1}, {3,1}, {3,4}, {3,3}, {3,1} };

	//实例化对象
	Role* roles[10];//对象指针数组
	Stage level;//关卡对应的逻辑棋盘初始化
	Interface scene;//图形化类
	optimum route;//游戏的最优解
	Logic logic;//游戏运行逻辑

	roles[0] = new Boss;
	roles[1] = new General;
	roles[2] = new General;
	roles[3] = new General;
	roles[4] = new General;
	roles[5] = new General;
	roles[6] = new Soldier;
	roles[7] = new Soldier;
	roles[8] = new Soldier;
	roles[9] = new Soldier;
	

	while (process!= Interface::quit) {
		switch (process)
		{
		case Interface::start:
			//游戏主菜单
			scene.Begin();
			process = Interface::select;
			break;
		case Interface::select:
			//游戏关卡模式选择
			stage = scene.Select();//选关界面
			//选关之后，对Boss进行初始化
			Initx = InitLocate[0][0] = InitBoss[stage - 1][0];
			Inity = InitLocate[0][1] = InitBoss[stage - 1][1];
			roles[0]->Init(i + 1, Initx, Inity);
			++i;
			//选关之后，对General进行初始化
			for (; i < 6; ++i) {
				InitForm = InitGeneral[i - 1][stage - 1][0];
				Initx = InitLocate[i][0] = InitGeneral[i - 1][stage - 1][1];
				Inity = InitLocate[i][1] = InitGeneral[i - 1][stage - 1][2];
				roles[i]->Init(i + 1, InitForm, Initx, Inity);
			}
			//选关之后，对Soldier进行初始化
			for (; i < 10; ++i) {
				Initx = InitLocate[i][0] = InitSoldier[i - 6][stage - 1][0];
				Inity = InitLocate[i][1] = InitSoldier[i - 6][stage - 1][1];
				roles[i]->Init(i + 1, Initx, Inity);
			}
			//逻辑棋盘初始化
			level.Select(stage);
			//对应的最优解路线
			route.Init(stage);
			//装载最优解
			logic.Init(stage);
			logic.Load(route.nametable, route.dirtable);
			//选择模式
			process = scene.Choose();
			break;
		case Interface::show:
			//演示模式
			scene.GameInit(stage, InitLocate);//加载游戏界面
				for (int i = 0; i < route.step; ++i) {
					scene.BoardReflesh(route.moveRole(i), route.moveDir(i)+1,stage);
					Sleep(1000);
					if (process != Interface::show)
						break;
			    }
			break;
		case Interface::play:
			//加载游戏界面
			scene.GameInit(stage, InitLocate);
			while (process == Interface::play) {//正式游戏
				operation = scene.Click();
				switch (operation) {
				case Interface::Option::move:
					//第一次的逻辑坐标
					logicx = scene.MovePoint.x - 1;
					logicy = scene.MovePoint.y - 1;
					RoleCode = getState(logicx, logicy);//人物代号 1-10
					break;
				case Interface::direction:
					//第二次的逻辑坐标
					logicx = scene.MovePoint.x - 1;
					logicy = scene.MovePoint.y - 1;
					moveCode = roles[RoleCode - 1]->move(RoleCode, logicx, logicy);
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
						tempx = roles[RoleCode - 1]->returnx();
						tempy = roles[RoleCode - 1]->returny();
						scene.BoardReflesh(RoleCode, tempx, tempy,stage);
						logic.Record(RoleCode, DirCode);
					}
					break;
				case Interface::Option::help:
					code = logic.Help();//两位数代号
					scene.Help(code);//传递代号 打印提示贴图
					break;
				case Interface::Option::revoke:
					if (logic.Revoke())
						scene.Revoke();
					break;
				case Interface::Option::music:
					//音乐的接口
					//设想的是先点击环境，再弹出三个音乐的选项
					break;
				case Interface::Option::exit:
					process = Interface::start;
					//Sleep(3000);//打印退出提示
					break;
				}
				if (logic.Examine())
					scene.UselesStep();
				//logic.Value();
				//scene.stepwrite(logic.Cnt);
				//scene.lifewrite(logic.score);
			}
			break;
		case Interface::quit:
			break;
		default:
			break;
		}
	}
	for (auto role : roles)
		delete role;
	
}
