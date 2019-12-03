#pragma once
class GameCamera;
class TitleUni : public IGameObject
{
public:
	TitleUni();
	~TitleUni();
	bool Start();
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	enum EnAnimationClip {
		enAnimationClip_run,	//����A�j���[�V�����B
		enAnimationClip_Num		//�A�j���[�V�����N���b�v�̐��B
	};
	CAnimationClip m_animClips[enAnimationClip_Num];	//�A�j���[�V�����N���b�v�B

};

