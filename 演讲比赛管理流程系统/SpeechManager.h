#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include<deque>
#include"speaker.h"
#include<numeric>
#include<fstream>
//管理类需要实现：

//-提供菜单界面与用户交互
//- 对演讲比赛流程进行控制
//- 与文件的读写交互

class SpeechManager
{
public:
	SpeechManager();

	//添加菜单功能
	void Show_Menu();

	void ExitSystem();

	//添加演讲者的属性
// 
//保存第一轮比赛选手
	vector<int>v1;
	//第一轮获胜要参加第二轮的比赛选手
	vector<int>v2;
	//第二轮获胜的比赛选手
	vector<int>VictorySpeakers;
	//所有选手和编号
	map<int, speaker>m_speaker;
	
	//记录比赛轮数
	int index;

	//初始化选手属性的函数(将容器全部置为空)
	void InitSpeak();
	//创建比赛选手的函数
	void CreateSpeaker();
	//流程开始的函数
	void StartGame();
	//抽签的函数
	void SpeechDraw();
	//比赛开始的函数
	void SpeechContest();
	//显示比赛晋级/获胜的结果
	void ShowScore();
	//保存比赛结果的函数
	void SaveScore();
	//析构函数
	~SpeechManager();

};



