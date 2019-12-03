#pragma once

class Player;
class Game;

class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
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
	//�X�P�[���̐ݒ�
	void SetScale(CVector3 s)
	{
		m_scale = s;
	}
	
private:
	CPhysicsStaticObject m_physicsStaticObject;				//�ÓI�����I�u�W�F�N�g�B
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//����������ް
	CVector3 m_position;										//���W
	CVector3 m_movespeed;										//�ړ����x
	CQuaternion m_rotation = CQuaternion::Identity;				//��]
	CVector3 m_scale = CVector3::One;
	CVector3 m_startPos;
	prefab::CEffect* effect = nullptr;
	prefab::CSoundSource* m_sound = nullptr;

	int m_timer = 0;		//�^�C�}�[
	Player* m_player;		//�v���C���[
	Game* m_game;			//�Q�[��
	enum EnState {
		enState_left,		//��
		enState_right,		//�E
		enState_search,		//�ǐ�
		enState_Atack
	};
	EnState m_state;
};

