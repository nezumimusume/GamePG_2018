#pragma once
class TitleScene : public IGameObject // IGameObjectを継承
{
public:
	TitleScene();
	~TitleScene();
	//IGameObjectのStart関数をオーバーライドする。
	bool Start();
	//IGameObjectのUpdate関数をオーバーライドする。
	void Update();
	//オーバーライドとは子クラスで親クラスのメソッドを再定義するこ
	//スプライトレンダラー
	prefab::CSpriteRender* m_spriteRender = nullptr;

};

