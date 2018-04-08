#pragma once
class TitleScene : public IGameObject
{
public:
	TitleScene();
	~TitleScene();
	//IGameObjectのStart関数をオーバーライドする。
	bool Start();
	//IGameObjectのUpdate関数をオーバーライドする。
	void Update();
	//スプライトレンダラー。
	prefab::CSpriteRender* m_spriteRender = nullptr;
};

