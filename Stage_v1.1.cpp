#include"Stage.h"
#include"Role.h"
#include<iostream>

//Stage.h/cpp�ļ������߼����̵ĳ�ʼ��,�Լ���������
/*
State��ʾ��һ������˭:
0=�� 1=�ܲ� 2=�� 3=�� 4=�� 5=�� 6=�� 7~10=С��1~4
General1Ϊ���� 2Ϊ����
*/
//������ÿһ�ص��߼����̳�ʼ��.
void Stage::Stage1()
{

	LogicPanel[0][0] = 7;
	LogicPanel[0][1] = 1;
	LogicPanel[0][2] = 1;
	LogicPanel[0][3] = 8;
	LogicPanel[1][0] = 9;
	LogicPanel[1][1] = 1;
	LogicPanel[1][2] = 1;
	LogicPanel[1][3] = 10;
	LogicPanel[2][0] = 4;
	LogicPanel[2][1] = 4;
	LogicPanel[2][2] = 5;
	LogicPanel[2][3] = 5;
	LogicPanel[3][0] = 6;
	LogicPanel[3][1] = 6;
	LogicPanel[3][2] = 3;
	LogicPanel[3][3] = 3;
	LogicPanel[4][0] = 0;
	LogicPanel[4][1] = 2;
	LogicPanel[4][2] = 2;
	LogicPanel[4][3] = 0;


}

void Stage::Stage2()
{
	
	LogicPanel[0][0] = 7;
	LogicPanel[0][1] = 1;
	LogicPanel[0][2] = 1;
	LogicPanel[0][3] = 8;
	LogicPanel[1][0] = 9;
	LogicPanel[1][1] = 1;
	LogicPanel[1][2] = 1;
	LogicPanel[1][3] = 10;
	LogicPanel[2][0] = 5;
	LogicPanel[2][1] = 4;
	LogicPanel[2][2] = 2;
	LogicPanel[2][3] = 2;
	LogicPanel[3][0] = 5;
	LogicPanel[3][1] = 4;
	LogicPanel[3][2] = 6;
	LogicPanel[3][3] = 6;
	LogicPanel[4][0] = 0;
	LogicPanel[4][1] = 3;
	LogicPanel[4][2] = 3;
	LogicPanel[4][3] = 0;

}

void Stage::Stage3()
{
	
	LogicPanel[0][0] = 6;
	LogicPanel[0][1] = 1;
	LogicPanel[0][2] = 1;
	LogicPanel[0][3] = 3;
	LogicPanel[1][0] = 6;
	LogicPanel[1][1] = 1;
	LogicPanel[1][2] = 1;
	LogicPanel[1][3] = 3;
	LogicPanel[2][0] = 0;
	LogicPanel[2][1] = 5;
	LogicPanel[2][2] = 4;
	LogicPanel[2][3] = 0;
	LogicPanel[3][0] = 7;
	LogicPanel[3][1] = 5;
	LogicPanel[3][2] = 4;
	LogicPanel[3][3] = 8;
	LogicPanel[4][0] = 9;
	LogicPanel[4][1] = 2;
	LogicPanel[4][2] = 2;
	LogicPanel[4][3] = 10;

}

void Stage::Stage4()
{
	
	LogicPanel[0][0] = 3;
	LogicPanel[0][1] = 1;
	LogicPanel[0][2] = 1;
	LogicPanel[0][3] = 5;
	LogicPanel[1][0] = 3;
	LogicPanel[1][1] = 1;
	LogicPanel[1][2] = 1;
	LogicPanel[1][3] = 5;
	LogicPanel[2][0] = 7;
	LogicPanel[2][1] = 4;
	LogicPanel[2][2] = 0;
	LogicPanel[2][3] = 8;
	LogicPanel[3][0] = 9;
	LogicPanel[3][1] = 4;
	LogicPanel[3][2] = 0;
	LogicPanel[3][3] = 10;
	LogicPanel[4][0] = 2;
	LogicPanel[4][1] = 2;
	LogicPanel[4][2] = 6;
	LogicPanel[4][3] = 6;

}

void Stage::Stage5()
{
	
	LogicPanel[0][0] = 6;
	LogicPanel[0][1] = 1;
	LogicPanel[0][2] = 1;
	LogicPanel[0][3] = 3;
	LogicPanel[1][0] = 6;
	LogicPanel[1][1] = 1;
	LogicPanel[1][2] = 1;
	LogicPanel[1][3] = 3;
	LogicPanel[2][0] = 4;
	LogicPanel[2][1] = 4;
	LogicPanel[2][2] = 5;
	LogicPanel[2][3] = 5;
	LogicPanel[3][0] = 7;
	LogicPanel[3][1] = 2;
	LogicPanel[3][2] = 2;
	LogicPanel[3][3] = 8;
	LogicPanel[4][0] = 9;
	LogicPanel[4][1] = 0;
	LogicPanel[4][2] = 0;
	LogicPanel[4][3] = 10;

}

void end()//������Ϸ����õĺ���
{
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

	//��������ʾѡ�ؽ���(ͼ�λ����������)
}


