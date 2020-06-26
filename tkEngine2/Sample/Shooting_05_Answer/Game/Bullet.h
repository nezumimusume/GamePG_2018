#pragma once
class Bullet : public IGameObject
{
public:
	Bullet();
	~Bullet();
	bool Start();
	void Update();
	/////////////////////////////////
	// ここからメンバ変数。
	/////////////////////////////////
    //スキンモデルレンダー
	prefab::CSkinModelRender* m_skinModelRender = nullptr;
	CVector3 m_position;	//座標。
	CVector3 m_moveSpeed;	//移動速度。
	int m_timer = 0; //タイマー。
};

