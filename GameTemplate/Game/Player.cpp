#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include "GameCamera.h"
#include "Font.h"
#include "Floor.h"
#include "GameClear.h"
#include "ClearFont.h"
#include "JumpFloor.h"
Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_skinModelRender);
	DeleteGO(m_clearFont);
}

bool Player::Start()
{
	//�A�j���[�V�����N���b�v�̃��[�h�B
	m_animClips[enAnimationClip_idle].Load(L"animData/unityChan/idle.tka");
	m_animClips[enAnimationClip_run].Load(L"animData/unityChan/run.tka");
	m_animClips[enAnimationClip_walk].Load(L"animData/unityChan/walk.tka");
	m_animClips[enAnimationClip_jump].Load(L"animData/unityChan/jump.tka");
	m_animClips[enAnimationClip_damage].Load(L"animData/unityChan/KneelDown.tka");
	m_animClips[enAnimationClip_clear].Load(L"animData/unityChan/clear.tka");
	//���[�v�t���O��ݒ肷��
	//����A�j���[�V�����̓��[�v�t���O��ݒ肵�Ă��Ȃ��̂Ń����V���b�g�Đ��Œ�~�B
	m_animClips[enAnimationClip_idle].SetLoopFlag(true);
	m_animClips[enAnimationClip_run].SetLoopFlag(true);
	m_animClips[enAnimationClip_walk].SetLoopFlag(true);
	m_animClips[enAnimationClip_jump].SetLoopFlag(false);
	m_animClips[enAnimationClip_damage].SetLoopFlag(false);
	m_animClips[enAnimationClip_clear].SetLoopFlag(false);

	EnFbxUpAxis Up = enFbxUpAxisY;		//FBX�̏����

	m_skinModelRender= NewGO<prefab::CSkinModelRender>(0);
	//�X�L�����f�������_���[������
	m_skinModelRender->Init(
		L"modelData/unityChan.cmo",
		m_animClips,
		enAnimationClip_Num,
		Up
	);	
	m_rotation.SetRotationDeg(CVector3::AxisY, 180);
	m_skinModelRender->SetPosition(m_position);
	m_skinModelRender->SetRotation(m_rotation);
	m_skinModelRender->SetScale(m_scale);

	//��׸�����۰װ
	m_charaCon.Init(
		20.0,			//���a
		100.0f,			//����
		m_position		//�������W
	);

	m_camera = FindGO<GameCamera>("camera");
	m_game = FindGO<Game>("Game");

	m_state = enState_play;
	return true;
}

void Player::Update()
{
	//�d��
	m_movespeed.y -= 40.0f;
	if (m_game->GetPlayerHp() == 0 || m_statenum == 1) {
		m_state = enState_gameOver;
	}
	if (m_state == enState_play) {
		StickMove();	//�v���C���[�̈ړ�

		//�_�b�V��
		if (Pad(0).IsPress(enButtonB)) {
			m_movespeed.x *= 1.5f;
			m_movespeed.z *= 1.5f;
		}

		//�W�����v
		if (m_charaCon.IsOnGround() && Pad(0).IsTrigger(enButtonA)) {
			m_movespeed.y = 900.0f;
			//�T�E���h�Đ�
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/jump.wav");
			m_sound->Play(false);
		}
		//�W�����v�A�j���[�V����
		if (m_charaCon.IsJump() == true) {
			m_skinModelRender->PlayAnimation(enAnimationClip_jump, 0.2f);
		}
		CVector3 moveSpeed = m_movespeed + m_force;
		m_floor = FindGO<Floor>("floor", false);
		m_gameClear = FindGO<GameClear>("gameclear",false);
		m_jumpFloor = FindGO<JumpFloor>("jumpFloor",false);
		PhysicsWorld().ContactTest(m_charaCon, [&](const btCollisionObject& contactObject) {
			if (m_floor->GetGhost()->IsSelf(contactObject) == true) {
					//m_ghostObject�ƂԂ�����
					moveSpeed += m_move;
			}
			if (m_jumpFloor->GetGhost()->IsSelf(contactObject) == true) {
				moveSpeed.y = 1500.0f;
				m_sound = NewGO<prefab::CSoundSource>(0);
				m_sound->Init(L"sound/jump.wav");
				m_sound->Play(false);
			}
			if (m_gameClear->GetGhost()->IsSelf(contactObject) == true) {
				if (m_clearFont == nullptr) {
					m_clearFont = NewGO<ClearFont>(0,"clearFont");
					//�T�E���h�Đ�
					m_sound = NewGO<prefab::CSoundSource>(0);
					m_sound->Init(L"sound/gameClear.wav");
					m_sound->Play(false);
				}
				m_clearFlag = true;
				m_state = enState_gameClear;
			}
		});
		//moveSpeed = m_movespeed + m_move;
		m_force *= 0.75f;
		if (m_force.Length() < 0.01f) {
			m_force = CVector3::Zero;
		}
		m_position = m_charaCon.Execute(moveSpeed, GameTime().GetFrameDeltaTime());
		m_movespeed.y = moveSpeed.y;

		m_skinModelRender->SetPosition(m_position);

		Rotation();		//�v���C���[�̉�]

	}
	//����s�ɂ��ăA�j���[�V�����𗬂�
	else if (m_state == enState_gameOver) {
		m_camera->SetCameraPos({ 0.0f,0.0f,-200.0f });
		m_gravity.y -= 40.0f;
		m_position = m_charaCon.Execute(m_gravity, GameTime().GetFrameDeltaTime());
		m_skinModelRender->SetPosition(m_position);
		m_rotation.SetRotationDeg(CVector3::AxisY, 180.0f);
		m_skinModelRender->SetRotation(m_rotation);
		m_skinModelRender->PlayAnimation(enAnimationClip_damage, 0.2f);
	}
	else if (m_state == enState_gameClear) {
		m_camera->SetCameraPos({ 0.0f,0.0f,-200.0f });
		m_gravity.y -= 40.0f;
		m_position = m_charaCon.Execute(m_gravity, GameTime().GetFrameDeltaTime());
		m_skinModelRender->SetPosition(m_position);
		m_rotation.SetRotationDeg(CVector3::AxisY, 180.0f);
		m_skinModelRender->SetRotation(m_rotation);
		m_skinModelRender->PlayAnimation(enAnimationClip_clear, 0.2f);
	}
}

void Player::StickMove()
{
	//�X�e�B�b�N���͂ŃJ�������l�������v���C���[�̈ړ�
	//�O�����̈ړ�
	CVector3 v = m_camera->GetTarget() - m_camera->GetPosition();
	v.Normalize();
	v.y = 0.0f;
	m_movespeed.x = 0.0f;
	m_movespeed.z = 0.0f;
	m_movespeed += v * Pad(0).GetLStickYF() * 400.0f;
	//�������̈ړ�
	CVector3 cameraRight;
	cameraRight.Cross(v, CVector3::AxisY);
	cameraRight.Normalize();
	m_movespeed += cameraRight * Pad(0).GetLStickXF() * -400.0f;
}

void Player::Rotation()
{
	//�v���C���[�̉�]
	//���Ƃ��̃x�N�g������p�x�����߂ĉ�]������
	auto moveSpeedXZ = m_movespeed;
	moveSpeedXZ.y = 0.0f;
	moveSpeedXZ.Normalize();
	if (moveSpeedXZ.LengthSq() < 0.8f) {
		if (m_charaCon.IsJump() == false) {
			m_skinModelRender->PlayAnimation(enAnimationClip_idle);
		}
		return;		//���͗ʂ��������Ƃ��͉�]���Ȃ�
	}
	else {
		if (m_charaCon.IsJump() == false) {
			m_skinModelRender->PlayAnimation(enAnimationClip_run, 0.2f);
		}
	}
	m_rotation.SetRotation(CVector3::AxisY, atan2f(moveSpeedXZ.x, moveSpeedXZ.z));	//�p�x�����߂�֐�
	m_skinModelRender->SetRotation(m_rotation);
}