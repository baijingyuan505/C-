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

	Interface::Option operation;//ö�� ѡ��Ĳ���

	int RoleCode = 0, DirCode=0;
	Role::move_result moveCode;
	//����
	int code;//������ʾ�Ĵ���
	int logicx, logicy;//����ĵ���߼����꣨�������Ͻǣ�
	int stage;//�ؿ���

	scene.Begin();//��ʼ����
	stage = scene.Select();//ѡ�ؽ���
	
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
	//ѡ�غ��ʼ��
	level.Select(stage);
	optimum route(stage);
	Logic logic(stage);
	logic.Load(route.nametable, route.dirtable);//��logic��װ�����Ž�
	scene.GameInit(stage,InitLocate);//���̳�ʼ��
	while (true) {//��ʽ��Ϸ
		operation = scene.Click();
		switch (operation) {
		case Interface::Option::move:
			//��һ�ε��߼�����
			logicx = scene.MovePoint.x - 1;
			logicy = scene.MovePoint.y - 1;
			RoleCode = getState(logicx, logicy);
			break;
		case Interface::direction:
			//�ڶ��ε��߼�����
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
			scene.Help(code);//�������ܷ���bug,���������޸�
			break;
		case Interface::Option::revoke:
			if (logic.Revoke())
				scene.Revoke();//���˹�������
			break;
		case Interface::Option::music:
			//���ֵĽӿ�
			//��������ȵ���������ٵ����������ֵ�ѡ��
			break;
		case Interface::Option::exit:
			//������˳�����	
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
