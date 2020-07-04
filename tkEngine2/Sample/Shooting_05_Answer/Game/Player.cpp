#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

//////////////////////////////////////////////////////////
// �R���X�g���N�^�B�C���X�^���X�����������Ƃ��ɌĂ΂�鏈���B
//////////////////////////////////////////////////////////
Player::Player()
{
}
//////////////////////////////////////////////////////////
// �f�X�g���N�^�B�C���X�^���X���j�������Ƃ��ɌĂ΂�鏈���B
//////////////////////////////////////////////////////////
Player::~Player()
{
	//�X�L�����f�������_���[��j��
	DeleteGO(m_skinModelRender);
}
//////////////////////////////////////////////////////////
// ���߂�Update�֐����Ă΂�钼�O�ɁA��x�����Ă΂��֐��B
//////////////////////////////////////////////////////////
bool Player::Start()
{
	//�X�L�����f�������_���[���쐬�B
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/AirPlane.cmo", NULL, 0, CSkinModel::enFbxUpAxisY);
	//���������������̂ŁAY�������-90���񂷁B
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, -90.0f);
	m_skinModelRender->SetRotation(qRot);

	return true;
}

void Player::MoveAndRotation() {
	CQuaternion qRot1;
	if (g_pad[0]->IsPress(enButtonRight)) {
		m_position.x += 100.0f;
	}
	if (g_pad[0]->IsPress(enButtonLeft)) {
		m_position.x -= 100.0f;
	}
	if (g_pad[0]->IsPress(enButtonUp)) {
		m_position.y += 100.0f;
		//Z������̉�]�N�H�[�^�j�I�����쐬�B
		qRot1.SetRotationDeg(g_vec3AxisZ, -20.0f);

	}
	if (g_pad[0]->IsPress(enButtonDown)) {
		m_position.y -= 100.0f;
		//Z������̉�]�N�H�[�^�j�I�����쐬�B
		qRot1.SetRotationDeg(g_vec3AxisZ, 20.0f);
	}
	

	//Y�������-90���񂷉�]�N�H�[�^�j�I�����쐬����B
	CQuaternion qRot2;
	qRot2.SetRotationDeg(g_vec3AxisY, -90.0f);
	m_skinModelRender->SetRotation(qRot1);

	//qRot1��qRot2�̃N�H�[�^�j�I���������B
	qRot1.Multiply(qRot2);

	//������m_position.x��9500�����傫���Ȃ�����B
	if (m_position.x > 9500.0f) {
		//9500.0f��������B
		m_position.x = 9500.0f;
	}
	//������m_position.x��-8500�����������Ȃ�����B
	if (m_position.x < -8500.0f) {
		//-8500.0f��������B
		m_position.x = -8500.0f;
	}
	//������m_position.y��5000�����傫���Ȃ�����B
	if (m_position.y > 5000.0f) {
		//5000.0f��������B
		m_position.y = 5000.0f;
	}
	//������m_position.y��-5000�����������Ȃ�����B
	if (m_position.y < -5000.0f) {
		//-5000.0f��������B
		m_position.y = -5000.0f;
	}

	//���W���X�L�����f�������_���[�ɔ��f������B
	m_skinModelRender->SetPosition(m_position);
	//��]���X�L�����f�������_���[�ɔ��f������B
	m_skinModelRender->SetRotation(qRot1);

}


//////////////////////////////////////////////////////////
// ���Ԋu�ŌĂ΂��X�V�����B
//////////////////////////////////////////////////////////
void Player::Update()
{
	//�v���C���[�̈ړ��Ɖ�]������MoveAndRotation�֐��ɂ܂Ƃ߂���B
	MoveAndRotation();
	//�^�C�}�[���C���N�������g�B
	m_timer++;
	//A�{�^���������ꂽ�A����m_timer��20�ȏ�Ȃ�A
	//�e�ۂ𐶐�����B
	if (g_pad[0]->IsPress(enButtonA) && m_timer >= 20) {
		//���i����e�ۂ��쐬�B
		Bullet* bullet = NewGO<Bullet>(0, "PlayerBullet");
		//�e�ۂ̍��W�Ƀv���C���[�̍��W��������B
		bullet->m_position = m_position;
		//X��������200�̑��x��ݒ肷��B
		bullet->m_moveSpeed.x = 200.0f;

		//�΂ߏ�ɐi�ޒe�ۂ��쐬�B
		bullet = NewGO<Bullet>(0, "PlayerBullet");
		//�e�ۂ̍��W�Ƀv���C���[�̍��W��������B
		bullet->m_position = m_position;
		//X��������200�̑��x��ݒ肷��B
		bullet->m_moveSpeed.x = 200.0f;
		bullet->m_moveSpeed.y = 100.0f;

		//�΂߉��ɐi�ޒe�ۂ��쐬�B
		bullet = NewGO<Bullet>(0, "PlayerBullet");
		//�e�ۂ̍��W�Ƀv���C���[�̍��W��������B
		bullet->m_position = m_position;
		//X��������200�̑��x��ݒ肷��B
		bullet->m_moveSpeed.x = 200.0f;
		bullet->m_moveSpeed.y = -100.0f;

		m_timer = 0;
	}

	//PlayerBullet�Ƃ������O�̃Q�[���I�u�W�F�N�g�ɑ΂��ăN�G��(�₢���킹)���s���B
	QueryGOs<Bullet>("EnemyBullet", [&](Bullet* bullet) {
		//�Q�_�Ԃ̋������v�Z����B
		CVector3 diff = bullet->m_position - m_position;
		if (diff.Length() < 500.0f) {	//������500�ȉ��ɂȂ�����B
			//���S�B
			prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
			ss->Init("sound/explosion.wav");	//explosion.wav�����[�h�B
			ss->SetVolume(0.2f);				//���邳���̂ŉ�������������B
			ss->Play(false);					//�����V���b�g�Đ��B

			//�G�t�F�N�g�̃C���X�^���X�̍쐬�B
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			effect->Play(L"effect/fire.efk");	//fire.efk���Đ��B
			effect->SetPosition(m_position);	//�G�t�F�N�g�̔����ʒu�Ƃ��ēG�@�̍��W��n���B

			DeleteGO(this);
			//false��Ԃ�����N�G��(�₢���킹)�͏I���B
			return false;
		}
		//true��Ԃ�����N�G��(�₢���킹)�͌p���B
		return true;
		});

}
