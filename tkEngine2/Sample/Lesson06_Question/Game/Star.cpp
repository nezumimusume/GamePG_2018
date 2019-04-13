#include "stdafx.h"
#include "Star.h"
#include "Player.h"



/////////////////////////////////////////////////
// デストラクタ。
// インスタンスが破棄されるときに呼ばれる。
/////////////////////////////////////////////////
Star::~Star()
{
	//スキンモデルレンダラーを削除。
	DeleteGO(skinModelRender);
}
/////////////////////////////////////////////////
// Start関数。
// 初めてUpdateが呼ばれる直前に一度だけ呼ばれる。
/////////////////////////////////////////////////
bool Star::Start()
{
	//プレイヤーのインスタンスを名前で検索する。
	player = FindGO<Player>("UnityChan");

	//HandsOn 2 スターのモデルを読み込んで、SkinModelRenderを作成。
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/star.cmo");
	skinModelRender->SetPosition(position);
	//スターが小さいので20倍にする。
	CVector3 scale = { 20.0f, 20.0f, 20.0f };
	skinModelRender->SetScale(scale);
	
	return true;
}
/////////////////////////////////////////////////
// 更新関数
// 毎フレーム一定の間隔で呼ばれる。
/////////////////////////////////////////////////
void Star::Update()
{
	////////////////////////////////////////////
	// 実習課題　スターを上下に動かしなさい。
	////////////////////////////////////////////

	//HandsOn 3 スターを回転させる。
	angle += 3.0f;
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, angle);
	skinModelRender->SetRotation(qRot);
	//HandsOn 4 プレイヤーとの距離を計算して、130cm以下なら星を削除する。
	
}