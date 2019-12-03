#include "stdafx.h"
#include "JumpFloor.h"
#include "GameData.h"
JumpFloor::JumpFloor()
{
}
JumpFloor::~JumpFloor()
{
	DeleteGO(m_skinModelRender);
}
bool JumpFloor::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/jumpFloor.cmo");
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
	m_physicsStaticObject.CreateMesh(m_position, m_rotation, m_scale, m_skinModelRender);


	m_ghostObject.CreateBox(
		m_position,
		CQuaternion::Identity,
		{ 400.0f,20.0f,600.0f }
	);
	return true;
}
void JumpFloor::Update()
{
	if (g_gameData.GetStageNo() == 1)
	{
		m_ghostObject.CreateBox(
			m_position,
			CQuaternion::Identity,
			{ 600.0f,20.0f,250.0f }
		);
	}
}