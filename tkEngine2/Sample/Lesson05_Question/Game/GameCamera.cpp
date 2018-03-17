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
	
	//実習課題2　注視点からのオフセットを変更すると、
	//            視点がどのように変わるか確認しなさい。
	//HandsOn 2 視点を動かす。
	
	//HandsOn 3 遠平面を設定する。
	
	//HandsOn 4 画角を変更してみる。
	
	//カメラ行列を更新する。
	MainCamera().Update();
}
