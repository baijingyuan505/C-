#ifndef OPTIMUM_H
#define OPTIMUM_H
#include<iostream>
#include<vector>//#include"move��������ͷ�ļ�"
#endif

class optimum//���Ž�
{
public:

	std::vector<int> nametable;//Ҫ�ƶ����ӵļ�¼���
	std::vector<int> dirtable;//�ƶ�����ļ�¼���
	int step = 0;//���Ž���ƶ�����

	optimum(int n);//���캯��:��������3����Ա����������Ϊ�ؿ����1-5

	int moveRole(int i);
	int moveDir(int i);

};