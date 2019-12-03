#include "stdafx.h"
#include "ClearFont.h"
ClearFont::ClearFont()
{
}
ClearFont::~ClearFont()
{
}

void ClearFont::PostRender(CRenderContext& rc)
{
	wchar_t text[256];

	m_font.Begin(rc);

	if (m_position.y > 0.0f) {
		m_position.y -= 10.0f;
	}

	swprintf_s(text, L"GAME CLEAR");
	m_font.Draw(
		text,
		m_position,
		{ 255.0f,255.0f,0.0f,50.0f }
	);

	m_font.End(rc);
}