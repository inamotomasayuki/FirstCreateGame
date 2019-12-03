#pragma once
class TitleBg;
class TitleCamera;
class TitleUni;
class TitleStar;
class TitleFont;
class Title01 : public IGameObject
{
public:
	Title01();
	~Title01();
	bool Start();
	void Update();
private:
	prefab::CSoundSource* m_bgm = nullptr;
	prefab::CSky* m_sky = nullptr;
	TitleBg* m_titleBg = nullptr;
	TitleCamera* m_titleCamera = nullptr;
	TitleUni* m_titleUni = nullptr;
	TitleStar* m_titleStar = nullptr;
	TitleFont* m_titleFont = nullptr;
};

