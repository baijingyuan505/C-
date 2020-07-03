#include "Logic.h"

Logic::Logic(int stage)
{
	switch (stage) {
	case 1:
		step = 48;break;
	case 2:
		step = 62;break;
	case 3:
		step = 90;break;
	case 4:
		step = 125;break;
	case 5:
		step = 178;break;
	}
}

inline void Logic::Load(std::vector<optimum::name>& nametable, std::vector<optimum::dir>& dirtable)
{
	int RoleCode;//���ӵĴ���0-9
	int DirCode;//�ƶ�����Ĵ���1,-1,2,-2
	Optimum.clear();
	for (int i = 0; i < step; ++i) {
		RoleCode = static_cast<int>(nametable[i]) - 1;//����1-10
		Move.role = RoleCode;//���д���ת��
		DirCode = static_cast<int>(dirtable[i]);//����0-3
		Move.dir = DirTrans[DirCode];//���д���ת��
		Optimum.push_back(Move);
	}
}

void Logic::Record(int RoleCode, int DirCode)
{
	DirCode = DirTrans[DirCode];
	Move.role = RoleCode;
	Move.dir = DirCode;
	if (!OutOfRoute) {
		//δƫ�����Ž�·��ʱ
		if (Move.dir == Optimum[Point].dir&& Move.role == Optimum[Point].role)
			++Point;//���������Ž�·���ϣ�������1
		else
			OutOfRoute = true;//����ƫ����·��
	}
	if(OutOfRoute){
		//ƫ�������Ž�·��
		HelpRoute.push_back(Move);
	}

	++Cnt;//�ܲ�����1
	
}

int Logic::Help()
{
	move HelpMove;//������ʾ
	if (HelpRoute.empty()) {
		//����������Ž��·��Ϊ��
		OutOfRoute = false;
		HelpMove = Optimum[Point + 1];//��ȡ���Ž�·�ߵ���һ��
	}
	else {
		//��ʾ�������Ž��·��
		auto iter = HelpRoute.end();
		HelpMove = *iter;//��ȡ����·�ߵ����һ��
		HelpRoute.pop_back();//ͬʱɾ�����һ��
	}
	UsedHelp = true;//��¼ʹ���˸ù��ܣ�Ӱ��÷�

	HelpMove.role += 1;
	switch (HelpMove.dir)
	{
	case 1:HelpMove.dir = 1; break;
	case -1:HelpMove.dir = 2; break;
	case 2:HelpMove.dir = 3; break;
	case -2:HelpMove.dir = 4; break;
	}
	return HelpMove.role * 10 + HelpMove.dir;//������ʾ�Ĵ���
}

bool Logic::Examine()
{
	if (!OutOfRoute)
		return false;
	    //δƫ�����Ž�·�ߣ��򲻿��ܳ������ù�
	for (auto iter = HelpRoute.end(); iter != HelpRoute.begin(); --iter) {
		MoveCheck[(*iter).role] += (*iter).dir;//��¼��Ӧ���ӵ�λ�ñ仯
		int Count=0;//ÿһ��ѭ��������һ�μ���
		for (auto i : MoveCheck) {
			if (i == 0)//�鿴�������ӵ�λ�ñ仯
				++Count;//Ϊ0�����ص���ǰ״̬��������1
		}
		++UselesStep;
		if (Count == 10) {
			//����Ϊ10����˵���������ù�
			for (int Cnt = 0; Cnt < UselesStep; ++Cnt)
				HelpRoute.pop_back();
			    //ɾ������·�������õĲ���
			return true;//�������� ������ʾ 
		}

	}//����ѭ������˵�����������ù�����

	//�Լ�¼�ļٶ����ò�����0
	UselesStep = 0;
	//�Լ�¼���ӱ仯��������0
	for (auto i : MoveCheck)
		i = 0;
	return false;
}

bool Logic::Revoke()
{
	if (UselesStep != 0) {
		Cnt -= UselesStep;//��ȥ���õĲ���
		UsedRevoke = true;//��¼ʹ���˸ù��ܣ�Ӱ��÷�
		return true;
	}
	return false;
}

void Logic::Value()
{
	if (Cnt > step)
		score -= 1;
	if (UsedHelp)
		score -= 2;
	if (UsedRevoke)
		score -= 3;

	UsedHelp = false;
	UsedRevoke = false;
}