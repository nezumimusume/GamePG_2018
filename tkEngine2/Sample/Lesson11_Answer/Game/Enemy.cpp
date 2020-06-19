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
// 初めてUpdate関数が呼ばれる直前に、一度だけ呼ばれる関数。
//////////////////////////////////////////////////////////
bool Enemy::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/enemy.cmo", nullptr, 0, CSkinModel::enFbxUpAxisY);
	//モデルが小さいので１０倍する。
	CVector3 scale;
	scale.x = 10.0f;
	scale.y = 10.0f;
	scale.z = 10.0f;
	m_skinModelRender->SetScale(scale);
	//横を向かせたいのでY軸周りに90°回転させる。
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, 90.0f);
	//スキンモデルに回転クォータニオンを設定する。
	m_skinModelRender->SetRotation(qRot);
	m_moveSpeed.x = 50.0f;
	return true;
}
//////////////////////////////////////////////////////////
// 一定間隔で呼ばれる更新処理。
//////////////////////////////////////////////////////////
void Enemy::Update()
{
	m_position += m_moveSpeed;
	if (m_position.x < 7000.0f) {
		//移動方向を変更する。
		m_moveSpeed.x = 50.0f;
	}
	if (m_position.x > 9000.0f) {
		//移動方向を変更する。
		m_moveSpeed.x = -50.0f;
	}
	//スキンモデルレンダーに座標を伝える。
	m_skinModelRender->SetPosition(m_position);
}