#pragma once
#include <string>
struct point{ int x; int y; };
//缺：棋盘移动刷新函数
//
class Interface
{
public:
	static enum Music{bgm,yell,mute};//三个音乐选项，未实现
	static enum Option{move,help,revoke,music,restart,exit};
	point MovePoint;//移动点的逻辑坐标
	void Begin();
	int Select();
	void GameInit(int num);
	Option Click();
	void stepwrite(int snum);
	void lifewrite(int lnum);
	void Help(std::string code);
	void UselesStep();
	void Revoke();
private:
	void TipReflesh();
};

