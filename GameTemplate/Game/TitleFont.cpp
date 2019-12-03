#include "stdafx.h"
#include "TitleFont.h"
TitleFont::TitleFont()
{
}
TitleFont::~TitleFont()
{
}
void TitleFont::PostRender(CRenderContext& rc)
{
	wchar_t text[256];

	m_font.Begin(rc);

	swprintf_s(text, L"Runity");
	m_font.Draw(
		text,
		m_titlePos,
		{ 0.0f,255.0f,200.0f,50.0f },
		0.0f,
		1.5f
	);
	swprintf_s(text, L"START\nPress A");
	m_font.Draw(
		text,
		m_pressPos,
		{ 200.0f,255.0f,200.0f,50.0f }
	);
	m_font.End(rc);

}