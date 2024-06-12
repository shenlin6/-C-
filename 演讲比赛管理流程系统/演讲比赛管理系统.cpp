#include<iostream>
using namespace std;
#include"SpeechManager.h"

int main()
{
	srand((unsigned)time(NULL));
	SpeechManager sm;
	while (true)
	{
		//显示菜单功能：
		/*for (map<int, speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++)
		{
			cout << "编号为：" << it->first << "姓名：" << it->second.m_name <<"成绩：" << it->second.m_score[0]<<endl;

		}*/

		sm.Show_Menu();
		//用户指令
		int choice;
		cin >> choice;
		switch (choice)
		{
			//开始比赛
		case 1:
			sm.StartGame();
			break;
			//查看往届记录
		case 2:
			break;
			//清空比赛记录
		case 3:
			break;
			//退出比赛程序
		case 0:
			sm.ExitSystem();
			break;
		default:
			system("cls");
  			break;
		}
	}

	system("pause");
	return 0;
}