#ifndef  _CLOCK_H_
#define  _CLOCK_H_


#include <iostream>
#include <windows.h>
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
	void SetDGT(int dgt) {
		set(dgt / 3600, dgt / 60,dgt % 60);
	}
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
	long int Getcounttime()
	{
		return counttime;
	};
	void Setcounttime(long int counttime1)
	{
		counttime = counttime1;
	}
	void set(int h, int m, int s);
	void Start(Clock m);

	void Pause();
	void Stop();
	void show();
private:
	bool IsPause;
	bool IsStop;
	long int StartTime;
	long int PauseTime;
	int hour, minute, second;
	long int counttime;
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
		 clock.SetIsStop(false);
	}
	 if (clock.GetIsPause())
	{
		 clock.SetIsPause(false);
	}
	while (!clock.GetIsStop())
	{
		if (!clock.GetIsPause())
		{
			//可以添加暂停操作...

			clock.show();
			Sleep(1000);
			system("cls");
			long int counttime1=clock.Getcounttime()+1;
			clock.Setcounttime(counttime1);
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
						cout << clock.Getcounttime()-1 << endl;
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

void Clock::show()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

void Clock::set(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}
#endif
