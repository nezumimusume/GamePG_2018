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
	//キャラクターのメインメモリに展開したデータを名前で検索する。
	Player* pl = FindGO<Player>("UnityChan");

	CVector3 cameraTarget;
	cameraTarget.x = pl->position.x;
	cameraTarget.y = pl->position.y + 100.0f;	//プレイヤーのちょっと上にする。
	cameraTarget.z = pl->position.z;

	g_camera3D->SetTarget(cameraTarget);
	//視点は注視点からＹ方向に＋４００、Ｚ方向に‐６００の場所にする。
	CVector3 cameraPos;
	cameraPos = cameraTarget;
	cameraPos.y += 400.0f;
	cameraPos.z -= 600.0f;
	g_camera3D->SetPosition(cameraPos);
	g_camera3D->SetFar(30000.0f);
	//カメラ行列を更新する。
	g_camera3D->Update();
}
