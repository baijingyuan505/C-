#pragma once
struct Location
{
	int x;
	int y;
};

class games
{
public:
	Location caocao;
	Location guanyu;
	Location machao;
	Location zhaoyun;
	Location huangzhong;
	Location zhangfei;
	Location soldier1;
	Location soldier2;
	Location soldier3;
	Location soldier4;
	int stepnum = 0;
	int score = 100;

	games(Location c, Location g, Location m, Location zy, Location h, Location zf, Location s1, Location s2, Location s3, Location s4)
		:caocao(c), guanyu(g), machao(m), zhaoyun(zy), huangzhong(h), zhangfei(zf), soldier1(s1), soldier2(s2), soldier3(s3), soldier4(s4) {};
	~games() {};
};

