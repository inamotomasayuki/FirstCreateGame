#pragma once
class TitleStar : public IGameObject
{
public:
	TitleStar();
	~TitleStar();
	bool Start();
	void Update();
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//ｽｷﾝﾓﾃﾞﾙﾚﾝﾀﾞｰ
	CVector3 m_position = CVector3::Zero;						//座標
	CQuaternion m_rotation = CQuaternion::Identity;				//回転
	CVector3 m_scale = CVector3::One;							//スケール
	void Rotation();
};

