#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
}


GameCamera::~GameCamera()
{
}

void GameCamera::Update()
{
	//プレイヤーのインスタンスを名前で検索する。
	Player* pl = FindGO<Player>("UnityChan");
	
	//実習課題1　プレイヤーからのオフセットを変更すると、
	//            注視点がどのように変わるか確認しなさい。
	//HandsOn 1 注視点を動かす。
	CVector3 cameraTarget;
	cameraTarget.x = pl->position.x;
	cameraTarget.y = pl->position.y + 100.0f;
	cameraTarget.z = pl->position.z;
	//注視点をカメラに伝える。
	MainCamera().SetTarget(cameraTarget);
	//実習課題2　注視点からのオフセットを変更すると、
	//            視点がどのように変わるか確認しなさい。
	//HandsOn 2 視点を動かす。
	CVector3 cameraPos;
	cameraPos = cameraTarget;
	cameraPos.y += 400.0f;
	cameraPos.z += 600.0f;
	//視点をカメラに伝える。
	MainCamera().SetPosition(cameraPos);
	//HandsOn 3 遠平面を設定する。
	MainCamera().SetFar(2000.0f);
	//HandsOn 4 画角を変更してみる。
	MainCamera().SetViewAngle(CMath::DegToRad(120.0f));
	//カメラ行列を更新する。
	MainCamera().Update();
}
