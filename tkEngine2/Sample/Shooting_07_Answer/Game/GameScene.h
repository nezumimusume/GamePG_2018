#pragma once
class GameScene : public IGameObject    // IGameObjectを継承
{
public:
	GameScene();
	~GameScene();
	//IGameObjectのStart関数をオーバーライドする。
	bool Start();
	//IGameObjectのUpdate関数をオーバーライドする。
	void Update();
	//オーバーライドとは子クラスで親クラスのメソッドを再定義すること
};

