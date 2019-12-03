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
	cameraTarget = m_player->GetPosition();	//�����_���v�Z����
	cameraTarget.y += 100.0f;	//�v���C���̑������炿����Ə�𒍎��_�Ƃ���B
	cameraPos = MainCamera().GetPosition();
	toCameraPos = cameraPos - MainCamera().GetTarget(); //�����_
	CVector3 toCameraPosOld = toCameraPos;
	//Y������̉�]
	rot.SetRotationDeg(CVector3::AxisY, Pad(0).GetRStickXF() * 2.0f);
	rot.Apply(toCameraPos);
	//X������̉�]�B
	CVector3 vUP(0.0f, 1.0f, 0.0f);
	CVector3 vRotAxis;
	vRotAxis.Cross(toCameraPos, vUP);
	vRotAxis.Normalize();
	rot.SetRotationDeg(vRotAxis, Pad(0).GetRStickYF() * 2.0f);
	rot.Apply(toCameraPos);
	//�J�����̉�]�̏�����`�F�b�N����B
	//�����_���王�_�܂ł̃x�N�g���𐳋K������B
	//���K������ƁA�x�N�g���̑傫�����P�ɂȂ�B
	//�傫�����P�ɂȂ�Ƃ������Ƃ́A�x�N�g�����狭�����Ȃ��Ȃ�A�����݂̂̏��ƂȂ�Ƃ������ƁB
	CVector3 toPosDir = toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < 0.0f) {
		//�J�����������������B
		toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.8f) {
		//�J����������������B
		toCameraPos = toCameraPosOld;
	}
	//���_���v�Z����B
	cameraPos = cameraTarget + toCameraPos;

	MainCamera().SetTarget(cameraTarget);
	MainCamera().SetPosition(cameraPos);
	MainCamera().Update();
}