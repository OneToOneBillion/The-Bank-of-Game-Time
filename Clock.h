#ifndef  _COUTDOWN_H_
#define  _COUTDOWN_H_


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
	void set(int h, int m, int s);
	void Start();
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

void Clock::Start()
{
	if (IsStop)
	{
		 
		IsStop = false;
	}
	else if (IsPause)
	{
		IsPause = false;
		 
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


