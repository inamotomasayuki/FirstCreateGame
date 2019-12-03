#pragma once
#include "tkEngine/physics/tkPhysicsGhostObject.h"
class Player;

class GameClear : public IGameObject
{
public:
	GameClear();
	~GameClear();
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
	CPhysicsGhostObject* GetGhost()
	{
		return &m_ghostObject;
	}
private:
	CPhysicsStaticObject m_physicsStaticObject;				//�ÓI�����I�u�W�F�N�g�B
	CPhysicsGhostObject m_ghostObject;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//����������ް
	CVector3 m_position = CVector3::Zero;						//���W
	CVector3 m_movespeed;										//�ړ����x
	CQuaternion m_rotation = CQuaternion::Identity;				//��]
	CVector3 m_scale;											//�X�P�[��

	Player* m_player;		//�v���C���[
};

