#pragma once
class Player;
class Game;

class Star : public IGameObject
{
public:
	Star();
	~Star();
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
	Player* m_player;
	Game* m_game;
	prefab::CSoundSource* m_sound = nullptr;
	prefab::CEffect* effect = nullptr;

	void Rotation();
	void GetStar();

};

