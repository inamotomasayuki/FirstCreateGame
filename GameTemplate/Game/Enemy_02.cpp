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
		20.0,			//���a
		20.0f,			//����
		m_position		//�������W
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
	//��
	if (m_state == enState_left) {
		if (m_timer == 170.0f) {
			m_movespeed.x *= -1.0f;
			m_timer = 0.0f;
			m_state = enState_right;
		}
	}
	//�E
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
	//�n�ʂɂ�����W�����v
	if (m_charaCon.IsOnGround()) {
		m_movespeed.y = 350.0f;
	}
	//�d��
	m_movespeed.y -= 20.0f;
}
void Enemy_02::Attack()
{
	//���������߂�
	CVector3 v = m_player->GetPosition() - m_position;
	float len = v.Length();
	v.Normalize();
	CVector3 up = CVector3::AxisY;
	float naiseki = v.Dot(up);
	float angle = acos(naiseki);
	//�������T�O��菬�����Ƃ�
	//�U��
	if (fabs(angle) > CMath::DegToRad(70) 
		&& len < 70 
		&& m_player->GetJumpFlag() == false){
		m_game->SetPlayerHp(-1);
		CVector3 force = v;
		//Y�����������B
		force.y = 0.0f;
		force.Normalize();
		force *= 2000;
		m_player->SetSpeed(force);
	}
}
void Enemy_02::Death()
{
	//���������߂�
	CVector3 v = m_player->GetPosition() - m_position;
	float len = v.Length();

	//�W�����v����������50
	if (m_player->GetJumpFlag() == true && len < 90) {
		effect = NewGO<prefab::CEffect>(0);
		effect->Play(L"effect/star.efk");
		effect->SetPosition(m_position);
		effect->SetScale({ 10.0f,10.0f,10.0f });
		//�T�E���h�Đ�
		m_sound = NewGO <prefab::CSoundSource>(0);
		m_sound->Init(L"sound/enemyDown.wav");
		m_sound->Play(false);
		m_game->SetScore(30);
		DeleteGO(this);
	}

}