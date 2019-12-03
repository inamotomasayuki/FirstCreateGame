#include "stdafx.h"
#include "Floor.h"
#include "Player.h"


Floor::Floor()
{
}


Floor::~Floor()
{
	DeleteGO(m_skinModelRender);
}

bool Floor::Start()
{
	m_player = FindGO<Player>("player");
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(
		L"modelData/ugokuyuka.cmo"
	);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);

	m_state = enState_left;
	m_physicsStaticObject.CreateMesh(m_position, m_rotation, m_scale, m_skinModelRender);

	PhysicsWorld().SetDebugDrawMode(btIDebugDraw::DBG_DrawWireframe);
	m_ghostObject.CreateBox(
		m_position,
		CQuaternion::Identity,
		{ 400.0f,20.0f,600.0f }
	);

	return true;
}

void Floor::Update()
{
	m_timer++;
	//¶
	if (m_state == enState_left) {
		if (m_timer == 120) {
			m_movespeed.x = 5.0f;
			m_timer = 0.0f;
			m_state = enState_right;
		}
		else if (m_timer == 90.0f) {
			m_movespeed.x = 0;
		}
	}
	//‰E
	if (m_state == enState_right) {
		if (m_timer == 120) {
			m_movespeed.x = -5.0f;
			m_timer = 0.0f;
			m_state = enState_left;
		}
		else if (m_timer == 90.0f) {
			m_movespeed.x = 0;
		}
	}
	m_position += m_movespeed;
	m_ghostObject.SetPosition(m_position);
	m_physicsStaticObject.SetPositionAndRotation(m_position, CQuaternion::Identity);
	m_player->SetMove(m_movespeed * 60.0f);
	m_skinModelRender->SetPosition(m_position);
}