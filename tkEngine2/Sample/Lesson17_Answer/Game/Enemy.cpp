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
	qRot.SetRotationDeg(CVector3::AxisY, 90.0f);
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
	//タイマーをインクリメント。
	m_timer++;
	if (m_timer == 10) {
		//タイマーが10になったので、弾丸のインスタンスを生成する。
		Bullet* bullet = NewGO<Bullet>(0, "EnemyBullet");
		bullet->m_position = m_position;
		bullet->m_moveSpeed.x = -400.0f;
		//タイマーをリセット。
		m_timer = 0.0f;
	}
	//PlayerBulletという名前のゲームオブジェクトに対してクエリ(問い合わせ)を行う。
	QueryGOs<Bullet>("PlayerBullet", [&](Bullet* bullet)->bool {
		//２点間の距離を計算する。
		CVector3 diff = bullet->m_position - m_position;
		if (diff.Length() < 500.0f) {	//距離が500以下になったら。
			//死亡。
			prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
			ss->Init("sound/explosion.wav");	//explosion.wavをロード。
			ss->SetVolume(0.05f);				//うるさいので音を小さくする。
			ss->Play(false);					//ワンショット再生。
			//エフェクトのインスタンスの作成。
			prefab::CEffect* effect = NewGO<prefab::CEffect>(0);
			effect->Play(L"effect/fire.efk");	//fire.efkを再生。
			effect->SetPosition(m_position);	//エフェクトの発生位置として敵機の座標を渡す。
			
			DeleteGO(this);						//自分自身を死亡させる。
			//falseを返したらクエリは終了。
			return false;
		}
		//trueを返したらクエリは継続。
		return true;
	});
}