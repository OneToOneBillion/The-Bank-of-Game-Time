#ifndef _PersonalInfo_H_
#define _PersonalInfo_H_

#include <vector>

class PersonalInfo {
public:
	PersonalInfo() {    //��ʼ������PersonalInfo�ı���
		DailyStudyTime = 0;
		RemainingGameTime = 0;
		TotalStudyTime = 0;
		TotalGameTime = 0;
		Vault = 0;
		DailyGameTime = 0;
		DailyStudyTime = 0;
		OnceStudyTime = 0;
		OnceGameTime = 0;
	}
	virtual ~PersonalInfo();

	//��ʼ�������õ��ĳ�Ա����
	void InitDGT(long int dgt);

	long int GetDST();
	long int GetRGT();
	long int GetTST();
	long int GetTGT();
	long int GetVault();
	long int GetOST();
	long int GetOGT();
	long int GetDGT();
	//�ı����
	void SetRGT(long int time);
	void SetDST(long int time);
	void SetTST(long int time);
	void SetTGT(long int time);
	void SetDGT(long int time);
	void SetDST(long int time);
	void SetOST(long int time);
	void SetOGT(long int time);
	void SetVault(long int vault);

	void ClearRGT();    //��RemainingGameTime����

	void PushInListOfDST(long int time) {
		ListOfDST.push_back(time);
	}

	void PushInListOfDGT(long int time) {
		ListOfDGT.push_back(time);
	}

	void PushInListOfOST(long int time) {
		ListOfOST.push_back(time);
	}

	void PushInListOfOGT(long int time) {
		ListOfOGT.push_back(time);
	}

	void ShowListOfDST() {
		for (auto i = ListOfDST; i > 0; i--) {
			cout << ListOfDST[i - 1];
		}
	}

	void ShowListOfDGT() {
		for (auto i = ListOfDGT; i > 0; i--) {
			cout << ListOfDGT[i - 1];
		}
	}

	void ShowListOfOST() {
		for (auto i = ListOfOST; i > 0; i--) {
			cout << ListOfOST[i - 1];
		}
	}

	void ShowListOfOGT() {
		for (auto i = ListOfOGT; i > 0; i--) {
			cout << ListOfOGT[i - 1];
		}
	}

private:
	long int DailyStudyTime;    //ÿ���Ѿ�ѧϰʱ��
	long int RemainingGameTime;    //����ʣ����Ϸʱ��
	long int TotalStudyTime;    //��һ��ʼʹ�ô�����ܹ�ѧϰ��ʱ��
	long int TotalGameTime;    //��һ��ʼʹ�ô�����ܹ���Ϸ��ʱ��
	long int Vault;    //�洢����Ϸʱ�䣨��Ϸʱ������
	long int DailyGameTime;    //���õ�ÿ�����ӵ���Ϸʱ��
	long int OnceStudyTime;    //����ѧϰʱ��
	long int OnceGameTime;    //������Ϸʱ��
	vector<long int> ListOfDST;    //�洢DailyStudyTime������
	vector<long int> ListOfDGT;    //�洢DailyGameTime������
	vector<long int> ListOfOST;    //�洢OnceStudyTime������
	vector<long int> ListOfOGT;    //�洢OnceGameTime������
};

void PersonalInfo::InitDGT(long int dgt) {
	DailyGameTime = dgt;
}

long int PersonalInfo::GetDST() {
	return DailyStudyTime;
}
long int PersonalInfo::GetRGT() {
	return RemainingGameTime;
}
long int PersonalInfo::GetTST() {
	return TotalStudyTime;
}
long int PersonalInfo::GetTGT() {
	return TotalGameTime;
}
long int PersonalInfo::GetVault() {
	return Vault;
}
long int PersonalInfo::GetOST() {
	return OnceStudyTime;
}
long int PersonalInfo::GetOGT() {
	return OnceGameTime;
}
long int PersonalInfo::GetDGT() {
	return DailyGameTime;
}

void PersonalInfo::SetRGT(long int time) {
	RemainingGameTime = time;
}
void PersonalInfo::SetDST(long int time) {
	DailyStudyTime = time;
}
void PersonalInfo::SetDGT(long int time) {
	DailyGameTime = time;
}
void PersonalInfo::SetTST(long int time) {
	TotalStudyTime = time;
}
void PersonalInfo::SetTGT(long int time) {
	TotalGameTime = time;
}
void PersonalInfo::SetOGT(long int time) {
	OnceGameTime = time;
}
void PersonalInfo::SetOST(long int time) {
	OnceStudyTime = time;
}
void PersonalInfo::SetVault(long int vault) {
	Vault = vault;
}

void PersonalInfo::ClearRGT() {
	RemainingGameTime = 0;
}
#endif // !_PersonalInfo_H_