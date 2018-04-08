#pragma once
class GameScene : public IGameObject
{
public:
	GameScene();
	~GameScene();
	//IGameObjectのStart関数をオーバーライドする。
	bool Start();
	//IGameObjectのUpdate関数をオーバーライドする。
	void Update();
};

