#include "stdafx.h"
#include "GameOver2D.h"
#include "GameScene.h"
#include "TitleScene.h"

GameOver2D::GameOver2D()
{
}


GameOver2D::~GameOver2D()
{
	//スプライトレンダラーを削除。
	DeleteGO(m_spriteRender);
}

bool GameOver2D::Start()
{
	//CSpriteRenderのインスタンスを生成
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	//２Ｄをロード。
	m_spriteRender->Init(
		L"sprite/GAMEOVER.dds",		//読み込むファイルのファイルパス。
		1105.0f,					//スプライトの幅。
		115.0f						//スプライトの高さ。
	);
	return true;
}
void GameOver2D::Update()
{
	if (Pad(0).IsTrigger(enButtonA)) {
		//ゲームシーンを削除する。
		GameScene* gameScene = FindGO<GameScene>("GameScene");
		DeleteGO(gameScene);		
		NewGO<TitleScene>(0);
	}
}