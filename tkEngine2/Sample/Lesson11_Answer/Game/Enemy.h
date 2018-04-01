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
	CVector3 m_moveSpeed = CVector3::Zero;						//エネミーの移動速度。
	prefab::CSkinModelRender*	m_skinModelRender = nullptr;	//スキンモデルレンダー。
	CVector3 m_position = CVector3::Zero;						//座標。
};

