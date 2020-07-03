#ifndef LOGIC_H
#define LOGIC_H
#include <vector>
#include "optimum.h"
#endif
class Logic
{
private:
	struct move { int role; int dir; };//һ���ƶ��ļ�¼
	std::vector<move> Optimum;//�洢���ص����Ž�
	bool OutOfRoute = false;//�Ƿ�ƫ�������Ž�·��
	int Point = 0;//Ŀǰ���������Ž�·���ϵĵ�
	move Move;//��ҵ�һ�β���
	int DirTrans[4] = { 1,-1,2,-2 };//���ƶ�����Ĵ���0,1,2,3����ת��
	std::vector<move>HelpRoute;//ƫ������·�ߺ�ļ�¼·��
	int MoveCheck[10] = { 0 };//����������ӵ�λ�ñ仯
	int UselesStep = 0;
	bool UsedHelp = false;//�Ƿ�ʹ���˰���
	bool UsedRevoke = false;//�Ƿ�ʹ���˻���
	int step;
public:
	int Cnt = 0;//Ŀǰ���ߵĲ���
	int score = 100;//��Ϸ�÷֣�����ֵ��
	void Load(std::vector<int>& nametable, std::vector<int>& dirtable);//¼�����Ž�
	void Record(int RoleCode, int DirCode);//��¼��ҵ��ƶ�
	bool Examine();//������ù�����
	int Help();//��������
	bool Revoke();//���˹���
	void Value();//��������
	Logic(int stage);
};

