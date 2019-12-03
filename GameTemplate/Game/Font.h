#pragma once
class Font :public IGameObject
{
public:
	Font();
	~Font();
	void PostRender(CRenderContext& rc);
	void SetScorePosition(CVector2 v)
	{
		m_position = v;
	}
	int GetTimer() {
		return m_count;
	}
	int GetSec() {
		return m_sec;
	}
private:
	CFont m_font;
	CVector2 m_position = { 490.0f, 330.0f };
	CVector2 m_timeOverPos = { 0.0f,550 };
	float m_timer = 120.0f;
	float m_waitTimer = 0.0f;
	int m_sec;
	int m_count = 0;
};

