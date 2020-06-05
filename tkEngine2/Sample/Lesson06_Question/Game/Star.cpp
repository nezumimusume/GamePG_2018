#include "stdafx.h"
#include "Star.h"
#include "Player.h" 

//////////////////////////////////////////////////////////  
// デストラクタ。 
// メインメモリに展開したデータが破棄されるときに呼ばれる。 
//////////////////////////////////////////////////////////  
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

	//スターのモデルを読み込んで、SkinModelRenderを作成。
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/star.cmo");
	position.x = 0.0f;
	position.y = 100.0f;
	position.z = 0.0f;
	skinModelRender->SetPosition(position);
	//スターのモデルが小さいので20倍くらいにしておく。
	CVector3 scale;
	scale.x = 20.0f;
	scale.y = 20.0f;
	scale.z = 20.0f;
	skinModelRender->SetScale(scale);

	return true;
}

///////////////////////////////////////////////// 
// 更新関数 
// 毎フレーム一定の間隔で呼ばれる。 
///////////////////////////////////////////////// 
void Star::Update()
{

}

