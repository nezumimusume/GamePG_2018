#pragma once
class GameOver2D : public IGameObject
{
public:
	GameOver2D();
	~GameOver2D();
	bool Start();
	void Update();
	prefab::CSpriteRender* m_spriteRender = nullptr;	//SpriteƒŒƒ“ƒ_ƒ‰[B
};

