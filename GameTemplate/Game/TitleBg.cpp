#include "stdafx.h"
#include "TitleBg.h"
TitleBg::TitleBg()
{
}
TitleBg::~TitleBg()
{
	DeleteGO(m_sky);
	DeleteGO(m_skinModelRender);
}
bool TitleBg::Start()
{
	//m_sky = NewGO<prefab::CSky>(0);
	//m_sky->SetSkyCubeMapFilePath(L"sprite/sky.dds");
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/ground.cmo");

	m_position.y = -100;
	m_scale = { 3.0f,3.0f,3.0f };
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);
	return true;
}