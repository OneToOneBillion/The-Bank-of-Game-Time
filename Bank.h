#ifndef _Bank_H_
#define _Bank_H_
#include"PersonalInfo.h"
#include"Timer.h"
#include"Clock.h"

class Bank
{
public:
	Bank();
	~Bank();
	void InitInfo(PersonalInfo* p);
	bool SavingTime();					//保存时间
	bool BorrowGT(int LengthOfTime);	//Borrow 
	bool ExchangeTime();				//借贷时间
	void StartStudy();					
	void EndStudy();
	void StartGame();
	void EndGame();

private:
	PersonalInfo *info;
	MyTimer t;
	Clock c;
};

Bank::Bank()
{

}
Bank::~Bank()
{

}

void Bank::InitInfo(PersonalInfo* p)
{
	info = p;
}

bool Bank::SavingTime()
{
	info->SetVault(info->GetVault() + info->GetRGT());
	info->SetRGT(0);
	return true;
}

bool Bank::BorrowGT(int LengthOfTime) 
{
	if (LengthOfTime > info->GetVault())
	{
		return false;
	}
	info->SetRGT(LengthOfTime + info->GetRGT());
	return true;
}
 
bool Bank::ExchangeTime()
{
	info->SetRGT(info->GetRGT() + info->GetDST());
	return true;
}

void Bank::StartStudy()
{
	t.Start();
}

void Bank::EndStudy()
{
	t.Stop();									
	long int StudyTime=t.GetClickTime();	
	info->SetOST(StudyTime);			
	info->SetDST(info->GetDST()+StudyTime);		
	ExchangeTime();								
	info->SetTST(info->GetTST() + StudyTime);		
}

void Bank::StartGame()
{
	c.SetDGT(info->GetDGT());
	c.Start(c);
}

void Bank::EndGame()
{
	c.Stop();
	long int GameTime = c.Getcounttime()-1;
	cout << GameTime << endl;
	info->SetRGT(info->GetDGT() - GameTime);
	info->SetTGT(info->GetTGT() + GameTime);
}
#endif // !_Bank_H_