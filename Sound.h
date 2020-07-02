#pragma once
#include <windows.h>
#include <mmsystem.h>//��ý��ӿڿ�
using namespace std;
#pragma comment(lib,"winmm.lib")//��ý�徲̬��

/**************************************
���ļ������˱��������߳������������߳�
***************************************/

class BGM
{
public:
    void play_music()
    {
        mciSendString("open 1.mp3 alias bgm", 0, 0, 0);//����Ƶ�ļ�,��������Ϊmusic1
        mciSendString("play bgm repeat", 0, 0, 0); //��ʼѭ������music1
    }

    void pause_music()
    {
        mciSendString("pause music1", 0, 0, 0);//��ͣ����music1
    }
    void setvolume(signed int u_volume)
    {
        char cmd[256];//ָ���ַ���
        char ch_volume[256];//�����ַ���
        mciSendString("status music1 volume", ch_volume, 255, 0);//��ȡ������С����ʼ������СΪ1000
        long l_volume = strtol(ch_volume, NULL, 10);//�������ַ�������תΪ�����Ա��޸�������С
        wsprintf(cmd, "setaudio music1 volume to %i", l_volume + u_volume);//�޸�������С(�������������������������������ÿ�ε�����СΪ100�ı���)
        mciSendString(cmd, NULL, 0, NULL);//����music1����
    }
    void close_music() 
    {
        mciSendString("close music1", 0, 0, 0);//�ر���Ƶ�ļ�
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



