#ifndef LOGIC_H
#define LOGIC_H
#include <vector>
#include "optimum.h"
#endif
class Logic
{
private:
	struct move { int role; int dir; };//一次移动的记录
	std::vector<move> Optimum;//存储本关的最优解
	bool OutOfRoute = false;//是否偏离了最优解路线
	int Point = 0;//目前行走在最优解路线上的点
	move Move;//玩家的一次操作
	int DirTrans[4] = { 1,-1,2,-2 };//对移动方向的代号0,1,2,3进行转换
	std::vector<move>HelpRoute;//偏离最优路线后的记录路线
	int MoveCheck[10] = { 0 };//检查所有棋子的位置变化
	int UselesStep = 0;
	bool UsedHelp = false;//是否使用了帮助
	bool UsedRevoke = false;//是否使用了回退
	int step;
public:
	int Cnt = 0;//目前行走的步数
	int score = 100;//游戏得分（生命值）
	void Load(std::vector<int>& nametable, std::vector<int>& dirtable);//录入最优解
	void Record(int RoleCode, int DirCode);//记录玩家的移动
	bool Examine();//检查无用功函数
	int Help();//帮助功能
	bool Revoke();//回退功能
	void Value();//进行评分
	Logic(int stage);
};

