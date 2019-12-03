#pragma once
//ｷｬﾗｸﾀｰｺﾝﾄﾛｰﾗｰを使うときのヘッダーファイル
#include "tkEngine/character/tkCharacterController.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
class Game;
class GameCamera;
class Font;
class Floor;
class GameClear;
class ClearFont;
class JumpFloor;
class Player : public IGameObject
{
public:
	Player();
	~Player();

	bool Start();
	void Update();

	//座標の取得。
	CVector3 GetPosition()
	{
		return m_position;
	}
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
	//スケールの設定。
	void SetScale(CVector3 s)
	{
		m_scale = s;
	}
	//ジャンプフラグの取得
	bool GetJumpFlag()
	{
		return m_charaCon.IsJump();
	}
	bool GetClearFlag()
	{
		return m_clearFlag;
	}
	void SetSpeed(CVector3 v)
	{
		m_force = v;
	}
	void SetState(int i)
	{
		m_statenum = i;
	}
	void SetMove(CVector3 v)
	{
		m_move = v;
	}
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//ｽｷﾝﾓﾃﾞﾙﾚﾝﾀﾞｰ
	CVector3 m_position = CVector3::Zero;						//座標
	CVector3 m_force = CVector3::Zero;							//外部から加わった力。
	CVector3 m_move = CVector3::Zero;
	CVector3 m_movespeed;										//移動速度
	CVector3 m_gravity;
	CQuaternion m_rotation = CQuaternion::Identity;				//回転
	CCharacterController m_charaCon;							//ｷｬﾗｸﾀｰｺﾝﾄﾛｰﾗｰ
	CVector3 m_scale = CVector3::One;							//スケール

	Game* m_game;				//ゲーム
	GameCamera* m_camera;		//ゲームカメラ
	Floor* m_floor = nullptr;
	GameClear* m_gameClear = nullptr;
	JumpFloor* m_jumpFloor = nullptr;
	ClearFont* m_clearFont = nullptr;
	bool m_clearFlag = false;
	enum EnAnimationClip {
		enAnimationClip_idle,	//待機アニメーション。
		enAnimationClip_run,	//走りアニメーション。
		enAnimationClip_walk,	//歩きアニメーション。
		enAnimationClip_jump,	//ジャンプアニメーション。
		enAnimationClip_damage,
		enAnimationClip_clear,
		enAnimationClip_Num		//アニメーションクリップの数。
	};
	CAnimationClip m_animClips[enAnimationClip_Num];	//アニメーションクリップ。
	enum EnState {
		enState_play,
		enState_gameOver,
		enState_gameClear
	};
	EnState m_state;
	int m_statenum = 0;
	prefab::CSoundSource* m_sound = nullptr;
	void StickMove();
	void Rotation();
};

