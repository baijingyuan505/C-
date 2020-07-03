#include "Interface.h"
#include <easyx.h>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>

#define wid 800
#define hei 700
using namespace std;

//游戏开始界面
void Interface::Begin()
{
	IMAGE back_pic1;
	IMAGE title;
	IMAGE buttom_1;
	IMAGE buttom_2;
	IMAGE buttom_3;
	IMAGE buttom_r1;
	IMAGE buttom_r2;
	IMAGE buttom_r3;
	loadimage(&back_pic1, _T("D:\\cpicture\\scene.jpg"), 800, 700);
	loadimage(&title, _T("D:\\cpicture\\title.png"), 300, 150);
	loadimage(&buttom_1, _T("D:\\cpicture\\buttom1.png"), 150, 70);
	loadimage(&buttom_2, _T("D:\\cpicture\\buttom2.png"), 150, 70);
	loadimage(&buttom_3, _T("D:\\cpicture\\buttom3.png"), 150, 70);

	initgraph(wid, hei);
	putimage(0, 0, &back_pic1);
	putimage(250, 10, &title);
	putimage(80, 400, &buttom_1);
	putimage(280, 400, &buttom_2);
	putimage(480, 400, &buttom_3);

	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	while (true)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONDOWN)
		{
			if (ms.x >= 80 && ms.x <= 230 && ms.y >= 400 && ms.y <= 470)
			{
				loadimage(&buttom_r1, _T("D:\\cpicture\\buttom1.png"), 200, 100);
				putimage(55, 385, &buttom_r1);
			}
			else if (ms.x >= 280 && ms.x <= 430 && ms.y >= 400 && ms.y <= 470)
			{
				loadimage(&buttom_r2, _T("D:\\cpicture\\buttom2.png"), 200, 100);
				putimage(255, 385, &buttom_r2);
			}
			else if (ms.x >= 480 && ms.x <= 630 && ms.y >= 400 && ms.y <= 470)
			{
				loadimage(&buttom_r3, _T("D:\\cpicture\\buttom3.png"), 200, 100);
				putimage(455, 385, &buttom_r3);
			}
		}
		if (ms.uMsg == WM_LBUTTONUP)
		{
			if (ms.x >= 80 && ms.x <= 230 && ms.y >= 400 && ms.y <= 470)
			{
				closegraph();
				break;
			}
			else if (ms.x >= 280 && ms.x <= 430 && ms.y >= 400 && ms.y <= 470)
			{
				closegraph();
				break;
			}
			else if (ms.x >= 480 && ms.x <= 630 && ms.y >= 400 && ms.y <= 470)
			{
				closegraph();
				break;
			}
		}
		else {
			;
		}
	}
}
//关卡选择
int Interface::Select()
{
	initgraph(wid, hei);
	IMAGE back_pic1;
	IMAGE buttom_x1;           //选关（x2~x6）
	IMAGE buttom_x2;
	IMAGE buttom_x3;
	IMAGE buttom_x4;
	IMAGE buttom_x5;
	IMAGE buttom_x6;
	IMAGE buttom_YL;          //演练按钮
	IMAGE buttom_CF;          //出发按钮
	IMAGE buttom_BT;          //标题贴图导入

	IMAGE buttom_rx1;         //buttom_r开头的均用于进行鼠标单击反馈
	IMAGE buttom_rx2;
	IMAGE buttom_rx3;
	IMAGE buttom_rx4;
	IMAGE buttom_rx5;
	IMAGE buttom_rx6;
	IMAGE buttom_rYL;
	IMAGE buttom_rCF;
	IMAGE buttom_rBT;

	loadimage(&back_pic1, _T("D:\\cpicture\\background1.jpg"), 800, 700);   	//选关界面背景
	loadimage(&buttom_BT, _T("D:\\cpicture\\stitle.png"), 200, 100);       //选关标题
	loadimage(&buttom_x2, _T("D:\\cpicture\\sbuttom1.png"), 80, 40);     //过五关
	loadimage(&buttom_x3, _T("D:\\cpicture\\sbuttom2.png"), 80, 40);     //层层设防
	loadimage(&buttom_x4, _T("D:\\cpicture\\sbuttom3.png"), 80, 40);     //左右布兵
	loadimage(&buttom_x5, _T("D:\\cpicture\\sbuttom4.png"), 80, 40);     //插翅难飞
	loadimage(&buttom_x6, _T("D:\\cpicture\\sbuttom5.png"), 80, 40);     //小燕出巢
	loadimage(&buttom_YL, _T("D:\\cpicture\\sbuttomYL.png"), 80, 50);     //演练按钮
	loadimage(&buttom_CF, _T("D:\\cpicture\\sbuttomCF.png"), 80, 50);     //出发按钮

	loadimage(&buttom_rx2, _T("D:\\cpicture\\sbuttom1.png"), 80, 40);

	putimage(0, 0, &back_pic1);
	putimage(300, 30, &buttom_BT);             //选关标题贴图
	putimage(360, 130, &buttom_x2);            //过五关
	putimage(360, 180, &buttom_x3);            //层层设防
	putimage(360, 230, &buttom_x4);            //左右布兵
	putimage(360, 280, &buttom_x5);            //插翅难飞
	putimage(360, 330, &buttom_x6);            //小燕出巢
	putimage(270, 400, &buttom_YL);             //演练功能
	putimage(450, 400, &buttom_CF);            //出发功能
	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	int levelselect;
	while (true)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{
			if (ms.x >= 360 && ms.x <= 440 && ms.y >= 130 && ms.y <= 170)
			{
				levelselect = 1;
				break;
			}
			else if (ms.x >= 360 && ms.x <= 440 && ms.y >= 180 && ms.y <= 220)
			{
				levelselect = 2;
				break;
			}
			else if (ms.x >= 360 && ms.x <= 440 && ms.y >= 230 && ms.y <= 270)
			{
				levelselect = 3;
				break;
			}
			else if (ms.x >= 360 && ms.x <= 440 && ms.y >= 280 && ms.y <= 320)
			{
				levelselect = 4;
				break;
			}
			else if (ms.x >= 360 && ms.x <= 440 && ms.y >= 330 && ms.y <= 370)
			{
				levelselect = 5;
				break;
			}

		}

	}
	return levelselect;
}
//模式选择
Interface::Mode Interface::Choose()
{
	MOUSEMSG ms2 = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	while (true)
	{
		ms2 = GetMouseMsg();
		if (ms2.uMsg == WM_LBUTTONUP) {
			if (ms2.x >= 270 && ms2.x <= 350 && ms2.y >= 400 && ms2.y <= 450)
			{
				closegraph();
				return Mode::show;
				break;
			}
			else if (ms2.x >= 450 && ms2.x <= 530 && ms2.y >= 400 && ms2.y <= 450)
			{
				closegraph();
				return Mode::play;
				break;
			}
		}	
	}
}
//提示栏刷新函数
void Interface::TipReflesh()
{
	IMAGE tip;
	loadimage(&tip, _T("D:\\cpicture\\tip.png"), 400, 170);
	putimage(550, 10, &tip);
}
//初始化游戏棋盘
void Interface::GameInit(int num, int(&InitLocate)[10][2])
{
	for (int i = 0; i < 10; ++i) {
		RefleshLocate[i][0] = InitLocate[i][0]+1;
		RefleshLocate[i][1] = InitLocate[i][1]+1;
	}
	initgraph(wid, hei);
	IMAGE bg2;//背景贴图
	IMAGE chart;
	IMAGE function;

	IMAGE step;//以下
	IMAGE life;
	IMAGE help;
	IMAGE revoke;
	IMAGE music;
	IMAGE drum;
	IMAGE say;
	IMAGE quite;
	IMAGE restart;
	IMAGE exit;//至此为按钮贴图

	//加载背景
	loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
	//加载按钮贴图
	loadimage(&step, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
	loadimage(&revoke, _T("D:\\cpicture\\back.png"), 120, 40);
	loadimage(&music, _T("D:\\cpicture\\voice.png"), 120, 40);
	loadimage(&restart, _T("D:\\cpicture\\return.png"), 120, 40);
	loadimage(&exit, _T("D:\\cpicture\\quit.png"), 120, 40);
	loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
	loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
	loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
	//背景显示
	putimage(0, 0, &bg2);
	putimage(100, 20, &chart);
	putimage(550, 5, &function);
	//状态栏图标显示
	putimage(680, 220, &step);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &revoke);
	putimage(680, 420, &music);
	putimage(680, 470, &restart);
	putimage(680, 520, &exit);

	DrawBoard();
}
//游戏中的点击操作
Interface::Option Interface::Click()
{

	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	while (1)
	{
		MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{
			if (ms.x >= 100 && ms.x <= 500 && ms.y >= 20 && ms.y <= 620)
			{
				MovePoint.x = ms.x / 100;
				MovePoint.y = ms.y / 100;
				!movearg;
				return Option::move;
			}
			if (ms.x >= 100 && ms.x <= 500 && ms.y >= 20 && ms.y <= 620 && movearg)
			{
				MovePoint.x = ms.x / 100;
				MovePoint.y = ms.y / 100;
				!movearg;
				return Option::direction;
			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 320 && ms.y <= 360)
				return Option::help;
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)
				return Option::revoke;
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 420 && ms.y <= 460)
				return Option::music;
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)
				return Option::restart;
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 520 && ms.y <= 560)
			{
				closegraph();
				return Option::exit;
			}
		}
	}

}
//更新现在走的步数
void Interface::stepwrite(int snum)
{
	IMAGE step;
	loadimage(&step, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	putimage(680, 220, &step);
	settextcolor(WHITE);
	settextstyle(10, 8, _T("宋体"));
	char a[3];
	sprintf_s(a, "%d", snum);
	outtextxy(700, 240, a);
}
//更新现在的生命值
void Interface::lifewrite(int lnum)
{
	IMAGE life;
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	putimage(680, 270, &life);
	settextcolor(WHITE);
	settextstyle(10, 8, _T("宋体"));
	char b[3];
	sprintf_s(b, "%d", lnum);
	outtextxy(700, 300, b);
}
//使用帮助功能
void Interface::Help(int code)
{
	IMAGE Role;//角色提示
	IMAGE Dir;//方向提示
	int role = code / 10;
	int dir = code % 10;
	switch (role)
	{
	case 1:
		loadimage(&Role, _T("D:\\cpicture\\tip_c.png"), 60, 60);
		break;
	case 2:
		loadimage(&Role, _T("D:\\cpicture\\tip_g.png"), 60, 60);
		break;
	case 3:
		loadimage(&Role, _T("D:\\cpicture\\tip_m.png"), 60, 60);
		break;
	case 4:
		loadimage(&Role, _T("D:\\cpicture\\tip_h.png"), 60, 60);
		break;
	case 5:
		loadimage(&Role, _T("D:\\cpicture\\tip_zf.png"), 60, 60);
		break;
	case 6:
		loadimage(&Role, _T("D:\\cpicture\\tip_zy.png"), 60, 60);
		break;
	case 7:
		loadimage(&Role, _T("D:\\cpicture\\tip_s1.png"), 60, 60);
		break;
	case 8:
		loadimage(&Role, _T("D:\\cpicture\\tip_s2.png"), 60, 60);
		break;
	case 9:
		loadimage(&Role, _T("D:\\cpicture\\tip_s3.png"), 60, 60);
		break;
	case 10:
		loadimage(&Role, _T("D:\\cpicture\\tip_s4.png"), 60, 60);
		break;
	}
	switch (dir)
	{
	case 1:
		loadimage(&Dir, _T("D:\\cpicture\\up.png"), 60, 60);
		break;
	case 2:
		loadimage(&Dir, _T("D:\\cpicture\\down.png"), 60, 60);
		break;
	case 3:
		loadimage(&Dir, _T("D:\\cpicture\\left.png"), 60, 60);
		break;
	case 4:
		loadimage(&Dir, _T("D:\\cpicture\\right.png"), 60, 60);
		break;
	}
	//打印提示贴图
	putimage(570, 20, &Role);
	putimage(570, 20, &Dir);
}
//满足无用功条件
void Interface::UselesStep()
{
	IMAGE wei;
	loadimage(&wei, _T("D:\\cpicture\\wei.png"), 100, 40);
	putimage(570, 20, &wei);
}
//使用回退功能
void Interface::Revoke()
{
	IMAGE ht;
	loadimage(&ht, _T("D:\\cpicture\\ht.png"), 100, 40);
	putimage(600, 80, &ht);
}
//棋盘贴图的刷新
void Interface::BoardReflesh(int state, int x, int y)
{
	RefleshLocate[state - 1][0] = x;
	RefleshLocate[state - 1][1] = y;
	DrawBoard();
	
}
void Interface::BoardReflesh(int state, int DirCode)
{
	switch (DirCode) {
	case 1://向上
		RefleshLocate[state - 1][1]--;
		break;
	case 2://向下
		RefleshLocate[state - 1][1]++;
		break;
	case 3://向左
		RefleshLocate[state - 1][0]--;
		break;
	case 4:
		RefleshLocate[state - 1][0]++;
		break;
	}
	DrawBoard();
}
void Interface::DrawBoard()
{
	IMAGE chart;
	IMAGE cchess;
	IMAGE gchess;
	IMAGE zf1chess;
	IMAGE zf2chess;
	IMAGE zy1chess;
	IMAGE zy2chess;
	IMAGE hz1chess;
	IMAGE hz2chess;
	IMAGE m1chess;
	IMAGE m2chess;
	IMAGE s1chess;
	IMAGE s2chess;
	IMAGE s3chess;
	IMAGE s4chess;

	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&cchess, _T("D:\\cpicture\\c.png"), 200, 200);
	loadimage(&zf1chess, _T("D:\\cpicture\\zf1.png"), 200, 100);
	loadimage(&zf2chess, _T("D:\\cpicture\\zf2.png"), 100, 200);
	loadimage(&zy1chess, _T("D:\\cpicture\\zy1.png"), 200, 100);
	loadimage(&zy2chess, _T("D:\\cpicture\\zy2.png"), 100, 200);
	loadimage(&m1chess, _T("D:\\cpicture\\m1.png"), 200, 100);
	loadimage(&m2chess, _T("D:\\cpicture\\m2.png"), 100, 200);
	loadimage(&hz1chess, _T("D:\\cpicture\\h1.png"), 200, 100);
	loadimage(&hz2chess, _T("D:\\cpicture\\h2.png"), 100, 200);
	loadimage(&gchess, _T("D:\\cpicture\\g.png"), 200, 100);
	loadimage(&s1chess, _T("D:\\cpicture\\s1.png"), 100, 100);
	loadimage(&s2chess, _T("D:\\cpicture\\s2.png"), 100, 100);
	loadimage(&s3chess, _T("D:\\cpicture\\s3.png"), 100, 100);
	loadimage(&s4chess, _T("D:\\cpicture\\s4.png"), 100, 100);

	putimage(100, 20, &chart);
	putimage(100 * RefleshLocate[0][0], 100 * RefleshLocate[0][1], &cchess);
	putimage(100 * RefleshLocate[1][0], 100 * RefleshLocate[1][1], &zf1chess);
	putimage(100 * RefleshLocate[2][0], 100 * RefleshLocate[2][1], &m1chess);
	putimage(100 * RefleshLocate[3][0], 100 * RefleshLocate[3][1], &hz1chess);
	putimage(100 * RefleshLocate[4][0], 100 * RefleshLocate[4][1], &gchess);
	putimage(100 * RefleshLocate[5][0], 100 * RefleshLocate[5][1], &zy1chess);
	putimage(100 * RefleshLocate[6][0], 100 * RefleshLocate[6][1], &s1chess);
	putimage(100 * RefleshLocate[7][0], 100 * RefleshLocate[7][1], &s2chess);
	putimage(100 * RefleshLocate[8][0], 100 * RefleshLocate[8][1], &s3chess);
	putimage(100 * RefleshLocate[9][0], 100 * RefleshLocate[9][1], &s4chess);
}