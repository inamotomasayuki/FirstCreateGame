#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
class Player;

class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();
	bool Start();
	void Update();
	//座標の設定
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
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//ｽｷﾝﾓﾃﾞﾙﾚﾝﾀﾞｰ
	CVector3 m_position = CVector3::Zero;						//座標
	CVector3 m_movespeed;										//移動速度
	CQuaternion m_rotation = CQuaternion::Identity;				//回転
	CVector3 m_scale;											//スケール

	Player* m_player;		//プレイヤー
};

