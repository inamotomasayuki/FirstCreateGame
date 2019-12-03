#pragma once

class Player;

class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();

	bool Start();
	void Update();
	CVector3 GetPosition()
	{
		return cameraPos;
	}
	CVector3 GetTarget()
	{
		return cameraTarget;
	}
	void SetCameraPos(CVector3 v) 
	{
		cameraPos = cameraTarget + v;
		MainCamera().SetPosition(cameraPos);
	}
private:
	CVector3 cameraTarget;
	CVector3 cameraPos;
	CVector3 toCameraPos;
	CQuaternion rot;

	Player* m_player = nullptr;
};

