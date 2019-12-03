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

	//座標の設定
	void SetPosition(CVector3 v)
	{
		m_position = v;
	}
	//回転の設定。
	void SetRotation(CQuaternion q)
	{
		m_rotation = q;
	}
	void SetScale(CVector3 s)
	{
		m_scale = s;
	}

private:
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//ｽｷﾝﾓﾃﾞﾙﾚﾝﾀﾞｰ
	CVector3 m_position = CVector3::Zero;						//座標
	CVector3 m_movespeed;										//移動速度
	CQuaternion m_rotation = CQuaternion::Identity;				//回転
	CVector3 m_scale = CVector3::One;							//スケール
	Player* m_player;
	Game* m_game;
	prefab::CSoundSource* m_sound = nullptr;
	prefab::CEffect* effect = nullptr;

	void Rotation();
	void GetStar();

};

