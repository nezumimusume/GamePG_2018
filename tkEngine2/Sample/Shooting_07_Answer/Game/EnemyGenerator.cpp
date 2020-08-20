#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"

// コンストラクタ。インスタンスが生成されるときに呼ばれる処理。
EnemyGenerator::EnemyGenerator()
{
}
// デストラクタ。インスタンスが破棄されるときに呼ばれる処理。
EnemyGenerator::~EnemyGenerator()
{
	//敵を削除。
	QueryGOs<Enemy>("Enemy", [](Enemy* enemy)->bool
		{
			DeleteGO(enemy);
			return true;
		});
	//BGMを削除。おまけです。
	prefab::CSoundSource* bgm = FindGO<prefab::CSoundSource>("BGM");
	DeleteGO(bgm);
}
bool EnemyGenerator::Start()
{
	TK_LOG("Start EnemyGenerator");
	return true;
}

void EnemyGenerator::Update()
{
	m_timer++;
	if (m_timer == 60) {
		m_timer = 0; //タイマーをリセット。
	   //60フレームごとに敵機を作成する。
		Enemy* enemy = NewGO<Enemy>(0, "Enemy");
		//X座標は画面際にする。
		enemy->m_position.x = 9000.0f;
		//Y座標をランダムにする。
		//GetRandDoubleは0.0～1.0をランダムに返してくる関数。
		float t = g_random->GetRandDouble();
		//CMath::Leap関数は二つの値の間を線形補完する関数。
		enemy->m_position.y = CMath::Lerp(t, -5000.0f, 5000.0f);

	}
	
}
