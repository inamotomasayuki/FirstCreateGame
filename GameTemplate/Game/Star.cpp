#include "stdafx.h"
#include "Star.h"
#include "Player.h"
#include "Game.h"

Star::Star()
{
}


Star::~Star()
{
	DeleteGO(m_skinModelRender);
}

bool Star::Start()
{


	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(
		L"modelData/star.cmo"
	);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);

	return true;
}
void Star::Update()
{
	Rotation();
	GetStar();
}

void Star::Rotation()
{
	//星を回転させる
	float angle = 0.0f;
	angle += 3.0f;
	CQuaternion addRot;
	addRot.SetRotationDeg(CVector3::AxisY, angle);
	m_rotation.Multiply(addRot);

	m_skinModelRender->SetRotation(m_rotation);
}

void Star::GetStar()
{
	m_player = FindGO<Player>("player");
	m_game = FindGO<Game>("Game");
	CVector3 v = m_player->GetPosition() - m_position;
	float len = v.Length();
	if (len < 100) {
		effect = NewGO<prefab::CEffect>(0);
		effect->Play(L"effect/star.efk");
		effect->SetPosition(m_position);
		effect->SetScale({ 10.0f,10.0f,10.0f });
		//サウンド再生
		m_sound = NewGO <prefab::CSoundSource>(0);
		m_sound->Init(L"sound/coinGet.wav");
		m_sound->Play(false);
		//スコアを加算
		m_game->SetScore(10);

		DeleteGO(this);
	}
}