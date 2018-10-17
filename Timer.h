#include<iostream>
#include<time.h>

using namespace std;

class MyTimer
{
public:
	MyTimer();
	~MyTimer();
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

MyTimer::MyTimer()
{
	IsPause=false;
	IsStop=true;
	PauseTime=0;
}

MyTimer::~MyTimer()
{

}
void MyTimer::Start()
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


void MyTimer::Pause() //��ͣ 
{
	if(IsStop||IsPause) //�������ֹͣ/��ͣ״̬,�˶��������κδ���ֱ�ӷ��� 
		return; 
	else    //�������Ϊ��ͣ״̬
	{
		IsPause = true;
		PauseTime = time(0); //��ȡ��ͣʱ�� 
	}
}

void MyTimer::Stop()	//ֹͣ
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

void MyTimer::show()			//���
{
	long int t=time(0)-StartTime;
	cout<<t/3600<<":"<<t/60<<":"<<t%60<<endl;
}
