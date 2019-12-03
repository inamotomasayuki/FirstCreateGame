#pragma once
//��׸�����۰װ���g���Ƃ��̃w�b�_�[�t�@�C��
#include "tkEngine/character/tkCharacterController.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
class Game;
class GameCamera;
class Font;
class Floor;
class GameClear;
class ClearFont;
class JumpFloor;
class Player : public IGameObject
{
public:
	Player();
	~Player();

	bool Start();
	void Update();

	//���W�̎擾�B
	CVector3 GetPosition()
	{
		return m_position;
	}
	//���W�̐ݒ�B
	void SetPosition(CVector3 v)
	{
		m_position = v;
	}
	//��]�̐ݒ�B
	void SetRotation(CQuaternion q)
	{
		m_rotation = q;
	}
	//�X�P�[���̐ݒ�B
	void SetScale(CVector3 s)
	{
		m_scale = s;
	}
	//�W�����v�t���O�̎擾
	bool GetJumpFlag()
	{
		return m_charaCon.IsJump();
	}
	bool GetClearFlag()
	{
		return m_clearFlag;
	}
	void SetSpeed(CVector3 v)
	{
		m_force = v;
	}
	void SetState(int i)
	{
		m_statenum = i;
	}
	void SetMove(CVector3 v)
	{
		m_move = v;
	}
private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//����������ް
	CVector3 m_position = CVector3::Zero;						//���W
	CVector3 m_force = CVector3::Zero;							//�O�������������́B
	CVector3 m_move = CVector3::Zero;
	CVector3 m_movespeed;										//�ړ����x
	CVector3 m_gravity;
	CQuaternion m_rotation = CQuaternion::Identity;				//��]
	CCharacterController m_charaCon;							//��׸�����۰װ
	CVector3 m_scale = CVector3::One;							//�X�P�[��

	Game* m_game;				//�Q�[��
	GameCamera* m_camera;		//�Q�[���J����
	Floor* m_floor = nullptr;
	GameClear* m_gameClear = nullptr;
	JumpFloor* m_jumpFloor = nullptr;
	ClearFont* m_clearFont = nullptr;
	bool m_clearFlag = false;
	enum EnAnimationClip {
		enAnimationClip_idle,	//�ҋ@�A�j���[�V�����B
		enAnimationClip_run,	//����A�j���[�V�����B
		enAnimationClip_walk,	//�����A�j���[�V�����B
		enAnimationClip_jump,	//�W�����v�A�j���[�V�����B
		enAnimationClip_damage,
		enAnimationClip_clear,
		enAnimationClip_Num		//�A�j���[�V�����N���b�v�̐��B
	};
	CAnimationClip m_animClips[enAnimationClip_Num];	//�A�j���[�V�����N���b�v�B
	enum EnState {
		enState_play,
		enState_gameOver,
		enState_gameClear
	};
	EnState m_state;
	int m_statenum = 0;
	prefab::CSoundSource* m_sound = nullptr;
	void StickMove();
	void Rotation();
};

