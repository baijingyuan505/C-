#ifndef OPTIMUM_H
#define OPTIMUM_H
#include<iostream>
#include<vector>//#include"move��������ͷ�ļ�"
#endif

class optimum//���Ž�
{
public:
	int counter = 0;//������
	std::vector<int> nametable;//Ҫ�ƶ����ӵļ�¼���
	std::vector<int> dirtable;//�ƶ�����ļ�¼���
	int step = 0;//���Ž���ƶ�����

	void Init(int n);//���캯��:��������3����Ա����������Ϊ�ؿ����1-5

	int moveRole();
	int moveDir();

};