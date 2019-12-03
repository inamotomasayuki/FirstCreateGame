#pragma once
class GameOver : public IGameObject
{
public:
	GameOver();
	~GameOver();
	void PostRender(CRenderContext& rc);
private:
	CFont m_font;
	CVector2 m_position = { 0.0f,450.0f };
};

