#include<iostream>
using namespace std;
#include"SpeechManager.h"

int main()
{
	srand((unsigned)time(NULL));
	SpeechManager sm;
	while (true)
	{
		//��ʾ�˵����ܣ�
		/*for (map<int, speaker>::iterator it = sm.m_speaker.begin(); it != sm.m_speaker.end(); it++)
		{
			cout << "���Ϊ��" << it->first << "������" << it->second.m_name <<"�ɼ���" << it->second.m_score[0]<<endl;

		}*/

		sm.Show_Menu();
		//�û�ָ��
		int choice;
		cin >> choice;
		switch (choice)
		{
			//��ʼ����
		case 1:
			sm.StartGame();
			break;
			//�鿴�����¼
		case 2:
			break;
			//��ձ�����¼
		case 3:
			break;
			//�˳���������
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