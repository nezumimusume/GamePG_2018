#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"

class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	bool Start();
	prefab::CSkinModelRender* skinModelRender = nullptr;	//スキンモデルレンダラー。

	//BackgroudクラスにCPhysicsStaticObjectのインスタンスを保持させる。
	CPhysicsStaticObject m_physicsStaticObject;				//静的物理オブジェクト。
};

