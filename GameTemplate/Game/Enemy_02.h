#pragma once
#include "tkEngine/character/tkCharacterController.h"

class Player;
class Game;

class Enemy_02 : public IGameObject
{
public:
	Enemy_02();
	~Enemy_02();
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
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//ｽｷﾝﾓﾃﾞﾙﾚﾝﾀﾞｰ
	CVector3 m_position = CVector3::Zero;						//座標
	CVector3 m_movespeed;										//移動速度
	CQuaternion m_rotation = CQuaternion::Identity;				//回転
	CVector3 m_scale = CVector3::One;							//スケール
	CCharacterController m_charaCon;							//ｷｬﾗｸﾀｰｺﾝﾄﾛｰﾗｰ
	prefab::CSoundSource* m_sound = nullptr;
	prefab::CEffect* effect = nullptr;

	int m_timer = 0;		//タイマー
	
	Player* m_player;		//プレイヤー
	Game* m_game;			//ゲーム

	enum EnState {
		enState_right,		//右
		enState_left,		//左
		enState_Atack		//攻撃
	};
	EnState m_state;
	void Move();
	void Jump();
	void Attack();
	void Death();
};

