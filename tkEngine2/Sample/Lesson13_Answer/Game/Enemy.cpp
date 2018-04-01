#include "stdafx.h"
#include "Enemy.h"
#include "Bullet.h"


Enemy::Enemy()
{
}
Enemy::~Enemy()
{
	DeleteGO(m_skinModelRender);
}
//////////////////////////////////////////////////////////
// ���߂�Update�֐����Ă΂�钼�O�ɁA��x�����Ă΂��֐��B
//////////////////////////////////////////////////////////
bool Enemy::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/enemy.cmo", nullptr, 0, CSkinModel::enFbxUpAxisY);
	//���f�����������̂łP�O�{����B
	CVector3 scale;
	scale.x = 10.0f;
	scale.y = 10.0f;
	scale.z = 10.0f;
	m_skinModelRender->SetScale(scale);
	//���������������̂�Y�������90����]������B
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
	//�X�L�����f���ɉ�]�N�H�[�^�j�I����ݒ肷��B
	m_skinModelRender->SetRotation(qRot);
	m_moveSpeed.x = 50.0f;
	return true;
}
//////////////////////////////////////////////////////////
// ���Ԋu�ŌĂ΂��X�V�����B
//////////////////////////////////////////////////////////
void Enemy::Update()
{
	m_position += m_moveSpeed;
	if (m_position.x < 7000.0f) {
		//�ړ�������ύX����B
		m_moveSpeed.x = 50.0f;
	}
	if (m_position.x > 9000.0f) {
		//�ړ�������ύX����B
		m_moveSpeed.x = -50.0f;
	}
	//�X�L�����f�������_�[�ɍ��W��`����B
	m_skinModelRender->SetPosition(m_position);
	//�^�C�}�[���C���N�������g�B
	m_timer++;
	if (m_timer == 10) {
		//�^�C�}�[��10�ɂȂ����̂ŁA�e�ۂ̃C���X�^���X�𐶐�����B
		Bullet* bullet = NewGO<Bullet>(0, "EnemyBullet");
		bullet->m_position = m_position;
		bullet->m_moveSpeed.x = -400.0f;
		//�^�C�}�[�����Z�b�g�B
		m_timer = 0.0f;
	}
	//PlayerBullet�Ƃ������O�̃Q�[���I�u�W�F�N�g�ɑ΂��ăN�G��(�₢���킹)���s���B
	QueryGOs<Bullet>("PlayerBullet", [&](Bullet* bullet)->bool {
		//�Q�_�Ԃ̋������v�Z����B
		CVector3 diff = bullet->m_position - m_position;
		if (diff.Length() < 500.0f) {	//������500�ȉ��ɂȂ�����B
			//���S�B
			prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
			ss->Init("sound/explosion.wav");	//explosion.wav�����[�h�B
			ss->SetVolume(0.05f);				//���邳���̂ŉ�������������B
			ss->Play(false);					//�����V���b�g�Đ��B
			//�G�t�F�N�g�̃C���X�^���X�̍쐬�B
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			effect->Play(L"effect/fire.efk");	//fire.efk���Đ��B
			effect->SetPosition(m_position);	//�G�t�F�N�g�̔����ʒu�Ƃ��ēG�@�̍��W��n���B
			
			DeleteGO(this);						//�������g�����S������B
			//false��Ԃ�����N�G���͏I���B
			return false;
		}
		//true��Ԃ�����N�G���͌p���B
		return true;
	});
}