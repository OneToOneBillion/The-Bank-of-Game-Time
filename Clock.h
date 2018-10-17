#ifndef  _CLOCK_H_
#define  _CLOCK_H_


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
<<<<<<< HEAD
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
=======
	void SetIsPause(bool m)
	{IsPause = m;}
	void SetIsStop(bool m)
	{IsStop = m;}
	int Gethour()
	{return hour;}
	int Getminute()
	{	return minute;}
	int Getsecond()
	{return second;}
	void set(int h, int m, int s);
	void Start(Clock m);
>>>>>>> 9470b85c13a722ffe3ebcd417828149bbbc5bea1
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

void Clock::Start(Clock clock)
{
	if (clock.GetIsStop())
	{
<<<<<<< HEAD
		StartTime = time(0);
		IsStop = false;
=======
		 clock.SetIsStop(false);
>>>>>>> 9470b85c13a722ffe3ebcd417828149bbbc5bea1
	}
	 if (clock.GetIsPause())
	{
<<<<<<< HEAD
		IsPause = false;
		StartTime += time(0) - PauseTime;
=======
		 clock.SetIsPause(false);
>>>>>>> 9470b85c13a722ffe3ebcd417828149bbbc5bea1
	}
	while (!clock.GetIsStop())
	{
		if (!clock.GetIsPause())
		{
			//可以添加暂停操作...

			clock.show();
			Sleep(1000);
			system("cls");
			int s1 = clock.Getsecond() - 1;
			clock.set(clock.Gethour(),clock.Getminute(),s1);
			if (s1 == -1)
			{
				s1 = 59;
				int m1=clock.Getminute()-1;
				clock.set(clock.Gethour(), m1, s1);
				if (m1== -1)
				{
					m1 = 59;
					int h1=clock.Gethour()-1;
					clock.set(h1, m1, s1);
					if (h1== -1) //计时结束
					{
						clock.Stop();
						cout << "time up!" << endl;
						break;
					}
				}
			}
		}
		else
		{
			//解除暂停操作
		}
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
