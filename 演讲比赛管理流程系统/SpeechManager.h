#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<deque>
#include"speaker.h"
#include<numeric>
#include<fstream>
//��������Ҫʵ�֣�

//-�ṩ�˵��������û�����
//- ���ݽ��������̽��п���
//- ���ļ��Ķ�д����

class SpeechManager
{
public:
	SpeechManager();

	//��Ӳ˵�����
	void Show_Menu();

	void ExitSystem();

	//����ݽ��ߵ�����
// 
//�����һ�ֱ���ѡ��
	vector<int>v1;
	//��һ�ֻ�ʤҪ�μӵڶ��ֵı���ѡ��
	vector<int>v2;
	//�ڶ��ֻ�ʤ�ı���ѡ��
	vector<int>VictorySpeakers;
	//����ѡ�ֺͱ��
	map<int, speaker>m_speaker;
	
	//��¼��������
	int index;

	//��ʼ��ѡ�����Եĺ���(������ȫ����Ϊ��)
	void InitSpeak();
	//��������ѡ�ֵĺ���
	void CreateSpeaker();
	//���̿�ʼ�ĺ���
	void StartGame();
	//��ǩ�ĺ���
	void SpeechDraw();
	//������ʼ�ĺ���
	void SpeechContest();
	//��ʾ��������/��ʤ�Ľ��
	void ShowScore();
	//�����������ĺ���
	void SaveScore();
	//��������
	~SpeechManager();

};



