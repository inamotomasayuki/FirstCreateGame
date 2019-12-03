#include "stdafx.h"
#include "Font.h"
#include "Game.h"
#include "Player.h"

Font::Font()
{
}


Font::~Font()
{
}

void Font::PostRender(CRenderContext& rc)
{
	m_timer = max(0.0f, m_timer - GameTime().GetFrameDeltaTime());
	wchar_t text[256];
	int minute = (int)m_timer / 60;
	m_sec = (int)m_timer % 60;
	swprintf_s(text, L"%02d:%02d", minute, m_sec);

	Game* game = FindGO<Game>("Game");
	Player* player = FindGO<Player>("player");
	m_font.Begin(rc);
	m_font.Draw(
		L"タイム",
		{ -580,290 }, 
		{ 200.0f,100.0f,0.0f,0.0f }
	);
	m_font.Draw(
		text,
		{ -450,290 },
		{ 255.0f, 255.0f, 0.0f, 1.0f }
	);
	swprintf_s(text, L"スコア %04d", game->GetScore());
	m_font.Draw(
		text,
		m_position
	);

	if (m_timer <= 0) {
		player->SetState(1);
		m_font.Draw(
			L"TIME UP",
			m_timeOverPos,
			{ 255.0f,0.0f,0.0f,50.0f },
			0.0f,
			2.0f
		);
		if (m_timeOverPos.y > 0) {
			m_timeOverPos.y -= 10.0f;
		}
		m_count++;
		if (m_count > 60) {
			m_position = { 0.0f,100.0f };
		}
	}

	swprintf_s(text, L"HP %02d", game->GetPlayerHp());
	m_font.Draw(
		text,
		{ 540.0f, -300.0f },
		{ 0.0f,60.0f,230.0f,150.0f }
	);

	m_font.End(rc);
}