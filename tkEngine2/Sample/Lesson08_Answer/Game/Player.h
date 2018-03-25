#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	//////////////////////////////
	//　ここからメンバ変数。
	//////////////////////////////
	prefab::CSkinModelRender*  m_skinModelRenderer = nullptr;	//スキンモデルレンダラー。
};

