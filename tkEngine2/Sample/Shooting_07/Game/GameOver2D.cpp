#include "stdafx.h"
#include "GameOver2D.h"

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
