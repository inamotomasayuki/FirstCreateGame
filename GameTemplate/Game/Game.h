#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"


class BackGround;
class GameCamera;
class Player;
class Star;
class Enemy;
class Enemy_01;
class Enemy_02;
class Font;
class Floor;
class GameOver;
class GameClear;
class Title;
class JumpFloor;
class GameData;

class Game : public IGameObject
{
public:
	Game();
	~Game();

	bool Start();
	void Update();

	//スコア値設定。
	void SetScore(int i)
	{
		if (i >= 0 && i <= 9999) {
			m_score += i;
		}
	}
	//スコア値取得。
	int GetScore()
	{
		return m_score;
	}
	//プレイヤーのHp設定。
	void SetPlayerHp(int i) 
	{
		if (m_playerHp > 0 && m_playerHp <= 100) {
			m_playerHp += i;
		}
	}
	//プレイヤーのHp取得。
	int GetPlayerHp()
	{
		return m_playerHp;
	}

protected:
	CLevel m_level;
	prefab::CSoundSource* m_bgm = nullptr;						//サウンドソース
	prefab::CSoundSource* m_sound = nullptr;

	GameCamera* m_gameCamera = nullptr;				//ゲームカメラ
	Player* m_player = nullptr;						//プレイヤー
	Star* m_star = nullptr;							//星
	Enemy* m_enemy = nullptr;						//敵0
	Enemy_01* m_enemy01 = nullptr;					//敵1
	Enemy_02* m_enemy02 = nullptr;					//敵2
	BackGround* m_backGround = nullptr;				//背景
	Font* m_font = nullptr;							//文字
	Floor* m_floor = nullptr;						//動く床
	JumpFloor* m_jumpFloor = nullptr;				//ジャンプ床
	GameOver* m_gameOver = nullptr;					//ゲームオーバー
	GameClear* m_gameClear = nullptr;				//クリア床
	Title* m_title = nullptr;						//NextStageSprite

	int m_timer = 0;
	int m_score = 0;			//スコア
	int m_playerHp = 5;		//プレイヤーのHP

};