#include "stdafx.h"
#include "Game.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "GameCamera.h"
#include "Player.h"
#include "Star.h"
#include "Enemy.h"
#include "Enemy_01.h"
#include "Enemy_02.h"
#include "BackGround.h"
#include "Floor.h"
#include "Font.h"
#include "Title.h"
#include "GameOver.h"
#include "GameClear.h"
#include "Title01.h"
#include "JumpFloor.h"
#include "GameData.h"

Game::Game()
{
}


Game::~Game()
{
	DeleteGO(m_gameCamera);
	QueryGOs<Player>("player", [](Player* pl)->bool {
		DeleteGO(pl);
		return true;
	});
	QueryGOs<Star>("star", [](Star* star)->bool {
		DeleteGO(star);
		return true;
	});
	QueryGOs<Enemy>("Enemy", [](Enemy* enemy)->bool {
		DeleteGO(enemy);
		return true;
	});
	QueryGOs<Enemy_01>("Enemy01", [](Enemy_01* enemy01)->bool {
		DeleteGO(enemy01);
		return true;
	});
	QueryGOs<Enemy_02>("Enemy02", [](Enemy_02* enemy02)->bool {
		DeleteGO(enemy02);
		return true;
	});
	QueryGOs<BackGround>("bg", [](BackGround* bg)->bool {
		DeleteGO(bg);
		return true;
	});
	DeleteGO(m_font);
	QueryGOs<Floor>("floor", [](Floor* floor)->bool {
		DeleteGO(floor);
		return true;
	});
	QueryGOs<GameClear>("gameclear", [](GameClear* gameclear)->bool {
		DeleteGO(gameclear);
		return true;
	});
	QueryGOs<JumpFloor>("jumpFloor", [](JumpFloor* jumpFloor)->bool {
		DeleteGO(jumpFloor);
		return true;
	});
	DeleteGO(m_gameOver);
	DeleteGO(m_bgm);
	DeleteGO(m_title);
}
bool Game::Start()
{
	if (g_gameData.GetStageNo() == 0) {
		m_level.Init(L"level00.tkl", [&](LevelObjectData& objData) {
			if (objData.EqualObjectName(L"unityChan")) {
				m_player = NewGO<Player>(0, "player");
				m_player->SetPosition(objData.position);
				m_player->SetRotation(objData.rotation);
				m_player->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"BackGround")) {
				m_backGround = NewGO<BackGround>(0, "bg");
				m_backGround->SetPosition(objData.position);
				m_backGround->SetRotation(objData.rotation);
				m_backGround->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"star")) {
				m_star = NewGO<Star>(0, "star");
				m_star->SetPosition(objData.position);
				m_star->SetRotation(objData.rotation);
				m_star->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"enemy00")) {
				m_enemy = NewGO<Enemy>(0, "Enemy");
				m_enemy->SetPosition(objData.position);
				m_enemy->SetRotation(objData.rotation);
				m_enemy->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"enemy01")) {
				m_enemy01 = NewGO<Enemy_01>(0, "Enemy01");
				m_enemy01->SetPosition(objData.position);
				m_enemy01->SetRotation(objData.rotation);
				m_enemy01->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"enemy02")) {
				m_enemy02 = NewGO<Enemy_02>(0, "Enemy02");
				m_enemy02->SetPosition(objData.position);
				m_enemy02->SetRotation(objData.rotation);
				m_enemy02->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"ugokuyuka")) {
				m_floor = NewGO<Floor>(0, "floor");
				m_floor->SetPosition(objData.position);
				m_floor->SetRotation(objData.rotation);
				m_floor->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"jumpFloor")) {
				m_jumpFloor = NewGO<JumpFloor>(0, "jumpFloor");
				m_jumpFloor->SetPosition(objData.position);
				m_jumpFloor->SetRotation(objData.rotation);
				m_jumpFloor->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"clear")) {
				m_gameClear = NewGO<GameClear>(0, "gameclear");
				m_gameClear->SetPosition(objData.position);
				m_gameClear->SetRotation(objData.rotation);
				m_gameClear->SetScale(objData.scale);
				return true;
			}
			return false;
			});
	}
	else if (g_gameData.GetStageNo() == 1) {
		m_level.Init(L"level01.tkl", [&](LevelObjectData& objData) {
			if (objData.EqualObjectName(L"unityChan")) {
				m_player = NewGO<Player>(0, "player");
				m_player->SetPosition(objData.position);
				m_player->SetRotation(objData.rotation);
				m_player->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"BackGround")) {
				m_backGround = NewGO<BackGround>(0, "bg");
				m_backGround->SetPosition(objData.position);
				m_backGround->SetRotation(objData.rotation);
				m_backGround->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"jumpFloor")) {
				m_jumpFloor = NewGO<JumpFloor>(0, "jumpFloor");
				m_jumpFloor->SetPosition(objData.position);
				m_jumpFloor->SetRotation(objData.rotation);
				m_jumpFloor->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"star")) {
				m_star = NewGO<Star>(0, "star");
				m_star->SetPosition(objData.position);
				m_star->SetRotation(objData.rotation);
				m_star->SetScale(objData.scale);
				return true;
			}
			if (objData.EqualObjectName(L"clear")) {
				m_gameClear = NewGO<GameClear>(0, "gameclear");
				m_gameClear->SetPosition(objData.position);
				m_gameClear->SetRotation(objData.rotation);
				m_gameClear->SetScale(objData.scale);
				return true;
			}
			return false;
			});
	}
	m_gameCamera = NewGO<GameCamera>(0,"camera");
	m_font = NewGO<Font>(0, "font");

	m_bgm = NewGO<prefab::CSoundSource>(0);
	m_bgm->Init(L"sound/normalBGM.wav");
	m_bgm->Play(true);

	return true;
}

void Game::Update()
{

	//セレクトボタンでタイトル
	if (Pad(0).IsTrigger(enButtonSelect)) {
		NewGO<Title01>(0);
		DeleteGO(this);
	}
	//タイムオーバーでタイトル
	if (m_font->GetTimer() == 30) {
		//サウンド再生
		m_sound = NewGO<prefab::CSoundSource>(0);
		m_sound->Init(L"sound/timeOver.wav");
		m_sound->Play(false);
	}
	if (m_font->GetTimer() > 130) {
		NewGO<Title01>(0);
		DeleteGO(this);
	}
	//HPが０でタイトル
	if (m_playerHp == 0 && m_font->GetSec() > 0) {
		if (m_gameOver == nullptr) {
			m_gameOver = NewGO<GameOver>(0);
			//サウンド再生
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/gameOver.wav");
			m_sound->Play(false);
		}
		m_timer++;
		if (m_timer > 130) {
			NewGO<Title01>(0);
			DeleteGO(this);
		}
		else if (m_timer > 60) {
			m_font->SetScorePosition({ 0.0f,100.0f });
		}
	}
	//ゲームクリアで次のステージにいきたい
	if (m_player->GetClearFlag() == true) {
		m_timer++;
		if (m_timer > 270) {
			DeleteGO(this);
			m_timer = 0;
			if (g_gameData.ProgressNextStageNo()) {
				NewGO<Game>(0, "Game");
			}
			else {
				NewGO<Title01>(0);
			}
		}
		else if (m_timer > 200) {
			if (m_title == nullptr && g_gameData.GetStageNo() == 0) {
				m_title = NewGO<Title>(0);
			}
		}
		else if (m_timer > 60) {
			m_font->SetScorePosition({ 0.0f,100.0f });
		}
	}
	//ステージから落ちたらタイトル
	CVector3 playerPos = m_player->GetPosition();
	if (playerPos.y < -100) {
		if (m_gameOver == nullptr) {
			m_gameOver = NewGO<GameOver>(0);
			//サウンド再生
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/gameOver.wav");
			m_sound->Play(false);
		}
		m_timer++;
		if (m_timer > 80) {
			NewGO<Title01>(0);
			DeleteGO(this);
		}
	}
}