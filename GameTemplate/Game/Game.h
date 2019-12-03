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

	//�X�R�A�l�ݒ�B
	void SetScore(int i)
	{
		if (i >= 0 && i <= 9999) {
			m_score += i;
		}
	}
	//�X�R�A�l�擾�B
	int GetScore()
	{
		return m_score;
	}
	//�v���C���[��Hp�ݒ�B
	void SetPlayerHp(int i) 
	{
		if (m_playerHp > 0 && m_playerHp <= 100) {
			m_playerHp += i;
		}
	}
	//�v���C���[��Hp�擾�B
	int GetPlayerHp()
	{
		return m_playerHp;
	}

protected:
	CLevel m_level;
	prefab::CSoundSource* m_bgm = nullptr;						//�T�E���h�\�[�X
	prefab::CSoundSource* m_sound = nullptr;

	GameCamera* m_gameCamera = nullptr;				//�Q�[���J����
	Player* m_player = nullptr;						//�v���C���[
	Star* m_star = nullptr;							//��
	Enemy* m_enemy = nullptr;						//�G0
	Enemy_01* m_enemy01 = nullptr;					//�G1
	Enemy_02* m_enemy02 = nullptr;					//�G2
	BackGround* m_backGround = nullptr;				//�w�i
	Font* m_font = nullptr;							//����
	Floor* m_floor = nullptr;						//������
	JumpFloor* m_jumpFloor = nullptr;				//�W�����v��
	GameOver* m_gameOver = nullptr;					//�Q�[���I�[�o�[
	GameClear* m_gameClear = nullptr;				//�N���A��
	Title* m_title = nullptr;						//NextStageSprite

	int m_timer = 0;
	int m_score = 0;			//�X�R�A
	int m_playerHp = 5;		//�v���C���[��HP

};