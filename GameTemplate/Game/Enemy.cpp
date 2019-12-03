#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
	DeleteGO(m_skinModelRender);
}

bool Enemy::Start()
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

	m_physicsStaticObject.CreateMesh(m_position, m_rotation, m_scale, m_skinModelRender);
	m_startPos = m_position;
	return true;
}
void Enemy::Update()
{
	CVector3 v = m_player->GetPosition() - m_position;
	float len = v.Length();
	v.Normalize();
	CVector3 up = { 0.0f,1.0f,0.0f };
	float naiseki = v.Dot(up);
	float angle = acos(naiseki);
	//ãóó£Ç™ÇTÇOÇÊÇËè¨Ç≥Ç¢Ç∆Ç´
	//çUåÇ
	if (fabs(angle) > CMath::DegToRad(70) 
		&& len < 70 
		&& m_player->GetJumpFlag() == false) {
		m_game->SetPlayerHp(-1);
		CVector3 force = v;
		//Yê¨ï™ÇèúãéÅB
		force.y = 0.0f;
		force.Normalize();
		force *= 2000;
		m_player->SetSpeed(force);
	}
	//ãóó£Ç™50ÇÊÇËëÂÇ´Ç¢500ÇÊÇËè¨Ç≥Ç¢Ç∆Ç´
	//í«ê’
	if (len > 50 && len < 400) {
		m_position += v * 3;
		m_position.y = 0.0f;
	}
	if (len > 400) {
		auto m_posV = m_startPos - m_position;
		m_posV.Normalize();
		m_position += m_posV * 5.0f;
	}
	m_skinModelRender->SetPosition(m_position);
	m_physicsStaticObject.SetPositionAndRotation(m_position, CQuaternion::Identity);

	//ÉWÉÉÉìÉvíÜÇ©Ç¬ãóó£Ç™ÇTÇOÇÊÇËè¨Ç≥Ç¢
	if (m_player->GetJumpFlag() == true && len < 90) {
		effect = NewGO<prefab::CEffect>(0);
		effect->Play(L"effect/star.efk");
		effect->SetPosition(m_position);
		effect->SetScale({ 10.0f,10.0f,10.0f });
		//ÉTÉEÉìÉhçƒê∂
		m_sound = NewGO <prefab::CSoundSource>(0);
		m_sound->Init(L"sound/enemyDown.wav");
		m_sound->Play(false);
		m_game->SetScore(20);
		DeleteGO(this);
	}
}