#pragma once
#include <windows.h>
#include <mmsystem.h>//多媒体接口库
using namespace std;
#pragma comment(lib,"winmm.lib")//多媒体静态库

/**************************************
本文件定义了背景音乐线程与人物语音线程
***************************************/

class BGM
{
public:
    void play_music()
    {
        mciSendString("open 1.mp3 alias bgm", 0, 0, 0);//打开音频文件,并重命名为music1
        mciSendString("play bgm repeat", 0, 0, 0); //开始循环播放music1
    }

    void pause_music()
    {
        mciSendString("pause music1", 0, 0, 0);//暂停播放music1
    }
    void setvolume(signed int u_volume)
    {
        char cmd[256];//指令字符串
        char ch_volume[256];//音量字符串
        mciSendString("status music1 volume", ch_volume, 255, 0);//获取音量大小：初始音量大小为1000
        long l_volume = strtol(ch_volume, NULL, 10);//把音量字符串类型转为整型以便修改音量大小
        wsprintf(cmd, "setaudio music1 volume to %i", l_volume + u_volume);//修改音量大小(正数提高音量，负数降低音量，建议每次调整大小为100的倍数)
        mciSendString(cmd, NULL, 0, NULL);//设置music1音量
    }
    void close_music() 
    {
        mciSendString("close music1", 0, 0, 0);//关闭音频文件
    }
};

DWORD WINAPI CaoCao_5(LPVOID lpvoid)
{
    mciSendString("open CaoCao_5.mp3 alias CaoCao_5", 0, 0, 0);
    mciSendString("play CaoCao_5 wait", 0, 0, 0);
    mciSendString("close CaoCao_5", 0, 0, 0);
    return 0;
}
DWORD WINAPI CaoCao_end(LPVOID lpvoid)
{
    mciSendString("open CaoCao_end.mp3 alias CaoCao_end", 0, 0, 0);
    mciSendString("play CaoCao_end wait", 0, 0, 0);
    mciSendString("close CaoCao_end", 0, 0, 0);
    mciSendString("open ZhuGe_end.mp3 alias ZhuGe_end", 0, 0, 0);
    mciSendString("play ZhuGe_end wait", 0, 0, 0);
    mciSendString("close ZhuGe_end", 0, 0, 0);
    return 0;
}
DWORD WINAPI CaoCao_start(LPVOID lpvoid)
{
    mciSendString("open ZhuGe_start1.mp3 alias ZhuGe_start1", 0, 0, 0);
    mciSendString("play ZhuGe_start1 wait", 0, 0, 0);
    mciSendString("close ZhuGe_start1", 0, 0, 0);
    mciSendString("open CaoCao_start1.mp3 alias CaoCao_start1", 0, 0, 0);
    mciSendString("play CaoCao_start1 wait", 0, 0, 0);
    mciSendString("close CaoCao_start1", 0, 0, 0);
    mciSendString("open CaoCao_start2.mp3 alias CaoCao_start2", 0, 0, 0);
    mciSendString("play CaoCao_start2 wait", 0, 0, 0);
    mciSendString("close CaoCao_start2", 0, 0, 0);
    return 0;
}
DWORD WINAPI GuanYu_1(LPVOID lpvoid)
{
    mciSendString("open GuanYu_1.mp3 alias GuanYu_1", 0, 0, 0);
    mciSendString("play GuanYu_1 wait", 0, 0, 0);
    mciSendString("close GuanYu_1", 0, 0, 0);
    return 0;
}
DWORD WINAPI GuanYu_100(LPVOID lpvoid)
{
    mciSendString("open GuanYu_100.mp3 alias GuanYu_100", 0, 0, 0);
    mciSendString("play GuanYu_100 wait", 0, 0, 0);
    mciSendString("close GuanYu_100", 0, 0, 0);
    return 0;
}
DWORD WINAPI GuanYu_25(LPVOID lpvoid)
{
    mciSendString("open GuanYu_25.mp3 alias GuanYu_25", 0, 0, 0);
    mciSendString("play GuanYu_25 wait", 0, 0, 0);
    mciSendString("close GuanYu_25", 0, 0, 0);
    return 0;
}
DWORD WINAPI GuanYu_50(LPVOID lpvoid)
{
    mciSendString("open GuanYu_50.mp3 alias GuanYu_50", 0, 0, 0);
    mciSendString("play GuanYu_50 wait", 0, 0, 0);
    mciSendString("close GuanYu_50", 0, 0, 0);
    return 0;
}
DWORD WINAPI HuangZhong_1(LPVOID lpvoid)
{
    mciSendString("open HuangZhong_1.mp3 alias HuangZhong_1", 0, 0, 0);
    mciSendString("play HuangZhong_1 wait", 0, 0, 0);
    mciSendString("close HuangZhong_1", 0, 0, 0);
    return 0;
}
DWORD WINAPI MaChao_1(LPVOID lpvoid)
{
    mciSendString("open MaChao_1.mp3 alias MaChao_1", 0, 0, 0);
    mciSendString("play MaChao_1 wait", 0, 0, 0);
    mciSendString("close MaChao_1", 0, 0, 0);
    return 0;
}
DWORD WINAPI ZhangFei_1(LPVOID lpvoid)
{
    mciSendString("open ZhangFei_1.mp3 alias ZhangFei_1", 0, 0, 0);
    mciSendString("play ZhangFei_1 wait", 0, 0, 0);
    mciSendString("close ZhangFei_1", 0, 0, 0);
    return 0;
}
DWORD WINAPI ZhaoYun_1(LPVOID lpvoid)
{
    mciSendString("open ZhaoYun_1.mp3 alias ZhaoYun_1", 0, 0, 0);
    mciSendString("play ZhaoYun_1 wait", 0, 0, 0);
    mciSendString("close ZhaoYun_1", 0, 0, 0);
    return 0;
}
DWORD WINAPI ZhaoYun_25(LPVOID lpvoid)
{
    mciSendString("open ZhaoYun_25.mp3 alias ZhaoYun_25", 0, 0, 0);
    mciSendString("play ZhaoYun_25 wait", 0, 0, 0);
    mciSendString("close ZhaoYun_25", 0, 0, 0);
    return 0;
}



