#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"

class Player;
class BackGround;
class GameCamera;
//class Star;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void Render(CRenderContext& rc);

	Player* m_player = nullptr;
	BackGround* m_backGround = nullptr;
	GameCamera* m_gameCamera = nullptr;
	prefab::CDirectionLight* m_directionLight = nullptr;
	//std::vector<Star*> m_starList;
};

