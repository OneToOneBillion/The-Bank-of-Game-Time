#ifndef _PersonalInfo_H_
#define _PersonalInfo_H_

class PersonalInfo {
private:
	int DailyStudyTime;    //每天已经学习时间
	int RemainingGameTime;    //今天剩余游戏时间

	int TotalStudyTime;    //从一开始使用此软件总共学习的时间
	int TotalGameTime;    //从一开始使用此软件总共游戏的时间

	int Vault;    //存储的游戏时间（游戏时间余额宝）

	int FightingTime;    //本次学习时间

	int DailyGameTime;    //设置的每天增加的游戏时间

public:
	PersonalInfo();
	virtual ~PersonalInfo();

	void InitDGT(int dgt);

	int GetDST();    //得到每天已经学习时间
	int GetRGT();    //得到今天剩余游戏时间
	int GetTST();    //得到从一开始使用此软件总共学习的时间
	int GetTGT();    //得到从一开始使用此软件总共游戏的时间
	int GetVault();    //得到已存储的游戏时间
	int GetFT();    //得到本次学习时间
	int GetDGT();    //得到设定的每天增加的游戏时间

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