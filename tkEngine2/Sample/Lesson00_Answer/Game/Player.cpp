#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	//スキンモデルレンダラーを作成する。
	skinModelRenderer = NewGO<prefab::CSkinModelRender>(0);
	skinModelRenderer->Init(L"modelData/unityChan.cmo");
}


Player::~Player()
{
}
