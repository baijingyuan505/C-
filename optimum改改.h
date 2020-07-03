#ifndef OPTIMUM_H
#define OPTIMUM_H
#include<iostream>
#include<vector>
#include"Role_v1.1.h"
#endif

class optimum//���Ž�
{
public:
	enum class name { �� = 0, ��, ��, ��, ��, ��, ��, ��, ��, ��, �� };//ö�ٶ���:��������,ֵΪ1-10
	enum class dir { �� = 0, ��, ��, �� };//ö�ٶ���:�ƶ�����,ֵΪ0-3

	std::vector<name> nametable;//Ҫ�ƶ����ӵļ�¼���
	std::vector<dir> dirtable;//�ƶ�����ļ�¼���
	int step;//���Ž���ƶ�����
	optimum(int n);//���캯��:��������3����Ա����������Ϊ�ؿ����1-5

	//void movebyoptimum(Role* CaoCao, Role* GuanYu, Role* ZhaoYun, Role* MaChao, Role* HuangZhong, Role* ZhangFei, Role* S1, Role* S2, Role* S3, Role* S4)const;
	//����û�õĺ���

};

optimum::optimum(int n) {
	nametable.clear();
	dirtable.clear();

	//��¼�����Ž�����ı���ʽΪÿ20���������ֻ�һ�У���һ��20��Ԫ��
	name Stage1_Name[48] = {
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::�� };
	dir Stage1_Dir[48] = {
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::�� };
	//������ء�37��

	name Stage2_Name[62] = {
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::�� };
	dir Stage2_Dir[62] = {
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::�� };
	//����������44��

	name Stage3_Name[90] = {
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::�� };
	dir Stage3_Dir[90] = {
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::�� };
	//�����Ҳ�����62��

	name Stage4_Name[125] = {
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::�� };
	dir Stage4_Dir[125] = {
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::�� };
	//������ѷɡ�90��

	name Stage5_Name[178] = {
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::�� };
	dir Stage5_Dir[178] = {
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::�� };
	//��С�������131��

	switch (n) {//���캯�������岿��
	case 1:
		step = 48;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage1_Name[i]);
			dirtable.push_back(Stage1_Dir[i]);
		}
		break;
	case 2:
		step = 62;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage2_Name[i]);
			dirtable.push_back(Stage2_Dir[i]);
		}
		break;
	case 3:
		step = 90;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage3_Name[i]);
			dirtable.push_back(Stage3_Dir[i]);
		}
		break;
	case 4:
		step = 125;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage4_Name[i]);
			dirtable.push_back(Stage4_Dir[i]);
		}
		break;
	case 5:
		step = 178;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage5_Name[i]);
			dirtable.push_back(Stage5_Dir[i]);
		}
		break;
	}
}

/*void optimum::movebyoptimum(Role* CaoCao, Role* GuanYu, Role* ZhaoYun, Role* MaChao, Role* HuangZhong, Role* ZhangFei, Role* S1, Role* S2, Role* S3, Role* S4)const
{
	for (int i = 0; i < step; ++i)
	{
		movewhichwhere(nametable[i], dirtable[i], CaoCao, GuanYu, ZhaoYun, MaChao, HuangZhong, ZhangFei, S1, S2, S3, S4);//�ƶ�һ��
		//�������գ��벹�䡰��ͼ�λ�������ʾ�ƶ��������ĺ���
	}
}*/

//movewhichwhere(route.nametable[i], route.dirtable[i], CaoCao, GuanYu, ZhaoYun, MaChao, HuangZhong, ZhangFei, S1, S2, S3, S4);//����ʾ��
void movewhichwhere(optimum::name n, optimum::dir d, Role* CaoCao, Role* GuanYu, Role* ZhaoYun, Role* MaChao, Role* HuangZhong, Role* ZhangFei, Role* S1, Role* S2, Role* S3, Role* S4)
{//ͨ��n��d������ε���move����������ʵ�����Ž���ʾ����
	switch (n)
	{
		int i = static_cast<int>(n);
	case optimum::name::��:
		if (d == optimum::dir::��)			CaoCao->move(i, CaoCao->x, (CaoCao->y - 1));
		else if (d == optimum::dir::��)		CaoCao->move(i, CaoCao->x, (CaoCao->y + 1));
		else if (d == optimum::dir::��)		CaoCao->move(i, (CaoCao->x - 1), CaoCao->y);
		else					/*��*/		CaoCao->move(i, (CaoCao->x + 1), CaoCao->y);
		break;
	case optimum::name::��:
		if (d == optimum::dir::��)			GuanYu->move(i, GuanYu->x, (GuanYu->y - 1));
		else if (d == optimum::dir::��)		GuanYu->move(i, GuanYu->x, (GuanYu->y + 1));
		else if (d == optimum::dir::��)		GuanYu->move(i, (GuanYu->x - 1), GuanYu->y);
		else					/*��*/		GuanYu->move(i, (GuanYu->x + 1), GuanYu->y);
		break;
	case optimum::name::��:
		if (d == optimum::dir::��)			ZhaoYun->move(i, ZhaoYun->x, (ZhaoYun->y - 1));
		else if (d == optimum::dir::��)		ZhaoYun->move(i, ZhaoYun->x, (ZhaoYun->y + 1));
		else if (d == optimum::dir::��)		ZhaoYun->move(i, (ZhaoYun->x - 1), ZhaoYun->y);
		else					/*��*/		ZhaoYun->move(i, (ZhaoYun->x + 1), ZhaoYun->y);
		break;
	case optimum::name::��:
		if (d == optimum::dir::��)			MaChao->move(i, MaChao->x, (MaChao->y - 1));
		else if (d == optimum::dir::��)		MaChao->move(i, MaChao->x, (MaChao->y + 1));
		else if (d == optimum::dir::��)		MaChao->move(i, (MaChao->x - 1), MaChao->y);
		else					/*��*/		MaChao->move(i, (MaChao->x + 1), MaChao->y);
		break;
	case optimum::name::��:
		if (d == optimum::dir::��)			HuangZhong->move(i, HuangZhong->x, (HuangZhong->y - 1));
		else if (d == optimum::dir::��)		HuangZhong->move(i, HuangZhong->x, (HuangZhong->y + 1));
		else if (d == optimum::dir::��)		HuangZhong->move(i, (HuangZhong->x - 1), HuangZhong->y);
		else					/*��*/		HuangZhong->move(i, (HuangZhong->x + 1), HuangZhong->y);
		break;
	case optimum::name::��:
		if (d == optimum::dir::��)			ZhangFei->move(i, ZhangFei->x, (ZhangFei->y - 1));
		else if (d == optimum::dir::��)		ZhangFei->move(i, ZhangFei->x, (ZhangFei->y + 1));
		else if (d == optimum::dir::��)		ZhangFei->move(i, (ZhangFei->x - 1), ZhangFei->y);
		else					/*��*/		ZhangFei->move(i, (ZhangFei->x + 1), ZhangFei->y);
		break;
	case optimum::name::��:
		if (d == optimum::dir::��)			S1->move(i, S1->x, (S1->y - 1));
		else if (d == optimum::dir::��)		S1->move(i, S1->x, (S1->y + 1));
		else if (d == optimum::dir::��)		S1->move(i, (S1->x - 1), S1->y);
		else					/*��*/		S1->move(i, (S1->x + 1), S1->y);
		break;
	case optimum::name::��:
		if (d == optimum::dir::��)			S2->move(i, S2->x, (S2->y - 1));
		else if (d == optimum::dir::��)		S2->move(i, S2->x, (S2->y + 1));
		else if (d == optimum::dir::��)		S2->move(i, (S2->x - 1), S2->y);
		else					/*��*/		S2->move(i, (S2->x + 1), S2->y);
		break;
	case optimum::name::��:
		if (d == optimum::dir::��)			S3->move(i, S3->x, (S3->y - 1));
		else if (d == optimum::dir::��)		S3->move(i, S3->x, (S3->y + 1));
		else if (d == optimum::dir::��)		S3->move(i, (S3->x - 1), S3->y);
		else					/*��*/		S3->move(i, (S3->x + 1), S3->y);
		break;
	case optimum::name::��:
		if (d == optimum::dir::��)			S4->move(i, S4->x, (S4->y - 1));
		else if (d == optimum::dir::��)		S4->move(i, S4->x, (S4->y + 1));
		else if (d == optimum::dir::��)		S4->move(i, (S4->x - 1), S4->y);
		else					/*��*/		S4->move(i, (S4->x + 1), S4->y);
		break;
	}
}
