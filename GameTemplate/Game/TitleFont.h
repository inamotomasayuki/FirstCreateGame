#pragma once
class TitleFont : public IGameObject
{
public:
	TitleFont();
	~TitleFont();
	void PostRender(CRenderContext& rc);
private:
	CFont m_font;
	CVector2 m_titlePos = { 110.0f, 230.0f };
	CVector2 m_pressPos = { 120.0f,-100.0f };
};


