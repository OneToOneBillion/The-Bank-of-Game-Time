#include<iostream>
#include<time.h>

using namespace std;

class Timer
{
public:
	Timer();
	bool GetIsPause(){return IsPause;}
	bool GetIsStope(){return IsStop;}
	long int GetStartTime(){return StartTime;}
	long int GetPauseTime(){return PauseTime;}
	long int GetClickTime(){return time(0)-StartTime;}				//�õ�ʱ���
	void Start();
	void Pause();
	void Stop();	
	void show();	
private:
	//���濪ʼ����ͣʱ�̵�ʱ��
	long int StartTime;							//��ʼʱ��
	long int PauseTime;							//��ͣʱ��
	bool IsPause;								//�Ƿ���ͣ
	bool IsStop;								//�Ƿ�ֹͣ
};

Timer::Timer()
{
	IsPause=false;
	IsStop=true;
	PauseTime=0;
}

void Timer::Start()
{
	if(IsStop)				//�������ֹͣ״̬�����ÿ�ʼʱ�䣬��IsStop��false
	{
		StartTime=time(0);
		IsStop=false;
	}
	else if(IsPause)			//���������ͣ״̬������StartTime
	{
		IsPause=false;
		StartTime+=time(0)-PauseTime;
	}
}


void Timer::Pause() //��ͣ 
{
	if(IsStop||IsPause) //�������ֹͣ/��ͣ״̬,�˶��������κδ���ֱ�ӷ��� 
		return; 
	else    //�������Ϊ��ͣ״̬
	{
		IsPause = true;
		PauseTime = time(0); //��ȡ��ͣʱ�� 
	}
}

void Timer::Stop()	//ֹͣ
{
	if(IsStop)			//�������ֹͣ״̬
	{
		return;
	}
	else if(IsPause)		//����Ѿ���ֹͣ״̬
	{
		IsPause=false;
		IsStop=true;
	}
	else if(!IsStop)		//����Ѿ�ֹͣ��
	{
		IsStop=true;
	}
}

void Timer::show()			//���
{
	long int t=time(0)-StartTime;
	cout<<t/3600<<":"<<t/60<<":"<<t%60<<endl;
}
