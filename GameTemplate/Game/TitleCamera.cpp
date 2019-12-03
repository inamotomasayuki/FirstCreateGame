#include "stdafx.h"
#include "TitleCamera.h"
TitleCamera::TitleCamera()
{
}
TitleCamera::~TitleCamera()
{
}
bool TitleCamera::Start()
{
	MainCamera().SetTarget({ 0.0f, 0.0f, 0.0f });
	MainCamera().SetPosition({ 0.0f, -20.0f, -350.0f });
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);
	MainCamera().Update();

	return true;
}