#pragma once

class Player;
class Game;

class Enemy_01 : public IGameObject
{
public:
	Enemy_01();
	~Enemy_01();
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

private:
	CPhysicsStaticObject m_physicsStaticObject;				//静的物理オブジェクト。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//ｽｷﾝﾓﾃﾞﾙﾚﾝﾀﾞｰ
	CVector3 m_position = CVector3::Zero;						//座標
	CVector3 m_movespeed;										//移動速度
	CQuaternion m_rotation = CQuaternion::Identity;				//回転
	CVector3 m_scale = CVector3::One;							//スケール
	prefab::CSoundSource* m_sound = nullptr;

	prefab::CEffect* effect = nullptr;

	int m_timer = 0;		//タイマー
	Player* m_player;		//プレイヤー
	Game* m_game;			//ゲーム

	enum EnState {
		enState_right,		//右
		enState_left,		//左
		enState_Atack
	};
	EnState m_state;

};

