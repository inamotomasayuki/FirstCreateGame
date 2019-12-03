#pragma once
class TitleStar : public IGameObject
{
public:
	TitleStar();
	~TitleStar();
	bool Start();
	void Update();
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//����������ް
	CVector3 m_position = CVector3::Zero;						//���W
	CQuaternion m_rotation = CQuaternion::Identity;				//��]
	CVector3 m_scale = CVector3::One;							//�X�P�[��
	void Rotation();
};

