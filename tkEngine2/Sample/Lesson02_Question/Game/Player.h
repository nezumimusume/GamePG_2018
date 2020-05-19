#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();

	//ここからメンバ変数。
	prefab::CSkinModelRender* skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 position = g_vec3Zero;

};

