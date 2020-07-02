#ifndef OPTIMUM_H
#define OPTIMUM_H
#include<iostream>
#include<vector>//#include"move��������ͷ�ļ�"
#endif

class optimum//���Ž�
{
	enum class name { �� = 0, ��, ��, ��, ��, ��, ��, ��, ��, ��, �� };//ö�ٶ���:��������,ֵΪ1-10
	enum class dir { �� = 0, ��, ��, �� };//ö�ٶ���:�ƶ�����,ֵΪ0-3

	std::vector<name> nametable;//Ҫ�ƶ����ӵļ�¼���
	std::vector<dir> dirtable;//�ƶ�����ļ�¼���
	int step;//���Ž���ƶ�����
	optimum(int n);//���캯��:�����ڶ�������������������񣬲���Ϊ�ؿ����1-5

	void movebyoptimum(void)const;//���庯��:����Ԥ��¼������Ž��ƶ�������ͨ�أ������������̵ĳ�ʼ����
	//void optimumsave(void)const;//Ԥ������:���ɲ�����һ�����Ž⸱��������ʵ����ʾ���ܣ��ݲ�ʹ�ã�

	friend void movewhichwhere(name n, dir d);//��Ԫ����:ͨ�������name��dir���������ĸ�move����
};
//���캯����ʼ��
optimum::optimum(int n) {
	nametable.clear();
	dirtable.clear();
	name Stage1_Name[48] = {
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::�� };
	dir Stage1_Dir[48] = {
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::�� };
	//������name::�ء�37��

	name Stage2_Name[59] = {
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::�� };
	dir Stage2_Dir[59] = {
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::�� };
	//����������44��

	name Stage3_Name[88] = {
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::�� };
	dir Stage3_Dir[88] = {
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::�� };
	//��dir::��dir::�Ҳ�name::����62��

	name Stage4_Name[124] = {
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::�� };
	dir Stage4_Dir[124] = {
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::�� };
	//������ѷɡ�90��

	name Stage5_Name[176] = {
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,
		name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::��,name::�� };
	dir Stage5_Dir[176] = {
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,
		dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::��,dir::�� };
	//��С�������131��

	switch (n) {
	case 1:
		step = 48;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage1_Name[i]);
			dirtable.push_back(Stage1_Dir[i]);
		}
		break;
	case 2:
		step = 59;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage2_Name[i]);
			dirtable.push_back(Stage2_Dir[i]);
		}
		break;
	case 3:
		step = 88;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage3_Name[i]);
			dirtable.push_back(Stage3_Dir[i]);
		}
		break;
	case 4:
		step = 124;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage4_Name[i]);
			dirtable.push_back(Stage4_Dir[i]);
		}
		break;
	default:
		step = 176;
		for (int i = 0; i < step; ++i) {
			nametable.push_back(Stage5_Name[i]);
			dirtable.push_back(Stage5_Dir[i]);
		}
		break;
	}
}

void optimum::movebyoptimum(void)const
{
	for (int i = 0; i < step; ++i)
	{
		movewhichwhere(nametable[i], dirtable[i]);//�ƶ�һ��
		//�������գ����ͬѧ���䡰��ͼ�λ�������ʾ�ƶ��������ĺ���
	}
}

/*void optimum::optimumsave(void)const
{
	for (int i = 0; i < step; ++i) {
		movewhichwhere(nametable[i], dirtable[i]);//�ƶ�һ��
		//�������գ����ڱ��浱ǰ����״̬
	}
}
*/

void movewhichwhere(optimum::name n, optimum::dir d)
{
	int i=static_cast<int>(n);

	//�ȴ��趨�ƶ�����ͬѧ����
	//�ٶ�����ָ�������Ϊ  role[i],i��[1,10];//��dir���͵�dѡ��ִ�е��ƶ�
	if (d == optimum::dir::��)			role[i]->move_up();
	else if (d == optimum::dir::��)		role[i]->move_down();
	else if (d == optimum::dir::��)		role[i]->move_left();
	else if (d == optimum::dir::��)		role[i]->move_right();

}
