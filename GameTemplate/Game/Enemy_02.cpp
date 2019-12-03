#include "stdafx.h"
#include "Enemy_02.h"
#include "Player.h"
#include "Game.h"


Enemy_02::Enemy_02()
{
}


Enemy_02::~Enemy_02()
{
	DeleteGO(m_skinModelRender);
}

bool Enemy_02::Start()
{
	m_player = FindGO<Player>("player");
	m_game = FindGO<Game>("Game");

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(
		L"modelData/enemy00.cmo"
	);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
	m_charaCon.Init(
		20.0,			//半径
		20.0f,			//高さ
		m_position		//初期座標
	);
	m_movespeed.x = 130.0f;
	m_state = enState_left;
	return true;
}

void Enemy_02::Update()
{
	Move();
	Jump();

	m_position = m_charaCon.Execute(
		m_movespeed, 
		GameTime().GetFrameDeltaTime()
	);
	m_skinModelRender->SetPosition(m_position);
	Attack();
	Death();
}
void Enemy_02::Move()
{
	m_timer++;
	//左
	if (m_state == enState_left) {
		if (m_timer == 170.0f) {
			m_movespeed.x *= -1.0f;
			m_timer = 0.0f;
			m_state = enState_right;
		}
	}
	//右
	if (m_state == enState_right) {
		if (m_timer == 170.0f) {
			m_movespeed.x *= -1.0f;
			m_timer = 0.0f;
			m_state = enState_left;
		}
	}
}
void Enemy_02::Jump()
{
	//地面にいたらジャンプ
	if (m_charaCon.IsOnGround()) {
		m_movespeed.y = 350.0f;
	}
	//重力
	m_movespeed.y -= 20.0f;
}
void Enemy_02::Attack()
{
	//距離を求める
	CVector3 v = m_player->GetPosition() - m_position;
	float len = v.Length();
	v.Normalize();
	CVector3 up = CVector3::AxisY;
	float naiseki = v.Dot(up);
	float angle = acos(naiseki);
	//距離が５０より小さいとき
	//攻撃
	if (fabs(angle) > CMath::DegToRad(70) 
		&& len < 70 
		&& m_player->GetJumpFlag() == false){
		m_game->SetPlayerHp(-1);
		CVector3 force = v;
		//Y成分を除去。
		force.y = 0.0f;
		force.Normalize();
		force *= 2000;
		m_player->SetSpeed(force);
	}
}
void Enemy_02::Death()
{
	//距離を求める
	CVector3 v = m_player->GetPosition() - m_position;
	float len = v.Length();

	//ジャンプ中かつ距離が50
	if (m_player->GetJumpFlag() == true && len < 90) {
		effect = NewGO<prefab::CEffect>(0);
		effect->Play(L"effect/star.efk");
		effect->SetPosition(m_position);
		effect->SetScale({ 10.0f,10.0f,10.0f });
		//サウンド再生
		m_sound = NewGO <prefab::CSoundSource>(0);
		m_sound->Init(L"sound/enemyDown.wav");
		m_sound->Play(false);
		m_game->SetScore(30);
		DeleteGO(this);
	}

}