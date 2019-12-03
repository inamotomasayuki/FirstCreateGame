#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"

class BackGround :public IGameObject
{
public:
	BackGround();
	~BackGround();
	bool Start();
	//���W�̐ݒ�B
	void SetPosition(CVector3 v)
	{
		m_position = v;
	}
	//��]�̐ݒ�B
	void SetRotation(CQuaternion q)
	{
		m_rotation = q;
	}
	void SetScale(CVector3 s)
	{
		m_scale = s;
	}
private:
	CPhysicsStaticObject m_physicsStaticObject;				//�ÓI�����I�u�W�F�N�g�B
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	prefab::CSky* m_sky = nullptr;
	CVector3 m_position = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
};

