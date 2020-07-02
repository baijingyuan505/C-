#include "Logic.h"

template<int step>
inline void Logic<step>::Load(std::vector<int>& nametable, std::vector<int>& dirtable)
{
	int RoleCode;//���ӵĴ���0-9
	int DirCode;//�ƶ�����Ĵ���1,-1,2,-2
	for (int i = 0; i < step; ++i) {
		RoleCode = nametable[i] - 1;//����1-10
		Optimum[i].role = RoleCode;//���д���ת��
		DirCode = dirtable[i];//����0-3
		Optimum[i].dir = DirTrans[DirCode];//���д���ת��
	}
}

template<int step>
void Logic<step>::Record(int RoleCode, int DirCode)
{
	DirCode = DirTrans[DirCode];
	Move.role = RoleCode;
	Move.dir = DirCode;
	if (!OutOfRoute) {
		//δƫ�����Ž�·��ʱ
		if (Move == Optimum[Point])
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

template<int step>
std::string Logic<step>::Help()
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
	char Code[2];
	Code[0] = HelpMove.role;
	Code[1] = HelpMove.dir;
	return Code[0] + Code[1];//������ʾ�Ĵ���
}

template<int step>
bool Logic<step>::Examine()
{
	if (!OutOfRoute)
		return false;
	    //δƫ�����Ž�·�ߣ��򲻿��ܳ������ù�
	for (auto iter = HelpRoute.end(); iter != HelpRoute.begin(); --iter) {
		MoveCheck[*iter.role] += *iter.dir;//��¼��Ӧ���ӵ�λ�ñ仯
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

template<int step>
bool Logic<step>::Revoke()
{
	if (UselesStep != 0) {
		Cnt -= UselesStep;//��ȥ���õĲ���
		UsedRevoke = true;//��¼ʹ���˸ù��ܣ�Ӱ��÷�
		return true;
	}
	return false;
}

template<int step>
void Logic<step>::Value()
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