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
	long int GetClickTime(){return time(0)-StartTime;}				//得到时间差
	void Start();
	void Pause();
	void Stop();	
	void show();	
private:
	//保存开始和暂停时刻的时间
	long int StartTime;							//开始时间
	long int PauseTime;							//暂停时间
	bool IsPause;								//是否暂停
	bool IsStop;								//是否停止
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
	if(IsStop)				//如果处于停止状态，重置开始时间，把IsStop置false
	{
		StartTime=time(0);
		IsStop=false;
	}
	else if(IsPause)			//如果处于暂停状态，更新StartTime
	{
		IsPause=false;
		StartTime+=time(0)-PauseTime;
	}
}


void MyTimer::Pause() //暂停 
{
	if(IsStop||IsPause) //如果处于停止/暂停状态,此动作不做任何处理，直接返回 
		return; 
	else    //否则调制为暂停状态
	{
		IsPause = true;
		PauseTime = time(0); //获取暂停时间 
	}
}

void MyTimer::Stop()	//停止
{
	if(IsStop)			//如果不是停止状态
	{
		return;
	}
	else if(IsPause)		//如果已经是停止状态
	{
		IsPause=false;
		IsStop=true;
	}
	else if(!IsStop)		//如果已经停止了
	{
		IsStop=true;
	}
}

void MyTimer::show()			//输出
{
	long int t=time(0)-StartTime;
	cout<<t/3600<<":"<<t/60<<":"<<t%60<<endl;
}
