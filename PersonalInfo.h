#ifndef _PersonalInfo_H_
#define _PersonalInfo_H_

class PersonalInfo {
private:
	int DailyStudyTime;    //ÿ���Ѿ�ѧϰʱ��
	int RemainingGameTime;    //����ʣ����Ϸʱ��

	int TotalStudyTime;    //��һ��ʼʹ�ô�����ܹ�ѧϰ��ʱ��
	int TotalGameTime;    //��һ��ʼʹ�ô�����ܹ���Ϸ��ʱ��

	int Vault;    //�洢����Ϸʱ�䣨��Ϸʱ������

	int FightingTime;    //����ѧϰʱ��

	int DailyGameTime;    //���õ�ÿ�����ӵ���Ϸʱ��

public:
	PersonalInfo();
	virtual ~PersonalInfo();

	void InitDGT(int dgt);

	int GetDST();    //�õ�ÿ���Ѿ�ѧϰʱ��
	int GetRGT();    //�õ�����ʣ����Ϸʱ��
	int GetTST();    //�õ���һ��ʼʹ�ô�����ܹ�ѧϰ��ʱ��
	int GetTGT();    //�õ���һ��ʼʹ�ô�����ܹ���Ϸ��ʱ��
	int GetVault();    //�õ��Ѵ洢����Ϸʱ��
	int GetFT();    //�õ�����ѧϰʱ��
	int GetDGT();    //�õ��趨��ÿ�����ӵ���Ϸʱ��

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