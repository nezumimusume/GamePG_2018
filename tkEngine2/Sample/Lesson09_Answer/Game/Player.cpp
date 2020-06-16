#include "stdafx.h"
#include "Player.h"

//////////////////////////////////////////////////////////
// コンストラクタ。インスタンスが生成されるときに呼ばれる処理。
//////////////////////////////////////////////////////////
Player::Player()
{
}
//////////////////////////////////////////////////////////
// デストラクタ。インスタンスが破棄されるときに呼ばれる処理。
//////////////////////////////////////////////////////////
Player::~Player()
{
	//スキンモデルレンダラーを破棄
	DeleteGO(m_skinModelRenderer);
}
//////////////////////////////////////////////////////////
// 初めてUpdate関数が呼ばれる直前に、一度だけ呼ばれる関数。
//////////////////////////////////////////////////////////
bool Player::Start()
{
	//スキンモデルレンダラーを作成。
	m_skinModelRenderer = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRenderer->Init(L"modelData/AirPlane.cmo", NULL, 0, CSkinModel::enFbxUpAxisY);

	return true;
}
void Player::MoveAndRotation()
{
	CQuaternion qRot = CQuaternion::Identity;
	if (g_pad[0]->IsPress(enButtonRight)) {
		m_position.x += 200.0f;
	}
	if (g_pad[0]->IsPress(enButtonLeft)) {
		m_position.x -= 200.0f;
	}
	if (g_pad[0]->IsPress(enButtonUp)) {
		m_position.y += 200.0f;
		//Z軸周りの回転クォータニオンを作成。
		//qRot.SetRotationDeg(g_vec3AxisZ, -10.0f);
	}
	if (g_pad[0]->IsPress(enButtonDown)) {
		m_position.y -= 200.0f;
		//Z軸周りの回転クォータニオンを作成。
		//qRot.SetRotationDeg(g_vec3AxisZ, 10.0f);
	}
	//Y軸周りに-90°回す回転クォータニオンを作成する。
	CQuaternion qRot2;
	qRot2.SetRotationDeg(g_vec3AxisY, -90.0f);
	m_skinModelRenderer->SetRotation(qRot2);

	//qRotとqRot2のクォータニオンを合成。
	//qRot.Multiply(qRot2);

	//もしもm_position.xが10000よりも大きくなったら。
	if (m_position.x > 10000.0f) {
		//10000.0fを代入する。
		m_position.x = 10000.0f;
	}
	//もしもm_position.xが150よりも小さくなったら。
	if (m_position.x < -10000.0f) {
		//-20000.0fを代入する。
		m_position.x = -10000.0f;
	}

	//もしもm_position.yが10000よりも大きくなったら。
	if (m_position.y > 5625.0f) {
		//10000.0fを代入する。
		m_position.y = 5625.0f;
	}
	//もしもm_position.xが150よりも小さくなったら。
	if (m_position.y < -5625.0f) {
		//-20000.0fを代入する。
		m_position.y = -5625.0f;
	}

	//座標をスキンモデルレンダラーに反映させる。
	m_skinModelRenderer->SetPosition(m_position);
	//回転をスキンモデルレンダラーに反映させる。
	//m_skinModelRenderer->SetRotation(qRot);
}
//////////////////////////////////////////////////////////
// 一定間隔で呼ばれる更新処理。
//////////////////////////////////////////////////////////
void Player::Update()
{
	MoveAndRotation();	//プレイヤーの移動と回転処理はMove関数にまとめたよ。
}