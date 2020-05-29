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
	//HandsOn 1 注視点を動かす。
	CVector3 cameraTarget;
	cameraTarget.x = pl->position.x;
	cameraTarget.y = pl->position.y + 100.0f;	//プレイヤーのちょっと上にする。
	cameraTarget.z = pl->position.z;
	//注視点をカメラに伝える。
	g_camera3D->SetTarget(cameraTarget);


	//HandsOn 2 視点を動かす。
	//視点は注視点からＹ方向に＋４００、Ｚ方向に‐６００の場所にする。
	CVector3 cameraPos;
	cameraPos = cameraTarget;
	cameraPos.y += 400.0f;
	cameraPos.z -= 600.0f;
	//視点をカメラに伝える。
	g_camera3D->SetPosition(cameraPos);


	//HandsOn 3 遠平面を設定する。
	g_camera3D->SetFar(30000.0f);
	//実習課題１　遠平面を1000.0fに変更しなさい。
	g_camera3D->SetFar(1000.0f);

	//HandsOn 4 画角を変更してみる。
	//画角を120度にしてみる。
	g_camera3D->SetViewAngle(CMath::DegToRad(120.0f));

	//実習課題２　画角を90.0fに変更しなさい。
	g_camera3D->SetViewAngle(CMath::DegToRad(90.0f));

	//カメラを更新する。
	g_camera3D->Update();
}
