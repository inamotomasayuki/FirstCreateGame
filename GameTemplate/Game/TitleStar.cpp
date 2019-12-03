#include "stdafx.h"
#include "TitleStar.h"
TitleStar::TitleStar()
{
}


TitleStar::~TitleStar()
{
	DeleteGO(m_skinModelRender);
}

bool TitleStar::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(
		L"modelData/star.cmo"
	);
	m_position.x = 100.0f;
	m_position.y = 50.0f;
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_scale = { 10.0f,10.0f,10.0f };
	m_skinModelRender->SetScale(m_scale);

	return true;
}
void TitleStar::Update()
{
	Rotation();
}

void TitleStar::Rotation()
{
	//¯‚ð‰ñ“]‚³‚¹‚é
	float angle = 0.0f;
	angle += 3.0f;
	CQuaternion addRot;
	addRot.SetRotationDeg(CVector3::AxisY, angle);
	m_rotation.Multiply(addRot);

	m_skinModelRender->SetRotation(m_rotation);
}
