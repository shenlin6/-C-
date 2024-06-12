#include"SpeechManager.h"
#include<string>
#include<algorithm>
#include<iostream>

//构造函数
SpeechManager::SpeechManager()
{
	//一开始就调用将容器置空的函数
	this->InitSpeak();
	this->CreateSpeaker();
}

void SpeechManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
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
		//将全部容器置空(this?)
		v1.clear();
		v2.clear();
		VictorySpeakers.clear();
		m_speaker.clear();

		//初始化比赛的轮数
		this->index = 1;
	}
	void SpeechManager::CreateSpeaker()
	{
		//初始化选手的姓名：
		string nameseed = "ABCDEFGHIJKL";
		for (int i = 0; i < nameseed.size(); i++)
		{
			string name = "选手";
			name += nameseed[i];

			speaker sp;
			sp.m_name = name;
			//初始化选手的分数
			for (int j = 0; j < 2; j++)
			{
				sp.m_score[j] = 0;
			}

			//初始化选手的编号
		this->v1.push_back(i + 10001);
		   //将选手的编号和选手放入map容器中
		this->m_speaker.insert(make_pair(i+10001, sp));
			


		}
	}
	//开始抽签的函数
	void SpeechManager::SpeechDraw()
	{
		cout << "第" <<index<<"轮正在抽签"<< endl;
		cout << "抽签的比赛顺序如下：" << endl;
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
	
	//显示晋级/获胜选手的分数
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
		cout << "晋级选手如下：" << endl;
		for (vector<int>::const_iterator it = vd.begin(); it != vd.end(); it++)
		{
			cout << "编号：" << *it << " 姓名：" << this->m_speaker[*it].m_name
				<< " 得分：" << m_speaker[*it].m_score[this->index - 1] << endl;
		}

		system("pause");
		system("cls");

	}

	//开始比赛的函数
	void SpeechManager::SpeechContest()
	{
		cout << "第" << this->index << "轮比赛正式开始！" << endl;
		//用临时容器装第一轮或者第二轮的容器数据
		vector<int>v;
		//判断是第一轮还是第二轮
		if (this->index == 1)
		{
			v = v1;
		}
		else if(this->index==2)
		{
			v = v2;
		}
		//判断进行多少次循环的变量
		int num = 0;

		multimap<double, int,greater<double>>mp;//用于通过得分筛选前三名选手晋级

		//遍历临时容器数组中的所有数据
		for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
		{
			num++;
			double average = 0;//循环开始的时候把平均分置为0
			//评委打分(带有小数点，方便排名)：
			deque<double>d;//去掉最高分和最低分
			for (int i=0;i<10;i++)
			{
				double score = 0;
			    score = (rand() % 601 + 400)/10;//60-100分（带有小数点）
				d.push_back(score);
			}
			//当十位评委都打完一位选手的分后，先排序，再去除最高分和最低分
			sort(d.begin(), d.end(), greater<double>());//降序排列
			//去除最高分、最低分
			d.pop_back();
			d.pop_front();
			//计算平均数
			double sum = (double)(accumulate(d.begin(), d.end(), 0.0f));
			average = sum / (double)d.size();

			this->m_speaker[*it].m_score[this->index - 1] = average;//将该选手第1/2轮成绩放入m_speaker容器中

			mp.insert(make_pair(average, *it));//将得分和编号插入临时容器
			

			if (num % 6 == 0)
			{
				//开始筛选前三名
				int count=0;//记录删选次数的变量
				if (index == 1)
				{
					
					for (multimap<double, int>::iterator it = mp.begin(); it != mp.end()&&count<3; it++,count++)
					{
						v2.push_back((*it).second);//将晋级人员插入第二轮比赛的容器

						
				    }
					cout << "第" << num / 6 << "小组比赛结果为：" << endl;
					for (multimap<double, int,greater<double>>::iterator it = mp.begin(); it != mp.end(); it++)
					{
						cout << "编号：" << it->second << " 姓名：" << this->m_speaker[it->second].m_name <<
							" 成绩" << this->m_speaker[it->second].m_score[index-1] << endl;
					}

			    }
				else if(index==2)
				{
					
					for (multimap<double, int>::iterator it = mp.begin(); it != mp.end() && count < 3; it++, count++)
					{
				        VictorySpeakers.push_back((*it).second);//将晋级人员插入获胜选手的容器
					}

					cout << "比赛结果如下：" << endl;
					for (multimap<double, int,greater<double>>::iterator it = mp.begin(); it != mp.end(); it++)
					{
						cout << "编号：" << it->second << "姓名：" << this->m_speaker[index - 1].m_name <<
							"成绩" << this->m_speaker[it->second].m_score[index-1] << endl;
					}
				}
				//每一组（6个人）筛选完过后需要把临时容器置空,避免插入重复数据
				mp.clear();
			}
		}

		cout << "第" << index << "轮比赛完毕" << endl;
		cout << "---------------------------------------" << endl;
		SpeechManager::ShowScore();//因为函数调用完后会自动回收数据，因此需要在内部调用函数，才能保证分数不被清空
		
	}

	void SpeechManager::SaveScore()
	{
		ofstream ofs;
		ofs.open("speech.csv", ios::out | ios::app);//app:以追加的方式写文件，方便添加多届比赛结果（勿忘写 | ）

		for (vector<int>::const_iterator it = VictorySpeakers.begin(); it != VictorySpeakers.end(); it++)
		{
			ofs << *it << "," << m_speaker[*it].m_score[1] << ",";
		}
		ofs << endl;
		ofs.close();
		cout << "比赛结果保存完毕" << endl;
	}

	void SpeechManager::StartGame()
	{
		//1、抽签
		SpeechDraw();
		//2、比赛
		SpeechContest();
		//3、显示晋级结果
		//在SpeechContest函数内部实现了
		//第二轮比赛
		this->index++;
		//1、抽签
		SpeechDraw();
		//2、比赛
		SpeechContest();
		//3、显示最终结果
		//在SpeechContest函数内部实现了
		//4、保存分数
		SaveScore();
		cout << "本届比赛结束" << endl;
		system("pause");
		system("cls");

	}
	
//析构函数
SpeechManager::~SpeechManager()
{
}



