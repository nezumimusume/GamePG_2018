#include "stdafx.h"
#include "Star.h"
#include "Player.h"



/////////////////////////////////////////////////
// デストラクタ。
// メインメモリに展開したデータが破棄されるときに呼ばれる。
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
	//キャラクターのメインメモリに展開したデータを名前で検索する。
	player = FindGO<Player>("UnityChan");

	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/star.cmo");
	skinModelRender->SetPosition(position);
	//スターのモデルが小さいので20倍くらいにしておく。
	CVector3 scale = { 20.0f, 20.0f, 20.0f };
	skinModelRender->SetScale(scale);

	
	return true;
}
/////////////////////////////////////////////////
// Update関数
// 毎フレーム一定の間隔で呼ばれる。
/////////////////////////////////////////////////
void Star::Update()
{
	moveCount++;
	if (moveCount < 50) {
		//50より小さければ上に動く。
		position.y += 1.0f;
	}
	else if(moveCount < 100){
		//50以上、100以下なら下に動く
		position.y -= 1.0f;
	}
	else {
		//100以上になったらカウントを０に戻す。
		moveCount = 0;
	}
	//スキンモデルに座標を伝える。
	skinModelRender->SetPosition(position);

	
	//スターを回転させる。
	angle += 3.0f; //毎フレーム3°ずつ回転を加算していく。
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, angle); //回転クォータニオンを作成。
	skinModelRender->SetRotation(qRot);

	
	CVector3 diff = player->position - position;
	if (diff.Length() < 130.0f) {
		//HandsOn3 コインを取得したときに音を鳴らそう。
		


		DeleteGO(this);
	}
}