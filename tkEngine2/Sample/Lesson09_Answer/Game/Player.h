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
	prefab::CSkinModelRender*  m_skinModelRenderer = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;						//座標。	
};

