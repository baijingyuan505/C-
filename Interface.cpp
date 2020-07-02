#include "Interface.h"
#include <easyx.h>
#include <conio.h>
#include <stdlib.h>
#include <sstream>
#include <stdio.h>
#define wid 800
#define hei 700
using namespace std;

point c[5] = { { 200,50 },{ 200,50 },{ 200,50 },{ 200,50 } ,{ 200,50 } };
point s1[5] = { { 100,50 },{ 100,50 },{100,350 },{100,250},{100,350} };
point s2[5] = { { 100,150 },{100,150},{100,450},{100,350},{100,450} };
point s3[5] = { { 400,50 } ,{400,50},{400,350},{400,250},{400,350} };
point s4[5] = { { 400,150 },{400,150},{400,450},{400,350},{400,450} };
point m[5] = { { 100,250 },{200,250},{300,250},{200,250},{100,250} };
point h[5] = { { 300,250 },{100,250},{200,250},{400,50},{300,250} };
point zf[5] = { { 100,350 },{300,350}, {100,50},{300,450}, {100,50} };
point zy[5] = { { 300,350 }, {200,450} , {400,50},{100,50}, {400,50} };
point g[5] = { { 200,450 },{300,250},{200,450},{100,450},{200,350} };

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
				gameselect();
				break;
			}
			else if (ms.x >= 280 && ms.x <= 430 && ms.y >= 400 && ms.y <= 470)
			{
				closegraph();
				gameselect();
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
	/*


	美化操作感预留空间



	*/

	putimage(0, 0, &back_pic1);
	putimage(300, 30, &buttom_BT);             //选关标题贴图
	putimage(360, 130, &buttom_x2);            //过五关贴图
	putimage(360, 180, &buttom_x3);            //层层设防
	putimage(360, 230, &buttom_x4);            //左右布兵
	putimage(360, 280, &buttom_x5);            //插翅难飞
	putimage(360, 330, &buttom_x6);            //小燕出巢
	putimage(270, 400, &buttom_YL);             //演练功能
	putimage(450, 400, &buttom_CF);            //出发功能
	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	MOUSEMSG ms2 = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	int levelselect;
	int modeselect;
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
//提示栏刷新函数
void Interface::TipReflesh()  
{
	IMAGE tip;
	loadimage(&tip, _T("D:\\cpicture\\tip.png"), 400, 170);
	putimage(550, 10, &tip);
}
//初始化游戏棋盘
void Interface::GameInit(int num)
{
	initgraph(wid, hei);
	IMAGE bg2;//背景贴图
	IMAGE chart;
	IMAGE function;

	IMAGE cchess;//以下
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
	IMAGE s4chess;//至此为棋子贴图

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
	loadimage(&cchess, _T("D:\\cpicture\\c.png"), 200, 200);
	//加载棋子贴图
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
	//人物图案显示
	putimage(c[num - 1].x, c[num - 1].y, &cchess);
	putimage(zf[num - 1].x, zf[num - 1].y, &zf1chess);
	putimage(m[num - 1].x, m[num - 1].y, &m1chess);
	putimage(h[num - 1].x, h[num - 1].y, &hz1chess);
	putimage(g[num - 1].x, g[num - 1].y, &gchess);
	putimage(zy[num - 1].x, zy[num - 1].y, &zy1chess);
	putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
	putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
	putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
	putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);
	//状态栏图标显示
	putimage(680, 220, &step);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &revoke);
	putimage(680, 420, &music);
	putimage(680, 470, &restart);
	putimage(680, 520, &exit);
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
				return Option::move;
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
	settextcolor(WHITE);
	settextstyle(10, 8, _T("宋体"));
	char a[3];
	sprintf(a, "%d", snum);
	outtextxy(700, 240, a);
}
//更新现在的生命值
void Interface::lifewrite(int lnum)
{
	settextcolor(WHITE);
	settextstyle(10, 8, _T("宋体"));
	char b[3];
	sprintf(b, "%d", lnum);
	outtextxy(700, 300, b);
}
//使用帮助功能
void Interface::Help(std::string code)
{
	IMAGE Role;//角色提示
	IMAGE Dir;//方向提示
	char role = code[0];
	char dir = code[1];
	switch (role)
	{
	case '1':
		loadimage(&Role, _T("D:\\cpicture\\tip_c.png"), 60, 60);
		break;
	case '2':
		loadimage(&Role, _T("D:\\cpicture\\tip_g.png"), 60, 60);
		break;
	case '3':
		loadimage(&Role, _T("D:\\cpicture\\tip_m.png"), 60, 60);
		break;
	case '4':
		loadimage(&Role, _T("D:\\cpicture\\tip_h.png"), 60, 60);
		break;
	case '5':
		loadimage(&Role, _T("D:\\cpicture\\tip_zf.png"), 60, 60);
		break;
	case '6':
		loadimage(&Role, _T("D:\\cpicture\\tip_zy.png"), 60, 60);
		break;
	case '7':
		loadimage(&Role, _T("D:\\cpicture\\tip_s1.png"), 60, 60);
		break;
	case '8':
		loadimage(&Role, _T("D:\\cpicture\\tip_s2.png"), 60, 60);
		break;
	case '9':
		loadimage(&Role, _T("D:\\cpicture\\tip_s3.png"), 60, 60);
		break;
	case '10':
		loadimage(&Role, _T("D:\\cpicture\\tip_s4.png"), 60, 60);
		break;
	}
	switch (dir)
	{
	case '1':
		loadimage(&Dir, _T("D:\\cpicture\\up.png"), 60, 60);
		break;
	case '2':
		loadimage(&Dir, _T("D:\\cpicture\\down.png"), 60, 60);
		break;
	case '3':
		loadimage(&Dir, _T("D:\\cpicture\\left.png"), 60, 60);
		break;
	case '4':
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


