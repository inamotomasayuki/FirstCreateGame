#pragma once
class GameData
{
public:
	GameData();
	~GameData();
	/// <summary>
	/// ���݂̃X�e�[�W�ԍ����擾�B
	/// </summary>
	/// <returns></returns>
	int GetStageNo()
	{
		return stageNo;
	}
	/// <summary>
	/// �X�e�[�W�ԍ������̃X�e�[�W�ɐi�߂�B
	/// </summary>
	/// <returns>false���Ԃ��Ă�����A���̃X�e�[�W�͂Ȃ��B</returns>
	bool ProgressNextStageNo()
	{
		stageNo++;
		if (stageNo == 2) {
			stageNo = 0;
			return false;
		}
		return true;
	}
private:
	int stageNo = 0;	//���݂̃X�e�[�W�̔ԍ��B
};
extern GameData g_gameData;
