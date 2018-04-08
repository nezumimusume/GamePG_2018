#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
	//スプライトレンダラーのインスタンスを削除。
	DeleteGO(m_spriteRender);
}
bool BackGround::Start()
{
	m_spriteRender = NewGO<prefab::CSpriteRender>(0);
	m_spriteRender->Init(
		L"sprite/background.dds", 
		MainCamera().GetWidth(),  //飛行機の後ろに背景を書くための処理。
		MainCamera().GetHeight(), //飛行機の後ろに背景を書くための処理。
		true
	);
	return true;
}
