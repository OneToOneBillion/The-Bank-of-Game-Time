#ifndef _Bank_H_
#define _Bank_H_
#include"PersonalInfo.h"


class Bank
{
	bool SavingTime();
	bool BorrowGT(int LengthOfTime);
	bool ExchangeTime();


private:
	PersonalInfo * info;
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
		//提示您当前的余额
		return false;
	}
	info.SetRGT(LengthOfTime + info.GetGRT());
}
 
bool Bank::ExchangeTime()
{
	info.SetRGT(info.GetRGT() + info.GetDST());

	return true;

}

#endif // !_Bank_H_