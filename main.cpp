#include"Stage.h"
#include "Role.h"
#include "Interface.h"
#include "Logic.h"
#include <Windows.h>
#include <iostream>
int LogicPanel[5][4] = { 0 };

int main()
{	
	int RoleCode = 0, DirCode=0;//�������1-10 �������1-4
	int code;//������ʾ�Ĵ���
	int logicx, logicy;//�����ϵ���ĵ���߼�����
	int stage;//�ؿ���
	Interface::Mode process=Interface::start;//��Ϸ���̿���
	Interface::Option operation;//ö�� ѡ��Ĳ���
	Role::move_result moveCode;//�����ƶ��Ĵ���

	//��ʼ�������ӵ�λ��
	int InitLocate[10][2] = { 0 };//�洢�������Ͻ����� ���ڽ����ʼ��
	int i = 0;//��ʼ��������
	int Initx = 0, Inity = 0, InitForm = 0;//�м����
	int tempx=0, tempy=0;//�м����
	//BossΪ�ܲ٣��ĸ������
	int  InitBoss[5][2] = { {1,0},{1,0},{1,0},{1,0},{1,0} };
	//GeneralΪ�������������1��2������廹������
	int  InitGeneral[5][5][3] = {
	{ {1,0,3}, {1,2,3}, {2,0,0}, {1,2,4}, {2,0,3} },
	{ {1,2,3}, {1,1,4}, {2,3,0}, {2,0,0}, {2,3,0} },
	{ {1,1,4}, {1,2,2}, {1,1,4}, {1,0,4}, {1,1,3} },
	{ {1,0,2}, {2,1,2}, {2,2,2}, {2,1,2}, {1,0,2} },
	{ {1,2,2}, {2,0,2}, {2,1,2}, {2,3,0}, {1,2,2} } };
	//Soldier�ֱ�Ϊ
	int InitSoldier[4][5][2] = {
	{ {0,0}, {0,0}, {0,3}, {0,2}, {0,0} },
	{ {3,0}, {3,0}, {3,3}, {3,2}, {3,0} },
	{ {0,1}, {0,1}, {0,4}, {0,3}, {0,1} },
	{ {3,1}, {3,1}, {3,4}, {3,3}, {3,1} } };//

	//���½�Ϊչʾ����˳��
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

	//ʵ��������
	Role* roles[10];//����ָ������
	Stage level;//�ؿ���Ӧ���߼����̳�ʼ��
	Interface scene;//ͼ�λ���
	optimum route;//��Ϸ�����Ž�
	Logic logic;//��Ϸ�����߼�

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
			//��Ϸ���˵�
			scene.Begin();
			process = Interface::select;
			break;
		case Interface::select:
			//��Ϸ�ؿ�ģʽѡ��
			stage = scene.Select();//ѡ�ؽ���
			//ѡ��֮�󣬶�Boss���г�ʼ��
			Initx = InitLocate[0][0] = InitBoss[stage - 1][0];
			Inity = InitLocate[0][1] = InitBoss[stage - 1][1];
			roles[0]->Init(i + 1, Initx, Inity);
			++i;
			//ѡ��֮�󣬶�General���г�ʼ��
			for (; i < 6; ++i) {
				InitForm = InitGeneral[i - 1][stage - 1][0];
				Initx = InitLocate[i][0] = InitGeneral[i - 1][stage - 1][1];
				Inity = InitLocate[i][1] = InitGeneral[i - 1][stage - 1][2];
				roles[i]->Init(i + 1, InitForm, Initx, Inity);
			}
			//ѡ��֮�󣬶�Soldier���г�ʼ��
			for (; i < 10; ++i) {
				Initx = InitLocate[i][0] = InitSoldier[i - 6][stage - 1][0];
				Inity = InitLocate[i][1] = InitSoldier[i - 6][stage - 1][1];
				roles[i]->Init(i + 1, Initx, Inity);
			}
			//�߼����̳�ʼ��
			level.Select(stage);
			//��Ӧ�����Ž�·��
			route.Init(stage);
			//װ�����Ž�
			logic.Init(stage);
			logic.Load(route.nametable, route.dirtable);
			//ѡ��ģʽ
			process = scene.Choose();
			break;
		case Interface::show:
			//��ʾģʽ
			scene.GameInit(stage, InitLocate);//������Ϸ����
				for (int i = 0; i < route.step; ++i) {
					scene.BoardReflesh(route.moveRole(i), route.moveDir(i)+1,stage);
					Sleep(1000);
					if (process != Interface::show)
						break;
			    }
			break;
		case Interface::play:
			//������Ϸ����
			scene.GameInit(stage, InitLocate);
			while (process == Interface::play) {//��ʽ��Ϸ
				operation = scene.Click();
				switch (operation) {
				case Interface::Option::move:
					//��һ�ε��߼�����
					logicx = scene.MovePoint.x - 1;
					logicy = scene.MovePoint.y - 1;
					RoleCode = getState(logicx, logicy);//������� 1-10
					break;
				case Interface::direction:
					//�ڶ��ε��߼�����
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
					code = logic.Help();//��λ������
					scene.Help(code);//���ݴ��� ��ӡ��ʾ��ͼ
					break;
				case Interface::Option::revoke:
					if (logic.Revoke())
						scene.Revoke();
					break;
				case Interface::Option::music:
					//���ֵĽӿ�
					//��������ȵ���������ٵ����������ֵ�ѡ��
					break;
				case Interface::Option::exit:
					process = Interface::start;
					//Sleep(3000);//��ӡ�˳���ʾ
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
