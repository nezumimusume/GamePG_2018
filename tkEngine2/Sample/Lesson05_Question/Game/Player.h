#pragma once
#include "tkEngine/character/tkCharacterController.h"

class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();
	void Rotation();
	void AnimationControl();
	//�������烁���o�ϐ��B
	enum {
		enAnimationClip_idle,
		enAnimationClip_run,
		enAnimationClip_jump,
		enAnimationClip_num,
	};
	prefab::CSkinModelRender* skinModelRender = nullptr;	//�X�L�����f�������_���[�B
	CAnimationClip animationClips[enAnimationClip_num];		//�A�j���[�V�����N���b�v�B

	
	CVector3 position = CVector3::Zero;
	CQuaternion rotation = CQuaternion::Identity;
	//HandsOn 3 Player�N���X��CCharacterController�̃C���X�^���X��ێ�������B
	

	CVector3 moveSpeed = CVector3::Zero;
};
