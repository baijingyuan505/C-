#include"Role.h"
#include"Stage.h"
#include"Sound.h"
#include "optimum.h"
#include "Interface.h"
#include "Logic.h"
#include<iostream>

void end();//��������

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

	Interface::Option operation;//ö�� ѡ��Ĳ���

	string code;//������ʾ�Ĵ���
	int logicx, logicy;//����ĵ���߼����꣨�������Ͻǣ�
	int stage;//�ؿ���

	scene.Begin();//��ʼ����
	stage = scene.Select();//ѡ�ؽ���
	switch (stage)
	{//����ѡ��Ĺؿ��Խ�ɫ����ʵ���������ӵĴ��ţ����ӳ�ʼx����ʼy����
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

	//ѡ�غ��ʼ��
	optimum route(stage);
    const int steps = route.step;
	Logic<steps> logic;//������
	//logic.Load(static_cast<int>(route.nametable), static_cast<int>(route.dirtable));
	logic.Load(route.nametable, route.dirtable);//����ת�� ������
	scene.GameInit(stage);//���̳�ʼ��
	while (true) {//��ʽ��Ϸ
		operation=scene.Click();
		switch (operation) {
		case Interface::Option::move:
			logicx = scene.MovePoint.x - 1;
			logicy = scene.MovePoint.y - 1;
			//�ӿ�,��ʵ��
			//��һ�ε�����̵��߼�����
			//
			break;
		case Interface::Option::help:
			code=logic.Help();
			scene.Help(code);//�������ܷ���bug,���������޸�
			break;
		case Interface::Option::revoke:
			if (logic.Revoke())
				scene.Revoke();//���˹�������
			break;
		case Interface::Option::music:
			//���ֵĽӿ�
			//��������ȵ���������ٵ����������ֵ�ѡ��
		case Interface::Option::exit:
			//������˳�����
		}
		if (logic.Examine())
			scene.UselesStep();
		//��Ҫ��¼��һ���ߵĽ�ɫ�ͷ���
		logic.Record(3, 2);//����ʾ��
		logic.Value();
		scene.stepwrite(logic.Cnt);
		scene.lifewrite(logic.score);
	}


}

void end()//������Ϸ����õĺ���
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
	delete S4;//ɾ��new�����Ķ���

	*/
}