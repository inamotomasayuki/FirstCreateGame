#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
}


GameCamera::~GameCamera()
{
}
bool GameCamera::Start()
{
	MainCamera().SetTarget({ 0.0f, 0.0f, 0.0f });
	MainCamera().SetPosition({ 0.0f, 300.0f, -550.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(1000000.0f);

	return true;
}
void GameCamera::Update()
{

	m_player = FindGO<Player>("player");
	cameraTarget = m_player->GetPosition();	//注視点を計算する
	cameraTarget.y += 100.0f;	//プレイヤの足元からちょっと上を注視点とする。
	cameraPos = MainCamera().GetPosition();
	toCameraPos = cameraPos - MainCamera().GetTarget(); //注視点
	CVector3 toCameraPosOld = toCameraPos;
	//Y軸周りの回転
	rot.SetRotationDeg(CVector3::AxisY, Pad(0).GetRStickXF() * 2.0f);
	rot.Apply(toCameraPos);
	//X軸周りの回転。
	CVector3 vUP(0.0f, 1.0f, 0.0f);
	CVector3 vRotAxis;
	vRotAxis.Cross(toCameraPos, vUP);
	vRotAxis.Normalize();
	rot.SetRotationDeg(vRotAxis, Pad(0).GetRStickYF() * 2.0f);
	rot.Apply(toCameraPos);
	//カメラの回転の上限をチェックする。
	//注視点から視点までのベクトルを正規化する。
	//正規化すると、ベクトルの大きさが１になる。
	//大きさが１になるということは、ベクトルから強さがなくなり、方向のみの情報となるということ。
	CVector3 toPosDir = toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < 0.0f) {
		//カメラが下向きすぎ。
		toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.8f) {
		//カメラが上向きすぎ。
		toCameraPos = toCameraPosOld;
	}
	//視点を計算する。
	cameraPos = cameraTarget + toCameraPos;

	MainCamera().SetTarget(cameraTarget);
	MainCamera().SetPosition(cameraPos);
	MainCamera().Update();
}