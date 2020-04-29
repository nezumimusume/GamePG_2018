#pragma once
class Player : public IGameObject
{
public:
	bool Start();
	void Update();
	//ここからメンバ変数。
	prefab::CSkinModelRender* skinModelRender = nullptr;	//スキンモデルレンダラー。
	//Hands-On 1 座標データを追加する。
	
};

