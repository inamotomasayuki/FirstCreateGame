#include "stdafx.h"
#include "GameClear.h"
#include "Player.h"
#include "GameData.h"
GameClear::GameClear()
{
}
GameClear::~GameClear()
{
	DeleteGO(m_skinModelRender);
}

bool GameClear::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(
		L"modelData/clear.cmo"
	);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);

	m_physicsStaticObject.CreateMesh(m_position, m_rotation, m_scale, m_skinModelRender);

	m_ghostObject.CreateBox(
		m_position,
		CQuaternion::Identity,
		{ 1200.0f,500.0f,200.0f }
	);

	return true;
}
void GameClear::Update()
{
	if (g_gameData.GetStageNo() == 1) {
		m_ghostObject.CreateBox(
			m_position,
			CQuaternion::Identity,
			{ 800.0f,500.0f,180.0f }
		);
	}
}