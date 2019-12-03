#include "stdafx.h"
#include "Title01.h"
#include "TitleBg.h"
#include "TitleUni.h"
#include "Game.h"
#include "TitleStar.h"
#include "TitleCamera.h"
#include "TitleFont.h"

Title01::Title01()
{
}
Title01::~Title01()
{
	m_titleBg = FindGO<TitleBg>("tbg");
	m_titleStar = FindGO<TitleStar>("tstar");
	m_titleCamera = FindGO<TitleCamera>("tcamera");
	DeleteGO(m_titleStar);
	DeleteGO(m_titleCamera);
	DeleteGO(m_titleBg);
	QueryGOs<TitleUni>("tuni", [](TitleUni* tuni)->bool {
		DeleteGO(tuni);
		return true;
	});
	DeleteGO(m_titleFont);
	DeleteGO(m_sky);
	DeleteGO(m_bgm);
}
bool Title01::Start()
{
	m_titleFont = NewGO<TitleFont>(0);
	m_titleUni = NewGO<TitleUni>(0, "tuni");
	m_titleStar = NewGO<TitleStar>(0,"tstar");
	m_titleCamera = NewGO<TitleCamera>(0,"tcamera");
	m_titleBg = NewGO<TitleBg>(0,"tbg");
	m_bgm = NewGO<prefab::CSoundSource>(0);
	m_bgm->Init(L"sound/title.wav");
	m_bgm->Play(true);
	m_sky = NewGO<prefab::CSky>(0);
	return true;
}
void Title01::Update()
{
	//AÉ{É^ÉìÇ™âüÇ≥ÇÍÇΩÇÁÉQÅ[ÉÄÇ÷ëJà⁄
	if (Pad(0).IsTrigger(enButtonA)) {
		NewGO<Game>(0, "Game");
		DeleteGO(this);
	}

}