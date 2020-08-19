#pragma once
class GameOver2D : public IGameObject
{
public:
	GameOver2D();
	~GameOver2D();
	bool Start();
	//IGameObjectのUpdate関数をオーバーライドする。
	void Update();
	//オーバーライドとは子クラスで親クラスのメソッドを再定義すること

	prefab::CSpriteRender* m_spriteRender = nullptr;	//Spriteレンダラー。

};

