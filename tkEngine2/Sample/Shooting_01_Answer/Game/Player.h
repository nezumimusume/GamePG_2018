#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();

	//////////////////////////////
	//　ここからメンバ変数。
	//////////////////////////////
	//スキンモデルレンダラー。
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position ;	//座標。

};



