#pragma once
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	bool Start();
	void Update();
	///////////////////////////////
	// ここからメンバ変数
	///////////////////////////////
	prefab::CSkinModelRender*	m_skinModelRender = nullptr;	//スキンモデルレンダー。
	CVector3 m_position = CVector3::Zero;						//座標。
	int m_timer = 0;	//タイマー。
};

