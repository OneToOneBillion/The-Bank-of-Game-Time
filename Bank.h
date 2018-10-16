#ifndef _Bank_H_
#define _Bank_H_
#include"PersonalInfo.h"
#include"Timer.h"

class Bank
{
public:
	Bank();
	~Bank();
	bool SavingTime();					//保存时间到余额宝
	bool BorrowGT(int LengthOfTime);	//从余额宝借贷时间
	bool ExchangeTime();				//转换时间，每天学习时间转换为游戏时间
	void StartStudy();					//开始学习
	void EndStudy();					//结束学习

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

void Bank::StartStudy()
{
	t.Start();
}

void EndStudy()
{
	t.Stop();									//停止计时
	long int StudyTime=t.GetClickTime();		//得到持续时间
	info.SetFightingTime(StudyTime);			//设置本次学习时间
	info.SetDST(info.GetDST()+StudyTime);		//设置每天已经学习时间
	ExchangeTime();								//实时转化游戏时间
	info.SetTST(info.GetTST() + StudyTime);		//设置总学习时间

}
#endif // !_Bank_H_