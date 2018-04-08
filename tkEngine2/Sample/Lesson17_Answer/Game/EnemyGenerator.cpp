#include "stdafx.h"
#include "EnemyGenerator.h"
#include "Enemy.h"

EnemyGenerator::EnemyGenerator()
{
}


EnemyGenerator::~EnemyGenerator()
{
}

void EnemyGenerator::Update()
{
	m_timer++;
	if (m_timer == 60) {
		//60フレームごとに敵機を作成する。
		Enemy* enemy = NewGO<Enemy>(0, "Enemy");
		//X座標は画面際にする。
		enemy->m_position.x = 9000.0f;
		//Y座標をランダムにする。
		//GetRandDoubleは0.0～1.をランダムに返してくる関数。
		float t = Random().GetRandDouble();
		//CMath::Leap関数は二つの値の間を線形補完する関数。
		enemy->m_position.y = CMath::Lerp(t, -5625.0f, 5625.0f);
		m_timer = 0;
	}
}