#include "stdafx.h"
#include "Player.h"
#include "Bullet.h"

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
	if (Pad(0).IsPress(enButtonRight)) {
		m_position.x += 200.0f;
	}
	if (Pad(0).IsPress(enButtonLeft)) {
		m_position.x -= 200.0f;
	}
	if (Pad(0).IsPress(enButtonUp)) {
		m_position.y += 200.0f;
		//Z軸周りの回転クォータニオンを作成。
		qRot.SetRotationDeg(CVector3::AxisZ, -10.0f);
	}
	if (Pad(0).IsPress(enButtonDown)) {
		m_position.y -= 200.0f;
		//Z軸周りの回転クォータニオンを作成。
		qRot.SetRotationDeg(CVector3::AxisZ, 10.0f);
	}
	//Y軸周りに-90°回す回転クォータニオンを作成する。
	CQuaternion qRot2;
	qRot2.SetRotationDeg(CVector3::AxisY, -90.0f);
	m_skinModelRenderer->SetRotation(qRot);

	//qRotとqRot2のクォータニオンを合成。
	qRot.Multiply(qRot2);

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
	m_skinModelRenderer->SetRotation(qRot);
}
//////////////////////////////////////////////////////////
// 一定間隔で呼ばれる更新処理。
//////////////////////////////////////////////////////////
void Player::Update()
{
	MoveAndRotation();		//プレイヤーの移動と回転処理はMove関数にまとめたよ。
	//タイマーをインクリメント。
	m_timer++;
	//Aボタンが押された、かつm_timerが2以上なら、
	//弾丸を生成する。
	if (Pad(0).IsPress(enButtonA) && m_timer >= 2 ) {
		//直進する弾丸を作成。
		Bullet* bullet = NewGO<Bullet>(0, "PlayerBullet");
		//弾丸の座標にプレイヤーの座標を代入する。
		bullet->m_position = m_position;
		//X軸方向に400の速度を設定する。
		bullet->m_moveSpeed.x = 400.0f;
		//斜め上に飛んでいく弾丸を作成。
		bullet = NewGO<Bullet>(0, "PlayerBullet");
		bullet->m_position = m_position;
		bullet->m_moveSpeed.x = 400.0f;
		bullet->m_moveSpeed.y = 200.0f;

		//斜め下に飛んでいく弾丸を作成。
		bullet = NewGO<Bullet>(0, "PlayerBullet");
		bullet->m_position = m_position;
		bullet->m_moveSpeed.x = 400.0f;
		bullet->m_moveSpeed.y = -200.0f;

		//タイマーをリセット。
		m_timer = 0;
	}

	//EnemyBulletという名前のゲームオブジェクトに対してクエリ(問い合わせ)を行う。
	QueryGOs<Bullet>("EnemyBullet", [&](Bullet* bullet)->bool {
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

			DeleteGO(this);
			//クエリ終了。
			return false;
		}
		return true;
	});
}