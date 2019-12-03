#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"

class BackGround :public IGameObject
{
public:
	BackGround();
	~BackGround();
	bool Start();
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
private:
	CPhysicsStaticObject m_physicsStaticObject;				//静的物理オブジェクト。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	prefab::CSky* m_sky = nullptr;
	CVector3 m_position = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
};

