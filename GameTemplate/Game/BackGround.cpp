#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_sky);
}

bool BackGround::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/BackGround.cmo");
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
	m_physicsStaticObject.CreateMesh(m_position, m_rotation, m_scale, m_skinModelRender);
	m_sky = NewGO<prefab::CSky>(0);
	return true;
}