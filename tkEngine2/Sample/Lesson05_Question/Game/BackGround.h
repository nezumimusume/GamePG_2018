#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"

class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	bool Start();
	prefab::CSkinModelRender* skinModelRender = nullptr;	//スキンモデルレンダラー。

	//HandsOn1 静的物理オブジェクトをメインメモリに展開し保持させる。
	

};

