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
	DeleteGO(m_skinModelRender);
}
//////////////////////////////////////////////////////////
// 初めてUpdate関数が呼ばれる直前に、一度だけ呼ばれる関数。
//////////////////////////////////////////////////////////
bool Player::Start()
{
	//スキンモデルレンダラーを作成。
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/AirPlane.cmo", NULL, 0, CSkinModel::enFbxUpAxisY);
	//横を向かせたいので、Y軸周りに-90°回す。
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, -90.0f);
	m_skinModelRender->SetRotation(qRot);

	return true;
}

void Player::MoveAndRotation() {
	CQuaternion qRot1;
	if (g_pad[0]->IsPress(enButtonRight)) {
		m_position.x += 200.0f;
	}
	if (g_pad[0]->IsPress(enButtonLeft)) {
		m_position.x -= 200.0f;
	}
	if (g_pad[0]->IsPress(enButtonUp)) {
		m_position.y += 200.0f;
		//Z軸周りの回転クォータニオンを作成。
		qRot1.SetRotationDeg(g_vec3AxisZ, -20.0f);

	}
	if (g_pad[0]->IsPress(enButtonDown)) {
		m_position.y -= 200.0f;
		//Z軸周りの回転クォータニオンを作成。
		qRot1.SetRotationDeg(g_vec3AxisZ, 20.0f);
	}
	

	//Y軸周りに-90°回す回転クォータニオンを作成する。
	CQuaternion qRot2;
	qRot2.SetRotationDeg(g_vec3AxisY, -90.0f);
	m_skinModelRender->SetRotation(qRot1);

	//qRot1とqRot2のクォータニオンを合成。
	qRot1.Multiply(qRot2);

	//もしもm_position.xが9500よりも大きくなったら。
	if (m_position.x > 9500.0f) {
		//9500.0fを代入する。
		m_position.x = 9500.0f;
	}
	//もしもm_position.xが-8500よりも小さくなったら。
	if (m_position.x < -8500.0f) {
		//-8500.0fを代入する。
		m_position.x = -8500.0f;
	}
	//もしもm_position.yが5000よりも大きくなったら。
	if (m_position.y > 5000.0f) {
		//5000.0fを代入する。
		m_position.y = 5000.0f;
	}
	//もしもm_position.yが-5000よりも小さくなったら。
	if (m_position.y < -5000.0f) {
		//-5000.0fを代入する。
		m_position.y = -5000.0f;
	}

	//座標をスキンモデルレンダラーに反映させる。
	m_skinModelRender->SetPosition(m_position);
	//回転をスキンモデルレンダラーに反映させる。
	m_skinModelRender->SetRotation(qRot1);

}


//////////////////////////////////////////////////////////
// 一定間隔で呼ばれる更新処理。
//////////////////////////////////////////////////////////
void Player::Update()
{
	MoveAndRotation();


}
