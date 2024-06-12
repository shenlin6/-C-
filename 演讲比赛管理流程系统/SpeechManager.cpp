#include"SpeechManager.h"
#include<string>
#include<algorithm>
#include<iostream>

//���캯��
SpeechManager::SpeechManager()
{
	//һ��ʼ�͵��ý������ÿյĺ���
	this->InitSpeak();
	this->CreateSpeaker();
}

void SpeechManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
	void SpeechManager::ExitSystem()
	{
		system("pause");
		exit(0);
	}
	void SpeechManager::InitSpeak()
	{
		//��ȫ�������ÿ�(this?)
		v1.clear();
		v2.clear();
		VictorySpeakers.clear();
		m_speaker.clear();

		//��ʼ������������
		this->index = 1;
	}
	void SpeechManager::CreateSpeaker()
	{
		//��ʼ��ѡ�ֵ�������
		string nameseed = "ABCDEFGHIJKL";
		for (int i = 0; i < nameseed.size(); i++)
		{
			string name = "ѡ��";
			name += nameseed[i];

			speaker sp;
			sp.m_name = name;
			//��ʼ��ѡ�ֵķ���
			for (int j = 0; j < 2; j++)
			{
				sp.m_score[j] = 0;
			}

			//��ʼ��ѡ�ֵı��
		this->v1.push_back(i + 10001);
		   //��ѡ�ֵı�ź�ѡ�ַ���map������
		this->m_speaker.insert(make_pair(i+10001, sp));
			


		}
	}
	//��ʼ��ǩ�ĺ���
	void SpeechManager::SpeechDraw()
	{
		cout << "��" <<index<<"�����ڳ�ǩ"<< endl;
		cout << "��ǩ�ı���˳�����£�" << endl;
		cout << "---------------------------" << endl;
		if (this->index == 1)
		{
			random_shuffle(v1.begin(), v1.end());
			for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
			{
				cout << *it << " ";
			}
			cout << endl;
		}
		if (this->index == 2)
		{
			random_shuffle(v2.begin(), v2.end());
			for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
			{
				cout << *it << " ";
			}
			cout << endl;
		}
		system("pause");
	}
	
	//��ʾ����/��ʤѡ�ֵķ���
	void SpeechManager::ShowScore()
	{
		vector<int>vd;

		if (this->index == 1)
		{
			vd = this->v2;
		}
		else if (this->index == 2)
		{
			vd = this->VictorySpeakers;
		}
		cout << "����ѡ�����£�" << endl;
		for (vector<int>::const_iterator it = vd.begin(); it != vd.end(); it++)
		{
			cout << "��ţ�" << *it << " ������" << this->m_speaker[*it].m_name
				<< " �÷֣�" << m_speaker[*it].m_score[this->index - 1] << endl;
		}

		system("pause");
		system("cls");

	}

	//��ʼ�����ĺ���
	void SpeechManager::SpeechContest()
	{
		cout << "��" << this->index << "�ֱ�����ʽ��ʼ��" << endl;
		//����ʱ����װ��һ�ֻ��ߵڶ��ֵ���������
		vector<int>v;
		//�ж��ǵ�һ�ֻ��ǵڶ���
		if (this->index == 1)
		{
			v = v1;
		}
		else if(this->index==2)
		{
			v = v2;
		}
		//�жϽ��ж��ٴ�ѭ���ı���
		int num = 0;

		multimap<double, int,greater<double>>mp;//����ͨ���÷�ɸѡǰ����ѡ�ֽ���

		//������ʱ���������е���������
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			num++;
			double average = 0;//ѭ����ʼ��ʱ���ƽ������Ϊ0
			//��ί���(����С���㣬��������)��
			deque<double>d;//ȥ����߷ֺ���ͷ�
			for (int i=0;i<10;i++)
			{
				double score = 0;
			    score = (rand() % 601 + 400)/10;//60-100�֣�����С���㣩
				d.push_back(score);
			}
			//��ʮλ��ί������һλѡ�ֵķֺ���������ȥ����߷ֺ���ͷ�
			sort(d.begin(), d.end(), greater<double>());//��������
			//ȥ����߷֡���ͷ�
			d.pop_back();
			d.pop_front();
			//����ƽ����
			double sum = (double)(accumulate(d.begin(), d.end(), 0.0f));
			average = sum / (double)d.size();

			this->m_speaker[*it].m_score[this->index - 1] = average;//����ѡ�ֵ�1/2�ֳɼ�����m_speaker������

			mp.insert(make_pair(average, *it));//���÷ֺͱ�Ų�����ʱ����
			

			if (num % 6 == 0)
			{
				//��ʼɸѡǰ����
				int count=0;//��¼ɾѡ�����ı���
				if (index == 1)
				{
					
					for (multimap<double, int>::iterator it = mp.begin(); it != mp.end()&&count<3; it++,count++)
					{
						v2.push_back((*it).second);//��������Ա����ڶ��ֱ���������

						
				    }
					cout << "��" << num / 6 << "С��������Ϊ��" << endl;
					for (multimap<double, int,greater<double>>::iterator it = mp.begin(); it != mp.end(); it++)
					{
						cout << "��ţ�" << it->second << " ������" << this->m_speaker[it->second].m_name <<
							" �ɼ�" << this->m_speaker[it->second].m_score[index-1] << endl;
					}

			    }
				else if(index==2)
				{
					
					for (multimap<double, int>::iterator it = mp.begin(); it != mp.end() && count < 3; it++, count++)
					{
				        VictorySpeakers.push_back((*it).second);//��������Ա�����ʤѡ�ֵ�����
					}

					cout << "����������£�" << endl;
					for (multimap<double, int,greater<double>>::iterator it = mp.begin(); it != mp.end(); it++)
					{
						cout << "��ţ�" << it->second << "������" << this->m_speaker[index - 1].m_name <<
							"�ɼ�" << this->m_speaker[it->second].m_score[index-1] << endl;
					}
				}
				//ÿһ�飨6���ˣ�ɸѡ�������Ҫ����ʱ�����ÿ�,��������ظ�����
				mp.clear();
			}
		}

		cout << "��" << index << "�ֱ������" << endl;
		cout << "---------------------------------------" << endl;
		SpeechManager::ShowScore();//��Ϊ�������������Զ��������ݣ������Ҫ���ڲ����ú��������ܱ�֤�����������
		
	}

	void SpeechManager::SaveScore()
	{
		ofstream ofs;
		ofs.open("speech.csv", ios::out | ios::app);//app:��׷�ӵķ�ʽд�ļ���������Ӷ��������������д | ��

		for (vector<int>::const_iterator it = VictorySpeakers.begin(); it != VictorySpeakers.end(); it++)
		{
			ofs << *it << "," << m_speaker[*it].m_score[1] << ",";
		}
		ofs << endl;
		ofs.close();
		cout << "��������������" << endl;
	}

	void SpeechManager::StartGame()
	{
		//1����ǩ
		SpeechDraw();
		//2������
		SpeechContest();
		//3����ʾ�������
		//��SpeechContest�����ڲ�ʵ����
		//�ڶ��ֱ���
		this->index++;
		//1����ǩ
		SpeechDraw();
		//2������
		SpeechContest();
		//3����ʾ���ս��
		//��SpeechContest�����ڲ�ʵ����
		//4���������
		SaveScore();
		cout << "�����������" << endl;
		system("pause");
		system("cls");

	}
	
//��������
SpeechManager::~SpeechManager()
{
}



