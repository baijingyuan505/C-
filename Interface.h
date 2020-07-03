#pragma once
struct point { int x; int y; };
class Interface
{
public:
	static enum Music { bgm, yell, mute };//三个音乐选项，未实现
	static enum Option { move, help, revoke, music, restart, exit, direction };
	bool movearg = 0;
	point MovePoint;//移动点的逻辑坐标
	void Begin();
	int Select();
	void GameInit(int num,int (&InitLocate)[10][2]);
	void BoardReflesh(int state,int x,int y);
	Option Click();
	void stepwrite(int snum);
	void lifewrite(int lnum);
	void Help(int code);
	void UselesStep();
	void Revoke();
private:
	int RefleshLocate[10][2] = { 0 };
	void TipReflesh();
};

