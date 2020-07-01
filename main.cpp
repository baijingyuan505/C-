#include <iostream>
#include<conio.h>
#include "bgm.h"
#include "optimum.h"

int main()
{
    BGM bgm;
    bgm.play_music();//开始播放音乐

	switch (char key = getch())//按键控制
	{
    case "9"://自动示例最优解
        int i = getch();
        optimum instance(i);//选择展示哪一关的最优解
        instance.movebyoptimum()const;//按照最优解一步步自动移动
        break;
    case "0":
        bgm.close_music();//停止播放音乐
        break;
	case "+":
        bgm.setvolume(+100);//提高音量100
		break;
	case "-":
        bgm.setvolume(-100);//降低音量100
        break;
	}

    system("pause");//冻结屏幕
    return 0;
}

