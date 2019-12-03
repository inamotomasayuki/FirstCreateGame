#include "stdafx.h"
#include "Title.h"

Title::Title()
{
}


Title::~Title()
{
	DeleteGO(m_spriteRender);
}

bool Title::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(L"sprite/nextStage.dds", 1280, 760);
	return true;
}
