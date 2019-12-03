#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"

class JumpFloor :public IGameObject
{
public:
	JumpFloor();
	~JumpFloor();
	bool Start();
	void Update();
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
	CPhysicsGhostObject* GetGhost()
	{
		return &m_ghostObject;
	}
private:
	CPhysicsStaticObject m_physicsStaticObject;				//�ÓI�����I�u�W�F�N�g�B
	CPhysicsGhostObject m_ghostObject;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
};