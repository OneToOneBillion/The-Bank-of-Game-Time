#include"Timer.h"
#include<windows.h>

using namespace std;

int main()
{
	Timer t;
	int n=0;
	cin>>n;
	if(n==1)
	{
		t.Start();
	}
	while(1)
	{
		if(time(0)-t.GetStartTime()==5)
		{
			t.Pause();
		}
		if(time(0)-t.GetStartTime()==9)
		{
			t.Start();
		}
		if(time(0)-t.GetStartTime()==15)
		{
			t.Stop();
			break;
		}
		if(!t.GetIsPause() && !t.GetIsStope())
		{
			Sleep(1000);
			t.show();
			continue;
		}
		Sleep(1000);
	}
	return 0;
}
