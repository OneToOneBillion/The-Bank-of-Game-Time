#ifndef  _CLOCK_H_
#define  _CLOCK_H_


#include <iostream>
#include <windows.h>

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
	void Pause();
	void Stop();
	void show();
private:
	bool IsPause;
	bool IsStop;
	int hour, minute, second;
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
void Clock::set(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

void Clock::show()
{
	cout << hour << ":" << minute << ":" << second << endl;
}

#endif
