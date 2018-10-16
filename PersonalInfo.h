#ifndef _PersonalInfo_H_
#define _PersonalInfo_H_
#include<vector>
class PersonalInfo {
private:
	long int DailyStudyTime;    //ÿ���Ѿ�ѧϰʱ��
	long int RemainingGameTime;    //����ʣ����Ϸʱ��

	long int TotalStudyTime;    //��һ��ʼʹ�ô�����ܹ�ѧϰ��ʱ��
	long int TotalGameTime;     //��һ��ʼʹ�ô�����ܹ���Ϸ��ʱ��

	long int Vault;    //�洢����Ϸʱ�䣨��Ϸʱ������

	vector<long int> FightingTime;    //����ѧϰʱ��

	long int DailyGameTime;    //���õ�ÿ�����ӵ���Ϸʱ��

public:
	PersonalInfo();
	virtual ~PersonalInfo();

	void InitDGT(int dgt);

	long int GetDST();    //�õ�ÿ���Ѿ�ѧϰʱ��
	long int GetRGT();    //�õ�����ʣ����Ϸʱ��
	long int GetTST();    //�õ���һ��ʼʹ�ô�����ܹ�ѧϰ��ʱ��
	long int GetTGT();    //�õ���һ��ʼʹ�ô�����ܹ���Ϸ��ʱ��
	long int GetVault();    //�õ��Ѵ洢����Ϸʱ��
	long int GetFT();    //�õ�����ѧϰʱ��
	long int GetDGT();    //�õ��趨��ÿ�����ӵ���Ϸʱ��

	void AddDGTtoRGT();

protected:

};

void PersonalInfo::InitDGT(int dgt) {
	DailyGameTime = dgt;
}

int PersonalInfo::GetDST() {
	return DailyStudyTime;
}

int PersonalInfo::GetRGT() {
	return RemainingGameTime;
}

int PersonalInfo::GetTST() {
	return TotalStudyTime;
}

int PersonalInfo::GetTGT() {
	return TotalGameTime;
}

int PersonalInfo::GetVault() {
	return Vault;
}

int PersonalInfo::GetFT() {
	return FightingTime;
}

int PersonalInfo::GetDGT() {
	return DailyGameTime;
}

void PersonalInfo::AddDGTtoRGT() {
	RemainingGameTime += DailyGameTime;
}

#endif // !_PersonalInfo_H_