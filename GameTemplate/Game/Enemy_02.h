#pragma once
#include "tkEngine/character/tkCharacterController.h"

class Player;
class Game;

class Enemy_02 : public IGameObject
{
public:
	Enemy_02();
	~Enemy_02();
	bool Start();
	void Update();

	//���W�̐ݒ�
	void SetPosition(CVector3 v)
	{
		m_position = v;
	}
	//��]�̐ݒ�B
	void SetRotation(CQuaternion q)
	{
		m_rotation = q;
	}
	void SetScale(CVector3 s)
	{
		m_scale = s;
	}

private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//����������ް
	CVector3 m_position = CVector3::Zero;						//���W
	CVector3 m_movespeed;										//�ړ����x
	CQuaternion m_rotation = CQuaternion::Identity;				//��]
	CVector3 m_scale = CVector3::One;							//�X�P�[��
	CCharacterController m_charaCon;							//��׸�����۰װ
	prefab::CSoundSource* m_sound = nullptr;
	prefab::CEffect* effect = nullptr;

	int m_timer = 0;		//�^�C�}�[
	
	Player* m_player;		//�v���C���[
	Game* m_game;			//�Q�[��

	enum EnState {
		enState_right,		//�E
		enState_left,		//��
		enState_Atack		//�U��
	};
	EnState m_state;
	void Move();
	void Jump();
	void Attack();
	void Death();
};

