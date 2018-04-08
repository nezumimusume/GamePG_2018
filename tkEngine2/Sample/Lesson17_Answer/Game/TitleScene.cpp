#include "stdafx.h"
#include "TitleScene.h"
#include "GameScene.h"

TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
	DeleteGO(m_spriteRender);
}

bool TitleScene::Start()
{
	//CSpriteRenderのインスタンスを作成。
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//タイトル画像をロード。
	m_spriteRender->Init(L"sprite/Title.dds", 1280.0f, 720.0f);
	return true;
}
void TitleScene::Update()
{
	//もしもAボタンが押されたら。
	if (Pad(0).IsTrigger(enButtonA)) {
		//GameSceneのインスタンスを生成。
		NewGO<GameScene>(0, "GameScene");
		//シーンが切り替わるのでTitleSceneのインスタンスを削除。
		DeleteGO(this);
	}
}