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

 Location c[5] = { { 200,50 },{ 200,50 },{ 200,50 },{ 200,50 } ,{ 200,50 } };      //�������ز���
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
 
 int tip_select_chess = 0;       //��ʾ��������ѡ���־λ
 int tip_select_toward = 0;      //��ʾ���ķ���ѡ���־λ
 

void gameselect();
void start1(int num);
void start2(int num);
void start3(int num);
void start4(int num);
void start5(int num);
//���ӵĳ�ʼλ��
games game[5] = {
	games(c[0],g[0],m[0],zy[0],h[0],zf[0],s1[0],s2[0],s3[0],s4[0]),
	games(c[1],g[1],m[1],zy[1],h[1],zf[1],s1[1],s2[1],s3[1],s4[1]),
	games(c[2],g[2],m[2],zy[2],h[2],zf[2],s1[2],s2[2],s3[2],s4[2]),
	games(c[3],g[3],m[3],zy[3],h[3],zf[3],s1[3],s2[3],s3[3],s4[3]),
	games(c[4],g[4],m[4],zy[4],h[4],zf[4],s1[4],s2[4],s3[4],s4[4]),
};
//ʵ���������߼������ת�������忴�Ű³ɴ��룬ת��������̵�����Ϊ4*5{��1��1��-��4��5��}
//�����Ҫ�䶯�����Ӽ��Ϳɣ������׵ĵط�ֱ������
Location logicturn(Location zb)
{
	int tempx = zb.x / 100;          //������
	int tempy = zb.y / 100;          //������
	Location temp = { tempx,tempy };      //�����߼�����
	return temp;                          //�����߼�����
}

//��Ҫ�ı���Ҫ�䶯���ӵ��߼�λ�ã������ŸĶ�����ʵ������
//��������������Ϳ����������������λ�õĸ��£�num�ǹؿ������
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
//��Ϸ��ʼ����
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
//�ؿ�ѡ��
void gameselect()
{
	initgraph(wid, hei);
	IMAGE back_pic1;
	IMAGE buttom_x1;           //ѡ�أ�x2~x6��
	IMAGE buttom_x2;
	IMAGE buttom_x3;
	IMAGE buttom_x4;
	IMAGE buttom_x5;
	IMAGE buttom_x6;
	IMAGE buttom_YL;          //������ť
	IMAGE buttom_CF;          //������ť
	IMAGE buttom_BT;          //������ͼ����
	
	IMAGE buttom_rx1;         //buttom_r��ͷ�ľ����ڽ�����굥������
	IMAGE buttom_rx2;
	IMAGE buttom_rx3;
	IMAGE buttom_rx4;
	IMAGE buttom_rx5;
	IMAGE buttom_rx6;
	IMAGE buttom_rYL;
	IMAGE buttom_rCF;
	IMAGE buttom_rBT;
	   
	loadimage(&back_pic1, _T("D:\\cpicture\\background1.jpg"), 800, 700);   	//ѡ�ؽ��汳��
	loadimage(&buttom_BT, _T("D:\\cpicture\\stitle.png"), 200, 100);       //ѡ�ر���
	loadimage(&buttom_x2, _T("D:\\cpicture\\sbuttom1.png") ,80, 40);     //�����
	loadimage(&buttom_x3, _T("D:\\cpicture\\sbuttom2.png"), 80, 40);     //������
	loadimage(&buttom_x4, _T("D:\\cpicture\\sbuttom3.png"), 80, 40);     //���Ҳ���
	loadimage(&buttom_x5, _T("D:\\cpicture\\sbuttom4.png"), 80, 40);     //����ѷ�
	loadimage(&buttom_x6, _T("D:\\cpicture\\sbuttom5.png"), 80, 40);     //С�����
	loadimage(&buttom_YL, _T("D:\\cpicture\\sbuttomYL.png"), 80, 50);     //������ť
	loadimage(&buttom_CF, _T("D:\\cpicture\\sbuttomCF.png"), 80, 50);     //������ť

	loadimage(&buttom_rx2, _T("D:\\cpicture\\sbuttom1.png"), 80, 40);
	/*
	
	
	����������Ԥ���ռ�
	
	
	
	*/

	putimage(0, 0, &back_pic1);
	putimage(300, 30, &buttom_BT);             //ѡ�ر�����ͼ
	putimage(360, 130, &buttom_x2);            //�������ͼ
	putimage(360, 180, &buttom_x3);            //������
	putimage(360, 230, &buttom_x4);            //���Ҳ���
	putimage(360, 280, &buttom_x5);            //����ѷ�
	putimage(360, 330, &buttom_x6);            //С�����
	putimage(270, 400, &buttom_YL);             //��������
	putimage(450, 400, &buttom_CF);            //��������
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
//��ʾ��ˢ�º�������������Ҫ��ʱ�������ϾͿ��Խ���ʾ��ˢ��Ϊ�հ���
void tipreflesh()                                                 //��ʾλ��ˢ�º���
{
	IMAGE tip;
	loadimage(&tip, _T("D:\\cpicture\\tip.png"), 400, 170);
	putimage(550, 10, &tip);
}
//������������ʾ������
void silencebounce()
{
	IMAGE silence;
	loadimage(&silence, _T("D:\\cpicture\\silence.png"), 100, 40);
	putimage(600, 80, &silence);
}
//�����������������Ӧλ�ô�ӡ�����ߵĲ���������Ҫʱ���ü���
void stepwrite(int wnum)
{
	settextcolor(WHITE);
	settextstyle(10, 8, _T("����"));
	char a[3];
	sprintf(a, "%d", wnum);
	outtextxy(700, 240, a);
}
//����ֵ���������ʹ�÷���ͬ��
void lifewrite(int lnum)
{
	settextcolor(WHITE);
	settextstyle(10, 8, _T("����"));
	char b[3];
	sprintf(b, "%d", lnum);
	outtextxy(700, 300, b);
}
//�������Һ�Σ�Ĵ���������������Ҫʱ���ü���
void htbounce()
{
	IMAGE ht;
	IMAGE wei;
	loadimage(&ht, _T("D:\\cpicture\\ht.png"), 100, 40);
	loadimage(&wei, _T("D:\\cpicture\\wei.png"), 100, 40);
	putimage(600, 80, &ht);
	putimage(570, 20, &wei);
}
//�ݸ��ؿ���ѡ�񣬲����д������ѡ���ˣ����Ѿ�������ѡ����
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

//״̬��ͼ����ʾ
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
			logicturn(zb);                           //����Ҫ������ʾ��
			tipreflesh();                            //���һ�β�������ʾ��������
		}
		if (ms.x >= 550 && ms.x <= 800 && ms.y >= 5 && ms.y <= 685)
		{
			if( ms.x >= 680 && ms.x <= 800 && ms.y >= 320 && ms.y <= 360)  //��ʾ���ܵ�ʵ��
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
		if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)   //���˹��ܴ�����
		{
			                                                 //���䲿��
			                                                 //�������º���
			                                                 //����ֵ���º���
		}
		if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //���ֹ��ܴ�����
		{ 
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // �Ӵ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //��С����
			{

			}
		}
		if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //�ź����ܴ�����
		{
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //�Ӵ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //��С����
			{

			}
		}
		if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //�������ܴ�����
		{

		}
		if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //�ؿ����ܾ���ʵ��
		{

		}
		if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //�˳�����
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

	//״̬��ͼ����ʾ
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
				logicturn(zb);                           //����Ҫ������ʾ��
				tipreflesh();                            //���һ�β�������ʾ��������
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
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)   //���˹��ܴ�����
			{
				//���䲿��
				//�������º���
				//����ֵ���º���
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //���ֹ��ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // �Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //�ź����ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //�Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //�������ܴ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //�ؿ����ܾ���ʵ��
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //�˳�����
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

	//״̬��ͼ����ʾ
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
				logicturn(zb);                           //����Ҫ������ʾ��
				tipreflesh();                            //���һ�β�������ʾ��������
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
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)   //���˹��ܴ�����
			{
				//���䲿��
				//�������º���
				//����ֵ���º���
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //���ֹ��ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // �Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //�ź����ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //�Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //�������ܴ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //�ؿ����ܾ���ʵ��
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //�˳�����
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

	//״̬��ͼ����ʾ
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
				logicturn(zb);                           //����Ҫ������ʾ��
				tipreflesh();                            //���һ�β�������ʾ��������
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
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)   //���˹��ܴ�����
			{
				//���䲿��
				//�������º���
				//����ֵ���º���
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //���ֹ��ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // �Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //�ź����ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //�Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //�������ܴ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //�ؿ����ܾ���ʵ��
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //�˳�����
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

	//״̬��ͼ����ʾ
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
				logicturn(zb);                           //����Ҫ������ʾ��
				tipreflesh();                            //���һ�β�������ʾ��������
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
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 370 && ms.y <= 410)   //���˹��ܴ�����
			{
				//���䲿��
				//�������º���
				//����ֵ���º���
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //���ֹ��ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // �Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //�ź����ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //�Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //�������ܴ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //�ؿ����ܾ���ʵ��
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //�˳�����
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

	//״̬��ͼ����ʾ
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
    //�˴�������ʾ���ֵĴ���Ϳ�����
	/*
	
	
	*/
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{
			
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //���ֹ��ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // �Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //�ź����ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //�Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //�������ܴ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //�ؿ����ܾ���ʵ��
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //�˳�����
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

	//״̬��ͼ����ʾ
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
	//�˴�������ʾ���ֵĴ���Ϳ�����
	/*


	*/
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{

			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //���ֹ��ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // �Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //�ź����ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //�Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //�������ܴ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //�ؿ����ܾ���ʵ��
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //�˳�����
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

	//״̬��ͼ����ʾ
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
	//�˴�������ʾ���ֵĴ���Ϳ�����
	/*


	*/
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{

			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //���ֹ��ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // �Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //�ź����ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //�Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //�������ܴ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //�ؿ����ܾ���ʵ��
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //�˳�����
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

	//״̬��ͼ����ʾ
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
	//�˴�������ʾ���ֵĴ���Ϳ�����
	/*


	*/
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{

			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //���ֹ��ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // �Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //�ź����ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //�Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //�������ܴ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //�ؿ����ܾ���ʵ��
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //�˳�����
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

	//״̬��ͼ����ʾ
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
	//�˴�������ʾ���ֵĴ���Ϳ�����
	/*


	*/
	while (1)
	{
		ms = GetMouseMsg();
		if (ms.uMsg == WM_LBUTTONUP)
		{

			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435)   //���ֹ��ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 400 && ms.y <= 435) // �Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 400 && ms.y <= 435) //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470) //�ź����ܴ�����
			{
				if (ms.x >= 650 && ms.x <= 680 && ms.y >= 435 && ms.y <= 470)  //�Ӵ�����
				{

				}
				if (ms.x >= 680 && ms.x <= 710 && ms.y >= 435 && ms.y <= 470)  //��С����
				{

				}
			}
			if (ms.x >= 650 && ms.x <= 680 && ms.y >= 470 && ms.y <= 505)   //�������ܴ�����
			{

			}
			if (ms.x >= 680 && ms.x <= 800 && ms.y >= 470 && ms.y <= 510)  //�ؿ����ܾ���ʵ��
			{

			}
			if (ms.x >= 700 && ms.x <= 800 && ms.y >= 520 && ms.y <= 580)  //�˳�����
			{
				closegraph();
			}
		}
	}

}
//����û�õĵط���ע���ҵĴ�������ԱȽ϶࣬��Ϊ������Ҫ�����仯����������Ƕ�ף�ִ�д���д��start������
int main()
{
	
	gamebegin();
	
	
	return 0;
}