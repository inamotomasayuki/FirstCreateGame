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
		enAnimationClip_run,	//走りアニメーション。
		enAnimationClip_Num		//アニメーションクリップの数。
	};
	CAnimationClip m_animClips[enAnimationClip_Num];	//アニメーションクリップ。

};

