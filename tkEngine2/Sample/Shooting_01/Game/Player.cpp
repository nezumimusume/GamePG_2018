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


