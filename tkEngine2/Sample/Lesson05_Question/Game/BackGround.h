#pragma once
#include "tkEngine/physics/tkPhysicsStaticObject.h"

class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	bool Start();
	prefab::CSkinModelRender* skinModelRender = nullptr;	//�X�L�����f�������_���[�B

	//HandsOn 1 Backgroud�N���X��CPhysicsStaticObject�̃C���X�^���X��ێ�������B
	
};
