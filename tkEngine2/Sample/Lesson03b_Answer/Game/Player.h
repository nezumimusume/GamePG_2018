#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();
	void Rotation();

	//ここからメンバ変数。
	prefab::CSkinModelRender* skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 position ;
	CQuaternion rotation ;
};

