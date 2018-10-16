#ifndef _Bank_H_
#define _Bank_H_
#include"PersonalInfo.h"
#include"Timer.h"

class Bank
{
public:
	Bank();
	~Bank();
	bool SavingTime();					//����ʱ�䵽��
	bool BorrowGT(int LengthOfTime);	//�������ʱ��
	bool ExchangeTime();				//ת��ʱ�䣬ÿ��ѧϰʱ��ת��Ϊ��Ϸʱ��
	void StartStudy();					//��ʼѧϰ
	void EndStudy();					//����ѧϰ

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
		//��ʾ����ǰ�����
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
	t.Stop();									//ֹͣ��ʱ
	long int StudyTime=t.GetClickTime();		//�õ�����ʱ��
	info.SetFightingTime(StudyTime);			//���ñ���ѧϰʱ��
	info.SetDST(info.GetDST()+StudyTime);		//����ÿ���Ѿ�ѧϰʱ��
	ExchangeTime();								//ʵʱת����Ϸʱ��
	info.SetTST(info.GetTST() + StudyTime);		//������ѧϰʱ��

}
#endif // !_Bank_H_