#pragma once

class TitleBg : public IGameObject
{
public:
	TitleBg();
	~TitleBg();
	bool Start();
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
	prefab::CSky* m_sky = nullptr;
};

