#ifndef  _COUTDOWN_H_
#define  _COUTDOWN_H_


#include <iostream>
#include <windows.h>
#include "PersonalInfo.h"
#include "time.h"

using namespace std;

class Clock 
{
public:
	Clock();
	~Clock();
	bool GetIsPause() 
	{ return IsPause; }
	bool GetIsStop()
	{ return IsStop; }
	int GetStartTime()
	{
		return StartTime;
	}
	int GetPauseTime()
	{
		return PauseTime;
	}
	int GetClockTime()
	{
		return time(0) - StartTime;
	}
	void set(int dgt);
	void Start();
	void Pause();
	void Stop();
	void show();
private:
	bool IsPause;
	bool IsStop;
	long int StartTime;
	long int PauseTime;
	int hour, minute, second;
	PersonalInfo info;
};

Clock::~Clock()
{}

Clock::Clock()
{
	IsPause = false;
	IsStop = true;
}

void Clock::Start()
{
	if (IsStop)
	{
		StartTime = time(0);
		IsStop = false;
	}
	else if (IsPause)
	{
		IsPause = false;
		StartTime += time(0) - PauseTime;
	}
}


void Clock::Pause()  
{
	if (IsStop || IsPause)  
		return;
	else    
	{
		IsPause = true;
		PauseTime = time(0);
	}
}

void Clock::Stop()
{
	if (IsStop)
	{
		return;
	}
	else if (IsPause)
	{
		IsPause = false;
		IsStop = true;
	}
	else if (!IsStop)
	{
		IsStop = true;
	}
}
void Clock::set(int dgt)
{
	dgt = info.GetDGT();
	hour = dgt/3600;
	minute = dgt%60;
	second = dgt%60;
}

void Clock::show()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

#endif


