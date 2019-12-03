#include "stdafx.h"
#include "TitleUni.h"
#include "GameCamera.h"
TitleUni::TitleUni()
{
}
TitleUni::~TitleUni()
{
	DeleteGO(m_skinModelRender);
}
bool TitleUni::Start()
{
	m_animClips[enAnimationClip_run].Load(L"animData/unityChan/run.tka");
	m_animClips[enAnimationClip_run].SetLoopFlag(true);
	EnFbxUpAxis Up = enFbxUpAxisY;		//FBXの上方向

	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	//スキンモデルレンダラー初期化
	m_skinModelRender->Init(
		L"modelData/unityChan.cmo",
		m_animClips,
		enAnimationClip_Num,
		Up
	);

	m_rotation.SetRotationDeg(CVector3::AxisY, 90);
	m_position = { -100.0f,-35.0f,0.0f };
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->PlayAnimation(enAnimationClip_run, 0.2f);
	return true;
}