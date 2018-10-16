#ifndef _Bank_H_
#define _Bank_H_
#include"PersonalInfo.h"
#include"Timer.h"

class Bank
{
public:
	Bank();
	~Bank();
	bool SavingTime();					//±£´æÊ±¼äµ½Óà¶î±¦
	bool BorrowGT(int LengthOfTime);	//´ÓÓà¶î±¦½è´ûÊ±¼ä
	bool ExchangeTime();				//×ª»»Ê±¼ä£¬Ã¿ÌìÑ§Ï°Ê±¼ä×ª»»ÎªÓÎÏ·Ê±¼ä
	void StartStudy();					//¿ªÊ¼Ñ§Ï°
	void EndStudy();					//½áÊøÑ§Ï°

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
	t.Stop();									//Í£Ö¹¼ÆÊ±
	long int StudyTime=t.GetClickTime();		//µÃµ½³ÖÐøÊ±¼ä
	info.SetFightingTime(StudyTime);			//ÉèÖÃ±¾´ÎÑ§Ï°Ê±¼ä
	info.SetDST(info.GetDST()+StudyTime);		//ÉèÖÃÃ¿ÌìÒÑ¾­Ñ§Ï°Ê±¼ä
	ExchangeTime();								//ÊµÊ±×ª»¯ÓÎÏ·Ê±¼ä
	info.SetTST(info.GetTST() + StudyTime);		//ÉèÖÃ×ÜÑ§Ï°Ê±¼ä

}
#endif // !_Bank_H_