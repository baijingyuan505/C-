#pragma once
struct point { int x; int y; };
class Interface
{
public:
	static enum Music { bgm, yell, mute };//��������ѡ�δʵ��
	static enum Option { move, help, revoke, music, restart, exit, direction };
	bool movearg = 0;
	point MovePoint;//�ƶ�����߼�����
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

