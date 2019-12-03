#pragma once

class Player;
class Game;

class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
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
	//スケールの設定
	void SetScale(CVector3 s)
	{
		m_scale = s;
	}
	
private:
	CPhysicsStaticObject m_physicsStaticObject;				//静的物理オブジェクト。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//ｽｷﾝﾓﾃﾞﾙﾚﾝﾀﾞｰ
	CVector3 m_position;										//座標
	CVector3 m_movespeed;										//移動速度
	CQuaternion m_rotation = CQuaternion::Identity;				//回転
	CVector3 m_scale = CVector3::One;
	CVector3 m_startPos;
	prefab::CEffect* effect = nullptr;
	prefab::CSoundSource* m_sound = nullptr;

	int m_timer = 0;		//タイマー
	Player* m_player;		//プレイヤー
	Game* m_game;			//ゲーム
	enum EnState {
		enState_left,		//左
		enState_right,		//右
		enState_search,		//追跡
		enState_Atack
	};
	EnState m_state;
};

