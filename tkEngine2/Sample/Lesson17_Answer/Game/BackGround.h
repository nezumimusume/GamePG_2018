#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	bool Start();
	prefab::CSpriteRender* m_spriteRender = nullptr;
};

