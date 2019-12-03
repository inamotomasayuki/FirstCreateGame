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
	//座標の設定。
	void SetPosition(CVector3 v)
	{
		m_position = v;
	}
	//回転の設定。
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
	CPhysicsStaticObject m_physicsStaticObject;				//静的物理オブジェクト。
	CPhysicsGhostObject m_ghostObject;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
};