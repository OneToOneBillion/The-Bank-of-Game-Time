#ifndef _Bank_H_
#define _Bank_H_
#include"PersonalInfo.h"
#include"Timer.h"

class Bank
{
public:
	Bank();
	~Bank();
	bool SavingTime();					//保存时间
	bool BorrowGT(int LengthOfTime);	//Borrow 
	bool ExchangeTime();				
	void StartStudy();					
	void EndStudy();					

private:
	PersonalInfo info;
	Timer t;
};

bool Bank::SavingTime()
{
	info.SetVault(info.GetVault() + info.GetRGT());
	info.SetRGT(0);
	return true;
}

bool Bank::BorrowGT(int LengthOfTime) 
{
	if (LengthOfTime > info.GetVault())
	{
		return false;
	}
	info.SetRGT(LengthOfTime + info.GetGRT());
}
 
bool Bank::ExchangeTime()
{
	info.SetRGT(info.GetRGT() + info.GetDST());
	return true;
}

void Bank::StartStudy()
{
	t.Start();
}

void EndStudy()
{
	t.Stop();									
	long int StudyTime=t.GetClickTime();		
	info.SetFightingTime(StudyTime);			
	info.SetDST(info.GetDST()+StudyTime);		
	ExchangeTime();								
	info.SetTST(info.GetTST() + StudyTime);		

}
#endif // !_Bank_H_