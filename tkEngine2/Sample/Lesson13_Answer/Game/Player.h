#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void MoveAndRotation();
	//////////////////////////////
	//　ここからメンバ変数。
	//////////////////////////////
	prefab::CSkinModelRender*  m_skinModelRenderer = nullptr;	//スキンモデルレンダラー。
	CVector3 m_position = CVector3::Zero;						//座標。
	int m_timer = 0;											//タイマー。
};

