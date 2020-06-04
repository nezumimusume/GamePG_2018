#pragma once
class Player;

class Star : public IGameObject
{
public:
	~Star();
	bool Start();
	void Update();
	//HandsOn 1 prefab::CSkinModelRender*Œ^‚Ìƒƒ“ƒo•Ï”‚ğ’Ç‰ÁB
	prefab::CSkinModelRender* skinModelRender = nullptr;
	CVector3 position ;
	float angle = 0.0f;	//‰ñ“]Šp“xB
	Player* player = nullptr;
	int moveCount = 0;
	
};

