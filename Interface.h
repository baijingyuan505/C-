#pragma once
#include <string>
struct point{ int x; int y; };
//ȱ�������ƶ�ˢ�º���
//
class Interface
{
public:
	static enum Music{bgm,yell,mute};//��������ѡ�δʵ��
	static enum Option{move,help,revoke,music,restart,exit};
	point MovePoint;//�ƶ�����߼�����
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

