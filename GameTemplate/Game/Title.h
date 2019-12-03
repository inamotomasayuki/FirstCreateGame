#pragma once
class Game;
class Title : public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
private:
	prefab::CSpriteRender* m_spriteRender = nullptr;
};

