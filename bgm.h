#pragma once
#include <windows.h>
#include <mmsystem.h>//��ý��ӿڿ�
using namespace std;
#pragma comment(lib,"winmm.lib")//��ý�徲̬��

class BGM
{
public:
    void play_music() {
        mciSendString("open 1.mp3 alias music1", 0, 0, 0);//����Ƶ�ļ�,��������Ϊmusic1
        mciSendString("play music1 repeat", 0, 0, 0); //��ʼѭ������music1
    };
    void pause_music() {
        mciSendString("pause music1", 0, 0, 0);//��ͣ����music1
    };
    void setvolume(signed int u_volume) {
        char cmd[256];//ָ���ַ���
        char ch_volume[256];//�����ַ���
        mciSendString("status music1 volume", ch_volume, 255, 0);//��ȡ������С����ʼ������СΪ1000
        long l_volume = strtol(ch_volume, NULL, 10);//�������ַ�������תΪ�����Ա��޸�������С
        wsprintf(cmd, "setaudio music1 volume to %i", l_volume + u_volume);//�޸�������С(�������������������������������ÿ�ε�����СΪ100�ı���)
        mciSendString(cmd, NULL, 0, NULL);//����music1����
    };
    void close_music() {
        mciSendString("close music1", 0, 0, 0);//�ر���Ƶ�ļ�
    }
};