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

#endif // !_PersonalInfo_H_

