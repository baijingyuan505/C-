#include "optimum.h"

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