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
//スキンモデルレンダラー。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;

};


