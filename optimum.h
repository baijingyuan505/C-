#ifndef OPTIMUM_H
#define OPTIMUM_H
#include<iostream>
#include<vector>//#include"move��������ͷ�ļ�"
#endif
enum name { �� = 0, ��, ��, ��, ��, ��, ��, ��, ��, ��, �� };//ö�ٶ���:��������,ֵΪ1-10
enum dir { �� = 0, ��, ��, �� };//ö�ٶ���:�ƶ�����,ֵΪ0-3


class optimum//���Ž�
{
public:

	std::vector<name> nametable;//Ҫ�ƶ����ӵļ�¼���
	std::vector<dir> dirtable;//�ƶ�����ļ�¼���
	int step=0;//���Ž���ƶ�����
	optimum(int n);//���캯��:��������3����Ա����������Ϊ�ؿ����1-5

	//void movebyoptimum(Role* CaoCao, Role* GuanYu, Role* ZhaoYun, Role* MaChao, Role* HuangZhong, Role* ZhangFei, Role* S1, Role* S2, Role* S3, Role* S4)const;
	//����û�õĺ���

};



/*void optimum::movebyoptimum(Role* CaoCao, Role* GuanYu, Role* ZhaoYun, Role* MaChao, Role* HuangZhong, Role* ZhangFei, Role* S1, Role* S2, Role* S3, Role* S4)const
{
	for (int i = 0; i < step; ++i)
	{
		movewhichwhere(nametable[i], dirtable[i], CaoCao, GuanYu, ZhaoYun, MaChao, HuangZhong, ZhangFei, S1, S2, S3, S4);//�ƶ�һ��
		//�������գ��벹�䡰��ͼ�λ�������ʾ�ƶ��������ĺ���
	}
}*/

//movewhichwhere(route.nametable[i], route.dirtable[i], CaoCao, GuanYu, ZhaoYun, MaChao, HuangZhong, ZhangFei, S1, S2, S3, S4);//����ʾ��
