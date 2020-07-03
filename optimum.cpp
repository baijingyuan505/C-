#include "optimum.h"

optimum::optimum(int n) {
	nametable.clear();
	dirtable.clear();
	//记录了最优解操作的表，格式为每20个操作单字换一行，即一行20个元素
	name Stage1_Name[48] = {
		name::关,name::赵,name::黄,name::勇,name::勇,name::卒,name::卒,name::曹,name::丁,name::丁,name::马,name::张,name::关,name::赵,name::赵,name::黄,name::勇,name::卒,name::曹,name::丁,
		name::丁,name::兵,name::兵,name::马,name::张,name::关,name::赵,name::黄,name::黄,name::勇,name::卒,name::曹,name::张,name::张,name::关,name::赵,name::黄,name::勇,name::勇,name::卒,
		name::卒,name::曹,name::赵,name::赵,name::黄,name::卒,name::卒,name::曹 };
	dir Stage1_Dir[48] = {
		dir::左,dir::下,dir::下,dir::下,dir::左,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::下,dir::下,dir::右,
		dir::右,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::左,dir::左,dir::左,
		dir::左,dir::下,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左 };
	//《过五关》37步

	name Stage2_Name[62] = {
		name::赵,name::黄,name::马,name::丁,name::丁,name::兵,name::兵,name::曹,name::勇,name::勇,name::关,name::丁,name::丁,name::兵,name::兵,name::曹,name::勇,name::勇,name::卒,name::卒,
		name::关,name::兵,name::兵,name::曹,name::黄,name::黄,name::马,name::张,name::赵,name::丁,name::丁,name::兵,name::兵,name::曹,name::黄,name::马,name::马,name::张,name::赵,name::兵,
		name::兵,name::曹,name::关,name::卒,name::卒,name::勇,name::勇,name::马,name::黄,name::张,name::赵,name::兵,name::兵,name::丁,name::丁,name::曹,name::张,name::张,name::赵,name::丁,
		name::丁,name::曹 };
	dir Stage2_Dir[62] = {
		dir::右,dir::下,dir::下,dir::下,dir::右,dir::下,dir::下,dir::左,dir::左,dir::上,dir::上,dir::右,dir::右,dir::右,dir::右,dir::下,dir::左,dir::左,dir::左,dir::左,
		dir::上,dir::上,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左,dir::左,dir::下,dir::下,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左,dir::左,
		dir::下,dir::下,dir::下,dir::右,dir::右,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::左,dir::左,dir::下,dir::右,dir::上,dir::上,dir::上,
		dir::左,dir::左 };
	//《层层设防》44步

	name Stage3_Name[90] = {
		name::兵,name::丁,name::关,name::勇,name::卒,name::赵,name::赵,name::曹,name::张,name::兵,name::兵,name::丁,name::丁,name::黄,name::张,name::张,name::曹,name::赵,name::赵,name::马,
		name::勇,name::勇,name::卒,name::卒,name::关,name::关,name::黄,name::张,name::勇,name::勇,name::曹,name::兵,name::兵,name::丁,name::丁,name::勇,name::勇,name::黄,name::黄,name::张,
		name::卒,name::卒,name::曹,name::兵,name::兵,name::赵,name::马,name::马,name::曹,name::兵,name::兵,name::丁,name::勇,name::黄,name::张,name::卒,name::兵,name::曹,name::马,name::马,
		name::赵,name::勇,name::丁,name::黄,name::张,name::张,name::曹,name::丁,name::丁,name::勇,name::勇,name::赵,name::马,name::马,name::丁,name::丁,name::关,name::兵,name::兵,name::卒,
		name::卒,name::曹,name::勇,name::勇,name::丁,name::丁,name::关,name::卒,name::卒,name::曹 };
	dir Stage3_Dir[90] = {
		dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::下,dir::下,dir::左,dir::上,dir::上,dir::右,
		dir::上,dir::上,dir::左,dir::上,dir::右,dir::右,dir::下,dir::下,dir::左,dir::左,dir::下,dir::右,dir::右,dir::上,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,
		dir::左,dir::下,dir::下,dir::下,dir::左,dir::左,dir::上,dir::上,dir::右,dir::下,dir::下,dir::下,dir::右,dir::上,dir::上,dir::左,dir::下,dir::左,dir::下,dir::下,
		dir::右,dir::右,dir::右,dir::右,dir::上,dir::上,dir::左,dir::下,dir::下,dir::下,dir::下,dir::左,dir::上,dir::上,dir::右,dir::上,dir::上,dir::右,dir::右,dir::右,
		dir::右,dir::下,dir::左,dir::左,dir::左,dir::左,dir::上,dir::上,dir::右,dir::右 };
	//《左右布兵》62步

	name Stage4_Name[125] = {
		name::卒,name::勇,name::黄,name::黄,name::曹,name::马,name::马,name::丁,name::丁,name::关,name::张,name::张,name::黄,name::卒,name::勇,name::丁,name::兵,name::关,name::赵,name::赵,
		name::马,name::曹,name::卒,name::卒,name::丁,name::丁,name::兵,name::兵,name::关,name::勇,name::勇,name::张,name::赵,name::关,name::兵,name::兵,name::关,name::关,name::赵,name::张,
		name::兵,name::勇,name::赵,name::马,name::马,name::曹,name::丁,name::丁,name::关,name::黄,name::勇,name::兵,name::张,name::张,name::马,name::赵,name::曹,name::丁,name::丁,name::卒,
		name::卒,name::关,name::勇,name::勇,name::曹,name::马,name::马,name::赵,name::兵,name::兵,name::曹,name::卒,name::卒,name::丁,name::丁,name::关,name::关,name::勇,name::勇,name::黄,
		name::黄,name::曹,name::丁,name::丁,name::马,name::赵,name::赵,name::丁,name::丁,name::马,name::卒,name::勇,name::关,name::赵,name::马,name::曹,name::黄,name::黄,name::关,name::勇,
		name::卒,name::赵,name::马,name::马,name::曹,name::卒,name::勇,name::黄,name::张,name::兵,name::兵,name::丁,name::丁,name::曹,name::马,name::赵,name::关,name::关,name::勇,name::卒,
		name::黄,name::张,name::丁,name::丁,name::曹 };
	dir Stage4_Dir[125] = {
		dir::左,dir::左,dir::下,dir::下,dir::右,dir::上,dir::上,dir::右,dir::上,dir::上,dir::左,dir::左,dir::下,dir::右,dir::下,dir::右,dir::右,dir::右,dir::下,dir::下,
		dir::左,dir::左,dir::上,dir::上,dir::右,dir::上,dir::右,dir::右,dir::上,dir::上,dir::左,dir::右,dir::下,dir::左,dir::左,dir::下,dir::右,dir::右,dir::上,dir::左,
		dir::下,dir::右,dir::右,dir::下,dir::下,dir::左,dir::左,dir::上,dir::上,dir::上,dir::上,dir::上,dir::右,dir::右,dir::下,dir::下,dir::下,dir::左,dir::左,dir::左,
		dir::左,dir::上,dir::上,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::下,dir::右,dir::右,dir::下,dir::左,dir::左,dir::上,dir::左,dir::上,
		dir::上,dir::右,dir::下,dir::下,dir::右,dir::上,dir::上,dir::左,dir::下,dir::下,dir::左,dir::下,dir::右,dir::上,dir::左,dir::左,dir::下,dir::下,dir::右,dir::右,
		dir::右,dir::右,dir::上,dir::上,dir::左,dir::下,dir::左,dir::上,dir::上,dir::右,dir::右,dir::右,dir::右,dir::下,dir::下,dir::下,dir::左,dir::左,dir::上,dir::上,
		dir::上,dir::上,dir::上,dir::右,dir::右 };
	//《插翅难飞》90步

	name Stage5_Name[178] = {
		name::关,name::卒,name::卒,name::勇,name::勇,name::关,name::卒,name::勇,name::黄,name::马,name::马,name::兵,name::勇,name::丁,name::卒,name::关,name::关,name::黄,name::卒,name::勇,
		name::马,name::卒,name::卒,name::黄,name::关,name::关,name::丁,name::丁,name::兵,name::兵,name::张,name::张,name::曹,name::赵,name::卒,name::马,name::勇,name::丁,name::兵,name::张,
		name::勇,name::马,name::卒,name::赵,name::曹,name::勇,name::勇,name::张,name::张,name::丁,name::兵,name::黄,name::关,name::卒,name::卒,name::赵,name::赵,name::曹,name::勇,name::张,
		name::丁,name::兵,name::关,name::卒,name::赵,name::马,name::丁,name::丁,name::马,name::赵,name::卒,name::关,name::兵,name::张,name::张,name::勇,name::丁,name::曹,name::赵,name::赵,
		name::卒,name::卒,name::关,name::兵,name::张,name::马,name::卒,name::赵,name::赵,name::曹,name::丁,name::丁,name::马,name::张,name::兵,name::关,name::赵,name::卒,name::曹,name::丁,
		name::丁,name::勇,name::勇,name::马,name::卒,name::卒,name::曹,name::丁,name::丁,name::勇,name::勇,name::马,name::马,name::卒,name::卒,name::张,name::张,name::兵,name::兵,name::黄,
		name::关,name::赵,name::丁,name::丁,name::勇,name::勇,name::曹,name::兵,name::张,name::卒,name::马,name::马,name::曹,name::赵,name::勇,name::丁,name::关,name::关,name::黄,name::张,
		name::卒,name::兵,name::赵,name::勇,name::勇,name::曹,name::马,name::马,name::卒,name::兵,name::张,name::赵,name::黄,name::关,name::关,name::勇,name::丁,name::曹,name::马,name::兵,
		name::兵,name::卒,name::卒,name::张,name::赵,name::黄,name::关,name::勇,name::勇,name::丁,name::丁,name::曹,name::黄,name::黄,name::关,name::丁,name::丁,name::曹 };
	dir Stage5_Dir[178] = {
		dir::下,dir::左,dir::左,dir::上,dir::左,dir::右,dir::下,dir::左,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::下,dir::右,dir::下,
		dir::左,dir::右,dir::上,dir::上,dir::右,dir::右,dir::下,dir::右,dir::下,dir::下,dir::下,dir::下,dir::左,dir::左,dir::上,dir::右,dir::上,dir::上,dir::右,dir::下,
		dir::左,dir::左,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::左,dir::左,dir::下,dir::下,dir::下,dir::下,dir::右,dir::右,dir::上,
		dir::上,dir::上,dir::左,dir::左,dir::下,dir::右,dir::右,dir::上,dir::左,dir::上,dir::右,dir::右,dir::下,dir::下,dir::下,dir::左,dir::左,dir::左,dir::上,dir::上,
		dir::上,dir::上,dir::右,dir::右,dir::下,dir::左,dir::左,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::左,dir::左,dir::下,dir::左,dir::下,dir::右,
		dir::右,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::右,dir::下,dir::右,dir::右,dir::上,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,
		dir::左,dir::左,dir::下,dir::下,dir::下,dir::下,dir::右,dir::右,dir::下,dir::下,dir::左,dir::左,dir::上,dir::上,dir::上,dir::上,dir::右,dir::右,dir::下,dir::下,
		dir::左,dir::上,dir::左,dir::左,dir::下,dir::下,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::下,dir::下,dir::下,dir::下,dir::右,
		dir::右,dir::右,dir::右,dir::上,dir::上,dir::上,dir::上,dir::左,dir::左,dir::左,dir::左,dir::下,dir::右,dir::右,dir::上,dir::上,dir::左,dir::左 };
	//《小燕出巢》131步

	switch (n) {//构造函数的主体部分
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