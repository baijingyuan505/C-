#include"Role.h"
#include"Stage.h"
#include"Sound.h"
#include<iostream>
int main()
{
	


	Role* CaoCao;
	Role* ZhangFei;
	Role* ZhaoYun;
	Role* GuanYu;
	Role* MaChao;
	Role* HuangZhong;
	Role* S1;
	Role* S2;
	Role* S3;
	Role* S4;
	Stage level;//level是随便实例化的,用来初始化逻辑棋盘

	/*以上是实例化*/

	int t;//存放键盘输入的关卡
	
	switch (t)
	{//delete放在结束游戏函数end()中
		case 1:
		{
			
			CaoCao=new Boss{ 1,1,0 };
			GuanYu=new General_1{ 2, 1, 4 };
			ZhaoYun = new General_1{ 3, 2, 3 };
			MaChao = new General_1{ 4, 0, 2 };
			HuangZhong = new General_1{ 5, 2, 2 };
			ZhangFei = new General_1{ 6, 0, 3 };
			S1=new Soldier{ 7 ,0,0 };
			S2=new Soldier{ 8 ,3,0 };
			S3=new Soldier{ 9 ,0,1 };
			S4=new Soldier{ 10,3,1 };
			level.Stage1();
			break;
		}
	
		case 2:
		{
			CaoCao= new Boss{ 1,1,0 };
			GuanYu = new General_1{ 2, 2, 2 };
			ZhaoYun = new General_1{ 3, 1, 4 };
			MaChao = new General_2{ 4, 1, 2 };
			HuangZhong = new General_2{ 5, 0, 2 };
			ZhangFei = new General_1{ 6, 2, 3 };
			S1 =new Soldier{ 7 ,0,0 };
			S2 =new Soldier{ 8 ,3,0 };
			S3 =new Soldier{ 9 ,0,1 };
			S4 =new Soldier{ 10,3,1 };
			level.Stage2();


			break;
		}

		case 3:
		{
			CaoCao=new Boss{ 1,1,0 };
			GuanYu = new General_1{ 2, 1, 4 };
			ZhaoYun = new General_2{ 3, 3, 0 };
			MaChao = new General_2{ 4, 2, 2 };
			HuangZhong = new General_2{ 5, 1, 2 };
			ZhangFei = new General_2{ 6, 0, 0 };
			S1 =new Soldier{ 7 ,0,3 };
			S2 =new Soldier{ 8 ,3,3 };
			S3 =new Soldier{ 9 ,0,4 };
			S4 =new Soldier{ 10,3,4 };
			level.Stage3();


			break;
		}

		case 4:
		{
			CaoCao= new Boss{ 1,1,0 };
			GuanYu = new General_1{ 2, 0, 4 };
			ZhaoYun = new General_2{ 3, 0, 0 };
			MaChao = new General_2{ 4, 1, 2 };
			HuangZhong = new General_2{ 5, 3, 0 };
			ZhangFei = new General_1{ 6, 2, 4 };
			S1 =new Soldier{ 7 ,0,2 };
			S2 =new Soldier{ 8 ,3,2 };
			S3 =new Soldier{ 9 ,0,3 };
			S4 =new Soldier{ 10,3,3 };
			level.Stage4();


			break;
		}
		
		case 5:
		{
			CaoCao=new Boss{ 1,1,0 };
			GuanYu = new General_1{ 2, 1, 3 };
			ZhaoYun = new General_2{ 3, 3, 0 };
			MaChao = new General_1{ 4, 0, 2 };
			HuangZhong = new General_1{ 5, 2, 2 };
			ZhangFei = new General_2{ 6, 0, 3 };
			S1 =new Soldier{ 7 ,0,0 };
			S2 =new Soldier{ 8 ,3,0 };
			S3 =new Soldier{ 9 ,0,1 };
			S4 =new Soldier{ 10,3,1 };
			level.Stage5();


			break;
		}
	}

	BGM music;
	music.play_music();


	/*初始化完毕 开始游戏*/
	
	CreateThread(NULL, NULL, CaoCao_start, NULL, NULL, NULL);
	//播放曹操护驾1,护驾2,诸葛亮:你可识得此阵.播放时间可能有7~8秒,考虑设置一下点击后开始游戏?
	
	while (true)
	{
		int key;//把鼠标点击转换成不同的信号
		switch (key)
		{
			/*case n:GuanYu->move_up();
			GuanYu->Stride+=1;//某人移动一次,他的步数+1
			break;
				
			case n+1:CaoCao->move_down();
			CaoCao->Stride+=1;
			break;
			
			etc...
			*/

		}
		if (GuanYu->Stride == 1)
		{
			CreateThread(NULL, NULL, GuanYu_1, NULL, NULL, NULL);//关羽在此
		}
		else if (GuanYu->Stride == 25)
		{
			CreateThread(NULL, NULL, GuanYu_25, NULL, NULL, NULL);//还不速速领死
		}
		else if (GuanYu->Stride == 50)
		{
			CreateThread(NULL, NULL, GuanYu_50, NULL, NULL, NULL);//取汝狗头
		}
		else if (GuanYu->Stride == 100)
		{
			CreateThread(NULL, NULL, GuanYu_100, NULL, NULL, NULL);//拿命来
		}
		else if (ZhaoYun->Stride == 1)
		{
			CreateThread(NULL, NULL, ZhaoYun_1, NULL, NULL, NULL);//吾乃赵子龙
		}
		else if (ZhaoYun->Stride == 25)
		{
			CreateThread(NULL, NULL, ZhaoYun_25, NULL, NULL, NULL);//一片赤胆平乱世
		}
		else if (CaoCao->Stride == 5)
		{
			CreateThread(NULL, NULL, CaoCao_5, NULL, NULL, NULL);//诸葛亮:你的计谋被识破了
		}
		else if (MaChao->Stride == 1)
		{
			CreateThread(NULL, NULL, MaChao_1, NULL, NULL, NULL);//全军突击
		}
		else if (ZhangFei->Stride == 1)
		{
			CreateThread(NULL, NULL, ZhangFei_1, NULL, NULL, NULL);//张飞在此
		}
		else if (HuangZhong->Stride == 5)
		{
			CreateThread(NULL, NULL, HuangZhong_1, NULL, NULL, NULL);//三步之内取你小命
		}
		else if (CaoCao->x == 1 && CaoCao->y==4)//曹操过关
		{
			CreateThread(NULL, NULL, CaoCao_end, NULL, NULL, NULL);
			//曹操:哈哈哈哈哈
			//诸葛亮:我的计谋竟被...
			end();
		}

	}
	
	system("pause");
}