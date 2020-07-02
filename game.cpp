#include <easyx.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include "game.h"
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

#define wid 800
#define hei 700

 Location c[5] = { { 200,50 },{ 200,50 },{ 200,50 },{ 200,50 } ,{ 200,50 } };      //过五关相关参数
 Location s1[5] = { { 100,50 },{ 100,50 },{100,350 },{100,250},{100,350} };
 Location s2[5] = { { 100,150 },{100,150},{100,450},{100,350},{100,450} };
 Location s3[5] = { { 400,50 } ,{400,50},{400,350},{400,250},{400,350} };
 Location s4[5] = { { 400,150 },{400,150},{400,450},{400,350},{400,450} };
 Location m[5] = { { 100,250 },{200,250},{300,250},{200,250},{100,250} };
 Location h[5] = { { 300,250 },{100,250},{200,250},{400,50},{300,250} };
 Location zf[5] = { { 100,350 },{300,350}, {100,50},{300,450}, {100,50} };
 Location zy[5] = { { 300,350 }, {200,450} , {400,50},{100,50}, {400,50} };
 Location g[5] = { { 200,450 },{300,250},{200,450},{100,450},{200,350} };

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
 IMAGE up;
 IMAGE down;
 IMAGE t_left;
 IMAGE t_right;
 IMAGE tip_c;
 IMAGE tip_m;
 IMAGE tip_g;
 IMAGE tip_h;
 IMAGE tip_zy;
 IMAGE tip_zf;
 IMAGE tip_s1;
 IMAGE tip_s2;
 IMAGE tip_s3;
 IMAGE tip_s4;
 
 int tip_select_chess = 0;       //提示栏的棋子选择标志位
 int tip_select_toward = 0;      //提示栏的方向选择标志位
 

void gameselect();
void start1(int num);
void start2(int num);
void start3(int num);
void start4(int num);
void start5(int num);
//棋子的初始位置
games game[5] = {
	games(c[0],g[0],m[0],zy[0],h[0],zf[0],s1[0],s2[0],s3[0],s4[0]),
	games(c[1],g[1],m[1],zy[1],h[1],zf[1],s1[1],s2[1],s3[1],s4[1]),
	games(c[2],g[2],m[2],zy[2],h[2],zf[2],s1[2],s2[2],s3[2],s4[2]),
	games(c[3],g[3],m[3],zy[3],h[3],zf[3],s1[3],s2[3],s3[3],s4[3]),
	games(c[4],g[4],m[4],zy[4],h[4],zf[4],s1[4],s2[4],s3[4],s4[4]),
};
//实际坐标向逻辑坐标的转换，具体看张奥成代码，转化完后，棋盘的坐标为4*5{（1，1）-（4，5）}
//如果需要变动，做加减就可，不明白的地方直接问我
Location logicturn(Location zb)
{
	int tempx = zb.x / 100;          //横坐标
	int tempy = zb.y / 100;          //纵坐标
	Location temp = { tempx,tempy };      //返回逻辑坐标
	return temp;                          //返回逻辑坐标
}

//先要改变所要变动棋子的逻辑位置，在随着改动它的实际坐标
//随后调用这个函数就可以完成棋盘上棋子位置的更新，num是关卡的序号
void picmove(int num)             
{                             
	switch (num)
	{
	case 1:
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
		break;
	case 2:
		putimage(c[num - 1].x, c[num - 1].y, &cchess);
		putimage(zf[num - 1].x, zf[num - 1].y, &zf1chess);
		putimage(m[num - 1].x, m[num - 1].y, &m2chess);
		putimage(h[num - 1].x, h[num - 1].y, &hz2chess);
		putimage(g[num - 1].x, g[num - 1].y, &gchess);
		putimage(zy[num - 1].x, zy[num - 1].y, &zy1chess);
		putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
		putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
		putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
		putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);
		break;
	case 3:
		putimage(c[num - 1].x, c[num - 1].y, &cchess);
		putimage(zf[num - 1].x, zf[num - 1].y, &zf2chess);
		putimage(m[num - 1].x, m[num - 1].y, &m2chess);
		putimage(h[num - 1].x, h[num - 1].y, &hz2chess);
		putimage(g[num - 1].x, g[num - 1].y, &gchess);
		putimage(zy[num - 1].x, zy[num - 1].y, &zy2chess);
		putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
		putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
		putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
		putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);
		break;
	case 4:
		putimage(c[num - 1].x, c[num - 1].y, &cchess);
		putimage(zf[num - 1].x, zf[num - 1].y, &zf1chess);
		putimage(m[num - 1].x, m[num - 1].y, &m2chess);
		putimage(h[num - 1].x, h[num - 1].y, &hz2chess);
		putimage(g[num - 1].x, g[num - 1].y, &gchess);
		putimage(zy[num - 1].x, zy[num - 1].y, &zy2chess);
		putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
		putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
		putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
		putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);
		break;
	case 5:
		putimage(c[num - 1].x, c[num - 1].y, &cchess);
		putimage(zf[num - 1].x, zf[num - 1].y, &zf2chess);
		putimage(m[num - 1].x, m[num - 1].y, &m1chess);
		putimage(h[num - 1].x, h[num - 1].y, &hz1chess);
		putimage(g[num - 1].x, g[num - 1].y, &gchess);
		putimage(zy[num - 1].x, zy[num - 1].y, &zy2chess);
		putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
		putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
		putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
		putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);
		break;
	}

}
//游戏开始函数
void gamebegin()
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

	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0};
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
		if(ms.uMsg== WM_LBUTTONUP)
		{
			if ( ms.x>=80 && ms.x<= 230 && ms.y>=400 && ms.y<= 470)
			{
				closegraph();
				gameselect();
				break;
			  }
			else if ( ms.x>=280 && ms.x<= 430 && ms.y>=400 && ms.y<= 470)
			{
				closegraph();
				gameselect();
				break;
			}
			else if (ms.x>=480 && ms.x<= 630 && ms.y>=400 && ms.y<= 470)
			{
				closegraph();
				cout << ms.x << "  " << ms.y << endl;
				cout << "hi,coward,sure to quit!" << endl;
				break;
			}
		}
		else {
			;
		}
	}
	cout << "see this, you do a great job!" << endl;
}
//关卡选择
void gameselect()
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
	loadimage(&buttom_x2, _T("D:\\cpicture\\sbuttom1.png") ,80, 40);     //过五关
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
	MOUSEMSG ms2= { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
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
	while (true)
	{
		ms2= GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{
			if (ms2.x >= 270 && ms2.x <= 350 && ms2.y >= 400 && ms2.y <= 450)
			{
				modeselect = 1;
				break;
			}
			else if (ms2.x >= 450 && ms2.x <= 530 && ms2.y >= 400 && ms2.y <= 450)
			{
				modeselect = 2;
				break;
			}
		}
	}
	switch (levelselect)
	{
	case 1:if (modeselect == 2)
	       {
		       closegraph();
			   start1(levelselect);
		       cout << "level 1 do" << endl;
	       }
		  else {
		       closegraph();

		       cout << "level 1 watch" << endl;
	       }
		  break;
	case 2:if (modeselect == 2)
	{
		closegraph();
		start2(levelselect);
		cout << "level 2 do" << endl;
	}
		  else {
		closegraph();
		cout << "level 2 watch" << endl;
	}
		  break;
	case 3:if (modeselect == 1)
	{
		closegraph();
		cout << "level 3 watch" << endl;
	}
		  else {
		closegraph();
		start3(levelselect);
		cout << "level 3 do" << endl;
	}
		  break;
	case 4:if (modeselect == 1)
	{
		closegraph();
		cout << "level 4 watch" << endl;
	}
		  else {
		closegraph();
		start4(levelselect);
		cout << "level 4 do" << endl;
	}
		  break;
	case 5:if (modeselect == 1)
	{
		closegraph();
		cout << "level 5 watch" << endl;
	}
		  else {
		closegraph();
		start5(levelselect);
		cout << "level 5 do" << endl;
	}
		  break;
	
	}

		_getch();
	closegraph();
}
//提示栏刷新函数，根据你需要的时候将他放上就可以将提示栏刷新为空白了
void tipreflesh()                                                 //提示位置刷新函数
{
	IMAGE tip;
	loadimage(&tip, _T("D:\\cpicture\\tip.png"), 400, 170);
	putimage(550, 10, &tip);
}
//屏气凝神在提示栏弹出
void silencebounce()
{
	IMAGE silence;
	loadimage(&silence, _T("D:\\cpicture\\silence.png"), 100, 40);
	putimage(600, 80, &silence);
}
//步数输出函数，在相应位置打印现在走的步数，在需要时调用即可
void stepwrite(int wnum)
{
	settextcolor(WHITE);
	settextstyle(10, 8, _T("宋体"));
	char a[3];
	sprintf(a, "%d", wnum);
	outtextxy(700, 240, a);
}
//生命值输出函数，使用方法同理
void lifewrite(int lnum)
{
	settextcolor(WHITE);
	settextstyle(10, 8, _T("宋体"));
	char b[3];
	sprintf(b, "%d", lnum);
	outtextxy(700, 300, b);
}
//兵荒马乱和危的触发函数，在你需要时调用即可
void htbounce()
{
	IMAGE ht;
	IMAGE wei;
	loadimage(&ht, _T("D:\\cpicture\\ht.png"), 100, 40);
	loadimage(&wei, _T("D:\\cpicture\\wei.png"), 100, 40);
	putimage(600, 80, &ht);
	putimage(570, 20, &wei);
}
//⑤个关卡的选择，不用列代码进行选择了，我已经做好了选择工作
void start1(int num)
{
initgraph(wid, hei);
IMAGE bg2;
IMAGE chart;
IMAGE function;
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

IMAGE stepnum;
IMAGE life;
IMAGE help;
IMAGE back;
IMAGE voice;
IMAGE drum;
IMAGE say;
IMAGE quite;
IMAGE return1;
IMAGE quit;


loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
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

loadimage(&stepnum, _T("D:\\cpicture\\stepnum.png"), 120, 40);
loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
loadimage(&back, _T("D:\\cpicture\\back.png"), 120, 40);
loadimage(&voice, _T("D:\\cpicture\\voice.png"), 120, 40);
loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
loadimage(&return1, _T("D:\\cpicture\\return.png"), 120, 40);
loadimage(&quit, _T("D:\\cpicture\\quit.png"), 80, 40);

putimage(0, 0, &bg2);
putimage(100, 20, &chart);
putimage(550, 5, &function);
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
putimage(680, 220, &stepnum);
putimage(680, 270, &life);
putimage(680, 320, &help);
putimage(680, 370, &back);
putimage(680, 420, &voice);
putimage(650, 400, &drum);
putimage(650, 435, &say);
putimage(680, 470, &return1);
putimage(650, 470, &quite);
putimage(700, 520, &quit);
MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
while (1)
{
	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	ms = GetMouseMsg();
	if (ms.uMsg == WM_LBUTTONUP)
	{
		if (ms.x >= 100 && ms.x <= 500 && ms.y >= 20 && ms.y <= 620)
		{
			Location zb = { ms.x,ms.y };
			logicturn(zb);                           //还需要覆盖提示栏
			tipreflesh();                            //完成一次操作，提示栏被覆盖
		}
		if (ms.x >= 550 && ms.x <= 800 && ms.y >= 5 && ms.y <= 685)
		{
			if( ms.x >= 680 && ms.x <= 800 && ms.y >= 320 && ms.y <= 360)  //提示功能的实现
			{
				loadimage(&up, _T("D:\\cpicture\\up.png"), 60, 60);
				loadimage(&down, _T("D:\\cpicture\\down.png"), 60, 60);
				loadimage(&t_left, _T("D:\\cpicture\\left.png"), 60, 60);
				loadimage(&t_right, _T("D:\\cpicture\\right.png"), 60, 60);
				loadimage(&tip_c, _T("D:\\cpicture\\tip_c.png"), 60, 60);
				loadimage(&tip_g, _T("D:\\cpicture\\tip_g.png"), 60, 60);
				loadimage(&tip_h, _T("D:\\cpicture\\tip_h.png"), 60, 60);
				loadimage(&tip_m, _T("D:\\cpicture\\tip_m.png"), 60, 60);
				loadimage(&tip_zf, _T("D:\\cpicture\\tip_zf.png"), 60, 60);
				loadimage(&tip_zy, _T("D:\\cpicture\\tip_zy.png"), 60, 60);
				loadimage(&tip_s1, _T("D:\\cpicture\\tip_s1.png"), 60, 60);
				loadimage(&tip_s2, _T("D:\\cpicture\\tip_s2.png"), 60, 60);
				loadimage(&tip_s3, _T("D:\\cpicture\\tip_s3.png"), 60, 60);
				loadimage(&tip_s4, _T("D:\\cpicture\\tip_s4.png"), 60, 60);

				switch (tip_select_chess)
				{
				case 1:
					putimage(570, 20, &tip_c);
					break;
				case 2:
					putimage(570, 20, &tip_g);
					break;
				case 3:
					putimage(570, 20, &tip_m);
					break;
				case 4:
					putimage(570, 20, &tip_h);
					break;
				case 5:
					putimage(570, 20, &tip_zf);
					break;
				case 6:
					putimage(570, 20, &tip_zy);
					break;
				case 7:
					putimage(570, 20, &tip_s1);
					break;
				case 8:
					putimage(570, 20, &tip_s2);
					break;
				case 9:
					putimage(570, 20, &tip_s3);
					break;
				case 10:
					putimage(570, 20, &tip_s4);
					break;
				}
				switch (tip_select_toward)
				{
				case 1:
					putimage(570, 20, &up);
					break;
				case 2:
					putimage(570, 20, &down);
					break;
				case 3:
					putimage(570, 20, &t_left);
					break;
				case 4:
					putimage(570, 20, &t_right);
					break;
				}
				
}
			}
		if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)   //回退功能待补充
		{
			                                                 //补充部分
			                                                 //步数更新函数
			                                                 //生命值更新函数
		}
		if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //鼓乐功能待补充
		{ 
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // 加大音量
			{

			}
			if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //减小音量
			{

			}
		}
		if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //呐喊功能待补充
		{
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //加大音量
			{

			}
			if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //减小音量
			{

			}
		}
		if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //静音功能待补充
		{

		}
		if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //重开功能具体实现
		{

		}
		if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //退出功能
		{
			closegraph();
		}
		}
	}
}
void start2(int num)
{
	initgraph(wid, hei);
	IMAGE bg2;
	IMAGE chart;
	IMAGE function;
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

	IMAGE stepnum;
	IMAGE life;
	IMAGE help;
	IMAGE back;
	IMAGE voice;
	IMAGE drum;
	IMAGE say;
	IMAGE quite;
	IMAGE return1;
	IMAGE quit;

	loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
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

	loadimage(&stepnum, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
	loadimage(&back, _T("D:\\cpicture\\back.png"), 120, 40);
	loadimage(&voice, _T("D:\\cpicture\\voice.png"), 120, 40);
	loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
	loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
	loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
	loadimage(&return1, _T("D:\\cpicture\\return.png"), 120, 40);
	loadimage(&quit, _T("D:\\cpicture\\quit.png"), 80, 40);

	putimage(0, 0, &bg2);
	putimage(100, 20, &chart);
	putimage(550, 5, &function);
	putimage(c[num - 1].x, c[num - 1].y, &cchess);
	putimage(zf[num - 1].x, zf[num - 1].y, &zf1chess);
	putimage(m[num - 1].x, m[num - 1].y, &m2chess);
	putimage(h[num - 1].x, h[num - 1].y, &hz2chess);
	putimage(g[num - 1].x, g[num - 1].y, &gchess);
	putimage(zy[num - 1].x, zy[num - 1].y, &zy1chess);
	putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
	putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
	putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
	putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);

	//状态栏图标显示
	putimage(680, 220, &stepnum);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &back);
	putimage(680, 420, &voice);
	putimage(650, 400, &drum);
	putimage(650, 435, &say);
	putimage(680, 470, &return1);
	putimage(650, 470, &quite);
	putimage(700, 520, &quit);

	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{
			if (ms.x >= 100 && ms.x <= 500 && ms.y >= 20 && ms.y <= 620)
			{
				Location zb = { ms.x,ms.y };
				logicturn(zb);                           //还需要覆盖提示栏
				tipreflesh();                            //完成一次操作，提示栏被覆盖
			}
			if (ms.x >= 550 && ms.x <= 800 && ms.y >= 5 && ms.y <= 685)
			{
				if (ms.x >= 680 && ms.x <= 800 && ms.y >= 320 && ms.y <= 360)
				{
					loadimage(&up, _T("D:\\cpicture\\up.png"), 60, 60);
					loadimage(&down, _T("D:\\cpicture\\down.png"), 60, 60);
					loadimage(&t_left, _T("D:\\cpicture\\left.png"), 60, 60);
					loadimage(&t_right, _T("D:\\cpicture\\right.png"), 60, 60);
					loadimage(&tip_c, _T("D:\\cpicture\\tip_c.png"), 60, 60);
					loadimage(&tip_g, _T("D:\\cpicture\\tip_g.png"), 60, 60);
					loadimage(&tip_h, _T("D:\\cpicture\\tip_h.png"), 60, 60);
					loadimage(&tip_m, _T("D:\\cpicture\\tip_m.png"), 60, 60);
					loadimage(&tip_zf, _T("D:\\cpicture\\tip_zf.png"), 60, 60);
					loadimage(&tip_zy, _T("D:\\cpicture\\tip_zy.png"), 60, 60);
					loadimage(&tip_s1, _T("D:\\cpicture\\tip_s1.png"), 60, 60);
					loadimage(&tip_s2, _T("D:\\cpicture\\tip_s2.png"), 60, 60);
					loadimage(&tip_s3, _T("D:\\cpicture\\tip_s3.png"), 60, 60);
					loadimage(&tip_s4, _T("D:\\cpicture\\tip_s4.png"), 60, 60);

					switch (tip_select_chess)
					{
					case 1:
						putimage(570, 20, &tip_c);
						break;
					case 2:
						putimage(570, 20, &tip_g);
						break;
					case 3:
						putimage(570, 20, &tip_m);
						break;
					case 4:
						putimage(570, 20, &tip_h);
						break;
					case 5:
						putimage(570, 20, &tip_zf);
						break;
					case 6:
						putimage(570, 20, &tip_zy);
						break;
					case 7:
						putimage(570, 20, &tip_s1);
						break;
					case 8:
						putimage(570, 20, &tip_s2);
						break;
					case 9:
						putimage(570, 20, &tip_s3);
						break;
					case 10:
						putimage(570, 20, &tip_s4);
						break;
					}
					switch (tip_select_toward)
					{
					case 1:
						putimage(570, 20, &up);
						break;
					case 2:
						putimage(570, 20, &down);
						break;
					case 3:
						putimage(570, 20, &t_left);
						break;
					case 4:
						putimage(570, 20, &t_right);
						break;
					}

				}
			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)   //回退功能待补充
			{
				//补充部分
				//步数更新函数
				//生命值更新函数
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //鼓乐功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // 加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //呐喊功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //静音功能待补充
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //重开功能具体实现
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //退出功能
			{
				closegraph();
			}
		}
	}
}
void start3(int num)
{
	initgraph(wid, hei);
	IMAGE bg2;
	IMAGE chart;
	IMAGE function;
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

	IMAGE stepnum;
	IMAGE life;
	IMAGE help;
	IMAGE back;
	IMAGE voice;
	IMAGE drum;
	IMAGE say;
	IMAGE quite;
	IMAGE return1;
	IMAGE quit;

	loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
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

	loadimage(&stepnum, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
	loadimage(&back, _T("D:\\cpicture\\back.png"), 120, 40);
	loadimage(&voice, _T("D:\\cpicture\\voice.png"), 120, 40);
	loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
	loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
	loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
	loadimage(&return1, _T("D:\\cpicture\\return.png"), 120, 40);
	loadimage(&quit, _T("D:\\cpicture\\quit.png"), 80, 40);

	putimage(0, 0, &bg2);
	putimage(100, 20, &chart);
	putimage(550, 5, &function);
	putimage(c[num - 1].x, c[num - 1].y, &cchess);
	putimage(zf[num - 1].x, zf[num - 1].y, &zf2chess);
	putimage(m[num - 1].x, m[num - 1].y, &m2chess);
	putimage(h[num - 1].x, h[num - 1].y, &hz2chess);
	putimage(g[num - 1].x, g[num - 1].y, &gchess);
	putimage(zy[num - 1].x, zy[num - 1].y, &zy2chess);
	putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
	putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
	putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
	putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);

	//状态栏图标显示
	putimage(680, 220, &stepnum);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &back);
	putimage(680, 420, &voice);
	putimage(650, 400, &drum);
	putimage(650, 435, &say);
	putimage(680, 470, &return1);
	putimage(650, 470, &quite);
	putimage(700, 520, &quit);

	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{
			if (ms.x >= 100 && ms.x <= 500 && ms.y >= 20 && ms.y <= 620)
			{
				Location zb = { ms.x,ms.y };
				logicturn(zb);                           //还需要覆盖提示栏
				tipreflesh();                            //完成一次操作，提示栏被覆盖
			}
			if (ms.x >= 550 && ms.x <= 800 && ms.y >= 5 && ms.y <= 685)
			{
				if (ms.x >= 680 && ms.x <= 800 && ms.y >= 320 && ms.y <= 360)
				{
					loadimage(&up, _T("D:\\cpicture\\up.png"), 60, 60);
					loadimage(&down, _T("D:\\cpicture\\down.png"), 60, 60);
					loadimage(&t_left, _T("D:\\cpicture\\left.png"), 60, 60);
					loadimage(&t_right, _T("D:\\cpicture\\right.png"), 60, 60);
					loadimage(&tip_c, _T("D:\\cpicture\\tip_c.png"), 60, 60);
					loadimage(&tip_g, _T("D:\\cpicture\\tip_g.png"), 60, 60);
					loadimage(&tip_h, _T("D:\\cpicture\\tip_h.png"), 60, 60);
					loadimage(&tip_m, _T("D:\\cpicture\\tip_m.png"), 60, 60);
					loadimage(&tip_zf, _T("D:\\cpicture\\tip_zf.png"), 60, 60);
					loadimage(&tip_zy, _T("D:\\cpicture\\tip_zy.png"), 60, 60);
					loadimage(&tip_s1, _T("D:\\cpicture\\tip_s1.png"), 60, 60);
					loadimage(&tip_s2, _T("D:\\cpicture\\tip_s2.png"), 60, 60);
					loadimage(&tip_s3, _T("D:\\cpicture\\tip_s3.png"), 60, 60);
					loadimage(&tip_s4, _T("D:\\cpicture\\tip_s4.png"), 60, 60);

					switch (tip_select_chess)
					{
					case 1:
						putimage(570, 20, &tip_c);
						break;
					case 2:
						putimage(570, 20, &tip_g);
						break;
					case 3:
						putimage(570, 20, &tip_m);
						break;
					case 4:
						putimage(570, 20, &tip_h);
						break;
					case 5:
						putimage(570, 20, &tip_zf);
						break;
					case 6:
						putimage(570, 20, &tip_zy);
						break;
					case 7:
						putimage(570, 20, &tip_s1);
						break;
					case 8:
						putimage(570, 20, &tip_s2);
						break;
					case 9:
						putimage(570, 20, &tip_s3);
						break;
					case 10:
						putimage(570, 20, &tip_s4);
						break;
					}
					switch (tip_select_toward)
					{
					case 1:
						putimage(570, 20, &up);
						break;
					case 2:
						putimage(570, 20, &down);
						break;
					case 3:
						putimage(570, 20, &t_left);
						break;
					case 4:
						putimage(570, 20, &t_right);
						break;
					}

				}
			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)   //回退功能待补充
			{
				//补充部分
				//步数更新函数
				//生命值更新函数
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //鼓乐功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // 加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //呐喊功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //静音功能待补充
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //重开功能具体实现
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //退出功能
			{
				closegraph();
			}
		}
	}
}
void start4(int num)
{
	initgraph(wid, hei);
	IMAGE bg2;
	IMAGE chart;
	IMAGE function;
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

	IMAGE stepnum;
	IMAGE life;
	IMAGE help;
	IMAGE back;
	IMAGE voice;
	IMAGE drum;
	IMAGE say;
	IMAGE quite;
	IMAGE return1;
	IMAGE quit;

	loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
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

	loadimage(&stepnum, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
	loadimage(&back, _T("D:\\cpicture\\back.png"), 120, 40);
	loadimage(&voice, _T("D:\\cpicture\\voice.png"), 120, 40);
	loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
	loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
	loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
	loadimage(&return1, _T("D:\\cpicture\\return.png"), 120, 40);
	loadimage(&quit, _T("D:\\cpicture\\quit.png"), 80, 40);

	putimage(0, 0, &bg2);
	putimage(100, 20, &chart);
	putimage(550, 5, &function);
	putimage(c[num - 1].x, c[num - 1].y, &cchess);
	putimage(zf[num - 1].x, zf[num - 1].y, &zf1chess);
	putimage(m[num - 1].x, m[num - 1].y, &m2chess);
	putimage(h[num - 1].x, h[num - 1].y, &hz2chess);
	putimage(g[num - 1].x, g[num - 1].y, &gchess);
	putimage(zy[num - 1].x, zy[num - 1].y, &zy2chess);
	putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
	putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
	putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
	putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);

	//状态栏图标显示
	putimage(680, 220, &stepnum);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &back);
	putimage(680, 420, &voice);
	putimage(650, 400, &drum);
	putimage(650, 435, &say);
	putimage(680, 470, &return1);
	putimage(650, 470, &quite);
	putimage(700, 520, &quit);

	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{
			if (ms.x >= 100 && ms.x <= 500 && ms.y >= 20 && ms.y <= 620)
			{
				Location zb = { ms.x,ms.y };
				logicturn(zb);                           //还需要覆盖提示栏
				tipreflesh();                            //完成一次操作，提示栏被覆盖
			}
			if (ms.x >= 550 && ms.x <= 800 && ms.y >= 5 && ms.y <= 685)
			{
				if (ms.x >= 680 && ms.x <= 800 && ms.y >= 320 && ms.y <= 360)
				{
					loadimage(&up, _T("D:\\cpicture\\up.png"), 60, 60);
					loadimage(&down, _T("D:\\cpicture\\down.png"), 60, 60);
					loadimage(&t_left, _T("D:\\cpicture\\left.png"), 60, 60);
					loadimage(&t_right, _T("D:\\cpicture\\right.png"), 60, 60);
					loadimage(&tip_c, _T("D:\\cpicture\\tip_c.png"), 60, 60);
					loadimage(&tip_g, _T("D:\\cpicture\\tip_g.png"), 60, 60);
					loadimage(&tip_h, _T("D:\\cpicture\\tip_h.png"), 60, 60);
					loadimage(&tip_m, _T("D:\\cpicture\\tip_m.png"), 60, 60);
					loadimage(&tip_zf, _T("D:\\cpicture\\tip_zf.png"), 60, 60);
					loadimage(&tip_zy, _T("D:\\cpicture\\tip_zy.png"), 60, 60);
					loadimage(&tip_s1, _T("D:\\cpicture\\tip_s1.png"), 60, 60);
					loadimage(&tip_s2, _T("D:\\cpicture\\tip_s2.png"), 60, 60);
					loadimage(&tip_s3, _T("D:\\cpicture\\tip_s3.png"), 60, 60);
					loadimage(&tip_s4, _T("D:\\cpicture\\tip_s4.png"), 60, 60);

					switch (tip_select_chess)
					{
					case 1:
						putimage(570, 20, &tip_c);
						break;
					case 2:
						putimage(570, 20, &tip_g);
						break;
					case 3:
						putimage(570, 20, &tip_m);
						break;
					case 4:
						putimage(570, 20, &tip_h);
						break;
					case 5:
						putimage(570, 20, &tip_zf);
						break;
					case 6:
						putimage(570, 20, &tip_zy);
						break;
					case 7:
						putimage(570, 20, &tip_s1);
						break;
					case 8:
						putimage(570, 20, &tip_s2);
						break;
					case 9:
						putimage(570, 20, &tip_s3);
						break;
					case 10:
						putimage(570, 20, &tip_s4);
						break;
					}
					switch (tip_select_toward)
					{
					case 1:
						putimage(570, 20, &up);
						break;
					case 2:
						putimage(570, 20, &down);
						break;
					case 3:
						putimage(570, 20, &t_left);
						break;
					case 4:
						putimage(570, 20, &t_right);
						break;
					}

				}
			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)   //回退功能待补充
			{
				//补充部分
				//步数更新函数
				//生命值更新函数
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //鼓乐功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // 加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //呐喊功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //静音功能待补充
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //重开功能具体实现
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //退出功能
			{
				closegraph();
			}
		}
	}
}
void start5(int num)
{
	initgraph(wid, hei);
	IMAGE bg2;
	IMAGE chart;
	IMAGE function;
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

	IMAGE stepnum;
	IMAGE life;
	IMAGE help;
	IMAGE back;
	IMAGE voice;
	IMAGE drum;
	IMAGE say;
	IMAGE quite;
	IMAGE return1;
	IMAGE quit;

	loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
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

	loadimage(&stepnum, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
	loadimage(&back, _T("D:\\cpicture\\back.png"), 120, 40);
	loadimage(&voice, _T("D:\\cpicture\\voice.png"), 120, 40);
	loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
	loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
	loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
	loadimage(&return1, _T("D:\\cpicture\\return.png"), 120, 40);
	loadimage(&quit, _T("D:\\cpicture\\quit.png"), 80, 40);

	putimage(0, 0, &bg2);
	putimage(100, 20, &chart);
	putimage(550, 5, &function);
	putimage(c[num - 1].x, c[num - 1].y, &cchess);
	putimage(zf[num - 1].x, zf[num - 1].y, &zf2chess);
	putimage(m[num - 1].x, m[num - 1].y, &m1chess);
	putimage(h[num - 1].x, h[num - 1].y, &hz1chess);
	putimage(g[num - 1].x, g[num - 1].y, &gchess);
	putimage(zy[num - 1].x, zy[num - 1].y, &zy2chess);
	putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
	putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
	putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
	putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);

	//状态栏图标显示
	putimage(680, 220, &stepnum);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &back);
	putimage(680, 420, &voice);
	putimage(650, 400, &drum);
	putimage(650, 435, &say);
	putimage(680, 470, &return1);
	putimage(650, 470, &quite);
	putimage(700, 520, &quit);

	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{
			if (ms.x >= 100 && ms.x <= 500 && ms.y >= 20 && ms.y <= 620)
			{
				Location zb = { ms.x,ms.y };
				logicturn(zb);                           //还需要覆盖提示栏
				tipreflesh();                            //完成一次操作，提示栏被覆盖
			}
			if (ms.x >= 550 && ms.x <= 800 && ms.y >= 5 && ms.y <= 685)
			{
				if (ms.x >= 680 && ms.x <= 800 && ms.y >= 320 && ms.y <= 360)
				{
					loadimage(&up, _T("D:\\cpicture\\up.png"), 60, 60);
					loadimage(&down, _T("D:\\cpicture\\down.png"), 60, 60);
					loadimage(&t_left, _T("D:\\cpicture\\left.png"), 60, 60);
					loadimage(&t_right, _T("D:\\cpicture\\right.png"), 60, 60);
					loadimage(&tip_c, _T("D:\\cpicture\\tip_c.png"), 60, 60);
					loadimage(&tip_g, _T("D:\\cpicture\\tip_g.png"), 60, 60);
					loadimage(&tip_h, _T("D:\\cpicture\\tip_h.png"), 60, 60);
					loadimage(&tip_m, _T("D:\\cpicture\\tip_m.png"), 60, 60);
					loadimage(&tip_zf, _T("D:\\cpicture\\tip_zf.png"), 60, 60);
					loadimage(&tip_zy, _T("D:\\cpicture\\tip_zy.png"), 60, 60);
					loadimage(&tip_s1, _T("D:\\cpicture\\tip_s1.png"), 60, 60);
					loadimage(&tip_s2, _T("D:\\cpicture\\tip_s2.png"), 60, 60);
					loadimage(&tip_s3, _T("D:\\cpicture\\tip_s3.png"), 60, 60);
					loadimage(&tip_s4, _T("D:\\cpicture\\tip_s4.png"), 60, 60);

					switch (tip_select_chess)
					{
					case 1:
						putimage(570, 20, &tip_c);
						break;
					case 2:
						putimage(570, 20, &tip_g);
						break;
					case 3:
						putimage(570, 20, &tip_m);
						break;
					case 4:
						putimage(570, 20, &tip_h);
						break;
					case 5:
						putimage(570, 20, &tip_zf);
						break;
					case 6:
						putimage(570, 20, &tip_zy);
						break;
					case 7:
						putimage(570, 20, &tip_s1);
						break;
					case 8:
						putimage(570, 20, &tip_s2);
						break;
					case 9:
						putimage(570, 20, &tip_s3);
						break;
					case 10:
						putimage(570, 20, &tip_s4);
						break;
					}
					switch (tip_select_toward)
					{
					case 1:
						putimage(570, 20, &up);
						break;
					case 2:
						putimage(570, 20, &down);
						break;
					case 3:
						putimage(570, 20, &t_left);
						break;
					case 4:
						putimage(570, 20, &t_right);
						break;
					}

				}
			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)   //回退功能待补充
			{
				//补充部分
				//步数更新函数
				//生命值更新函数
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //鼓乐功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // 加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //呐喊功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //静音功能待补充
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //重开功能具体实现
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //退出功能
			{
				closegraph();
			}
		}
	}
}

void yanshi1(int num)
{
	initgraph(wid, hei);
	IMAGE bg2;
	IMAGE chart;
	IMAGE function;
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

	IMAGE stepnum;
	IMAGE life;
	IMAGE help;
	IMAGE back;
	IMAGE voice;
	IMAGE drum;
	IMAGE say;
	IMAGE quite;
	IMAGE return1;
	IMAGE quit;

	loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
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

	loadimage(&stepnum, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
	loadimage(&back, _T("D:\\cpicture\\back.png"), 120, 40);
	loadimage(&voice, _T("D:\\cpicture\\voice.png"), 120, 40);
	loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
	loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
	loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
	loadimage(&return1, _T("D:\\cpicture\\return.png"), 120, 40);
	loadimage(&quit, _T("D:\\cpicture\\quit.png"), 80, 40);

	putimage(0, 0, &bg2);
	putimage(100, 20, &chart);
	putimage(550, 5, &function);
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
	putimage(680, 220, &stepnum);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &back);
	putimage(680, 420, &voice);
	putimage(650, 400, &drum);
	putimage(650, 435, &say);
	putimage(680, 470, &return1);
	putimage(650, 470, &quite);
	putimage(700, 520, &quit);
	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
    //此处引入演示部分的代码就可以了
	/*
	
	
	*/
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{
			
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //鼓乐功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // 加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //呐喊功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //静音功能待补充
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //重开功能具体实现
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //退出功能
			{
				closegraph();
			}
		}
	}
	
}
void yanshi2(int num)
{
	initgraph(wid, hei);
	IMAGE bg2;
	IMAGE chart;
	IMAGE function;
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

	IMAGE stepnum;
	IMAGE life;
	IMAGE help;
	IMAGE back;
	IMAGE voice;
	IMAGE drum;
	IMAGE say;
	IMAGE quite;
	IMAGE return1;
	IMAGE quit;

	loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
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

	loadimage(&stepnum, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
	loadimage(&back, _T("D:\\cpicture\\back.png"), 120, 40);
	loadimage(&voice, _T("D:\\cpicture\\voice.png"), 120, 40);
	loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
	loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
	loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
	loadimage(&return1, _T("D:\\cpicture\\return.png"), 120, 40);
	loadimage(&quit, _T("D:\\cpicture\\quit.png"), 80, 40);

	putimage(0, 0, &bg2);
	putimage(100, 20, &chart);
	putimage(550, 5, &function);
	putimage(c[num - 1].x, c[num - 1].y, &cchess);
	putimage(zf[num - 1].x, zf[num - 1].y, &zf1chess);
	putimage(m[num - 1].x, m[num - 1].y, &m2chess);
	putimage(h[num - 1].x, h[num - 1].y, &hz2chess);
	putimage(g[num - 1].x, g[num - 1].y, &gchess);
	putimage(zy[num - 1].x, zy[num - 1].y, &zy1chess);
	putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
	putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
	putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
	putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);

	//状态栏图标显示
	putimage(680, 220, &stepnum);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &back);
	putimage(680, 420, &voice);
	putimage(650, 400, &drum);
	putimage(650, 435, &say);
	putimage(680, 470, &return1);
	putimage(650, 470, &quite);
	putimage(700, 520, &quit);
	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	//此处引入演示部分的代码就可以了
	/*


	*/
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{

			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //鼓乐功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // 加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //呐喊功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //静音功能待补充
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //重开功能具体实现
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //退出功能
			{
				closegraph();
			}
		}
	}

}
void yanshi3(int num)
{
	initgraph(wid, hei);
	IMAGE bg2;
	IMAGE chart;
	IMAGE function;
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

	IMAGE stepnum;
	IMAGE life;
	IMAGE help;
	IMAGE back;
	IMAGE voice;
	IMAGE drum;
	IMAGE say;
	IMAGE quite;
	IMAGE return1;
	IMAGE quit;

	loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
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

	loadimage(&stepnum, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
	loadimage(&back, _T("D:\\cpicture\\back.png"), 120, 40);
	loadimage(&voice, _T("D:\\cpicture\\voice.png"), 120, 40);
	loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
	loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
	loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
	loadimage(&return1, _T("D:\\cpicture\\return.png"), 120, 40);
	loadimage(&quit, _T("D:\\cpicture\\quit.png"), 80, 40);

	putimage(0, 0, &bg2);
	putimage(100, 20, &chart);
	putimage(550, 5, &function);
	putimage(c[num - 1].x, c[num - 1].y, &cchess);
	putimage(zf[num - 1].x, zf[num - 1].y, &zf2chess);
	putimage(m[num - 1].x, m[num - 1].y, &m2chess);
	putimage(h[num - 1].x, h[num - 1].y, &hz2chess);
	putimage(g[num - 1].x, g[num - 1].y, &gchess);
	putimage(zy[num - 1].x, zy[num - 1].y, &zy2chess);
	putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
	putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
	putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
	putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);

	//状态栏图标显示
	putimage(680, 220, &stepnum);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &back);
	putimage(680, 420, &voice);
	putimage(650, 400, &drum);
	putimage(650, 435, &say);
	putimage(680, 470, &return1);
	putimage(650, 470, &quite);
	putimage(700, 520, &quit);
	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	//此处引入演示部分的代码就可以了
	/*


	*/
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{

			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //鼓乐功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // 加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //呐喊功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //静音功能待补充
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //重开功能具体实现
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //退出功能
			{
				closegraph();
			}
		}
	}

}
void yanshi4(int num)
{
	initgraph(wid, hei);
	IMAGE bg2;
	IMAGE chart;
	IMAGE function;
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

	IMAGE stepnum;
	IMAGE life;
	IMAGE help;
	IMAGE back;
	IMAGE voice;
	IMAGE drum;
	IMAGE say;
	IMAGE quite;
	IMAGE return1;
	IMAGE quit;

	loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
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

	loadimage(&stepnum, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
	loadimage(&back, _T("D:\\cpicture\\back.png"), 120, 40);
	loadimage(&voice, _T("D:\\cpicture\\voice.png"), 120, 40);
	loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
	loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
	loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
	loadimage(&return1, _T("D:\\cpicture\\return.png"), 120, 40);
	loadimage(&quit, _T("D:\\cpicture\\quit.png"), 80, 40);

	putimage(0, 0, &bg2);
	putimage(100, 20, &chart);
	putimage(550, 5, &function);
	putimage(c[num - 1].x, c[num - 1].y, &cchess);
	putimage(zf[num - 1].x, zf[num - 1].y, &zf1chess);
	putimage(m[num - 1].x, m[num - 1].y, &m2chess);
	putimage(h[num - 1].x, h[num - 1].y, &hz2chess);
	putimage(g[num - 1].x, g[num - 1].y, &gchess);
	putimage(zy[num - 1].x, zy[num - 1].y, &zy2chess);
	putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
	putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
	putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
	putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);

	//状态栏图标显示
	putimage(680, 220, &stepnum);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &back);
	putimage(680, 420, &voice);
	putimage(650, 400, &drum);
	putimage(650, 435, &say);
	putimage(680, 470, &return1);
	putimage(650, 470, &quite);
	putimage(700, 520, &quit);
	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	//此处引入演示部分的代码就可以了
	/*


	*/
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{

			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //鼓乐功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // 加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //呐喊功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //静音功能待补充
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //重开功能具体实现
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //退出功能
			{
				closegraph();
			}
		}
	}

}
void yanshi5(int num)
{
	initgraph(wid, hei);
	IMAGE bg2;
	IMAGE chart;
	IMAGE function;
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

	IMAGE stepnum;
	IMAGE life;
	IMAGE help;
	IMAGE back;
	IMAGE voice;
	IMAGE drum;
	IMAGE say;
	IMAGE quite;
	IMAGE return1;
	IMAGE quit;

	loadimage(&bg2, _T("D:\\cpicture\\background2.jpg"), 800, 700);
	loadimage(&chart, _T("D:\\cpicture\\chart.png"), 400, 600);
	loadimage(&function, _T("D:\\cpicture\\function.png"), 250, 680);
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

	loadimage(&stepnum, _T("D:\\cpicture\\stepnum.png"), 120, 40);
	loadimage(&life, _T("D:\\cpicture\\life.png"), 120, 40);
	loadimage(&help, _T("D:\\cpicture\\helpme.png"), 120, 40);
	loadimage(&back, _T("D:\\cpicture\\back.png"), 120, 40);
	loadimage(&voice, _T("D:\\cpicture\\voice.png"), 120, 40);
	loadimage(&drum, _T("D:\\cpicture\\drum.png"), 60, 35);
	loadimage(&say, _T("D:\\cpicture\\say.png"), 60, 35);
	loadimage(&quite, _T("D:\\cpicture\\quite.png"), 60, 35);
	loadimage(&return1, _T("D:\\cpicture\\return.png"), 120, 40);
	loadimage(&quit, _T("D:\\cpicture\\quit.png"), 80, 40);

	putimage(0, 0, &bg2);
	putimage(100, 20, &chart);
	putimage(550, 5, &function);
	putimage(c[num - 1].x, c[num - 1].y, &cchess);
	putimage(zf[num - 1].x, zf[num - 1].y, &zf2chess);
	putimage(m[num - 1].x, m[num - 1].y, &m1chess);
	putimage(h[num - 1].x, h[num - 1].y, &hz1chess);
	putimage(g[num - 1].x, g[num - 1].y, &gchess);
	putimage(zy[num - 1].x, zy[num - 1].y, &zy2chess);
	putimage(s1[num - 1].x, s1[num - 1].y, &s1chess);
	putimage(s2[num - 1].x, s2[num - 1].y, &s2chess);
	putimage(s3[num - 1].x, s3[num - 1].y, &s3chess);
	putimage(s4[num - 1].x, s4[num - 1].y, &s4chess);

	//状态栏图标显示
	putimage(680, 220, &stepnum);
	putimage(680, 270, &life);
	putimage(680, 320, &help);
	putimage(680, 370, &back);
	putimage(680, 420, &voice);
	putimage(650, 400, &drum);
	putimage(650, 435, &say);
	putimage(680, 470, &return1);
	putimage(650, 470, &quite);
	putimage(700, 520, &quit);
	MOUSEMSG ms = { WM_MOUSEMOVE ,0,0,0,0,0,0,0 };
	//此处引入演示部分的代码就可以了
	/*


	*/
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{

			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //鼓乐功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // 加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //呐喊功能待补充
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //加大音量
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //减小音量
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //静音功能待补充
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //重开功能具体实现
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //退出功能
			{
				closegraph();
			}
		}
	}

}
//基本没用的地方，注意我的代码过程性比较多，因为画布需要连续变化，函数发生嵌套，执行代码写进start函数中
int main()
{
	
	gamebegin();
	
	
	return 0;
}