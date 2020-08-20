#include "stdafx.h"
#include "TitleScene.h"
#include "GameScene.h"

// コンストラクタ。インスタンスが生成されるときに呼ばれる処理。
TitleScene::TitleScene()
{
}
// デストラクタ。インスタンスが破棄されるときに呼ばれる処理。
TitleScene::~TitleScene()
{
	DeleteGO(m_spriteRender);
}
bool TitleScene::Start()
{
	//CSpriteRenderのインスタンスを作成
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//タイトル画像をロード
	m_spriteRender->Init(L"sprite/Title.dds", 1280.0f, 720.0f);
	return true;
}
void TitleScene::Update()
{
	//もしもAボタンが押されたら。
	if (g_pad[0]->IsTrigger(enButtonA)) {
		//GameSceneのインスタンスを生成。
		NewGO<GameScene>(0, "GameScene");
		//シーンが切り替わるのでTitleSceneのインスタンスを削除。
		DeleteGO(this);
	}

}

