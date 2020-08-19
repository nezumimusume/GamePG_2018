#include "stdafx.h"
#include "GameScene.h"
#include "Player.h"
#include "EnemyGenerator.h"
#include "BackGround.h"
#include "Enemy.h"
#include "GameOver2D.h"
#include "Bullet.h"

GameScene::GameScene()
{
}
GameScene::~GameScene()
{
	//背景を削除。
	BackGround* bg = FindGO<BackGround>("BackGround");
	DeleteGO(bg);

	//プレイヤーを削除。
	Player* pl = FindGO<Player>("Player");
	DeleteGO(pl);
	
	//敵機生成器を削除。
	EnemyGenerator* enemyGenerator = FindGO<EnemyGenerator>("EnemyGenerator");
	DeleteGO(enemyGenerator);


	//BGMを削除。
	prefab::CSoundSource* bgm = FindGO<prefab::CSoundSource>("BGM");
	DeleteGO(bgm);

	//プレイヤーの弾丸を削除
	QueryGOs<Bullet>("PlayerBullet", [](Bullet* bullet)->bool
		{
			DeleteGO(bullet);
			return true;
		});

	//敵機の弾丸を削除。
	QueryGOs<Bullet>("EnemyBullet", [](Bullet* bullet)->bool
		{
			DeleteGO(bullet);
			return true;
		});

	//敵を削除。
	QueryGOs<Enemy>("Enemy", [](Enemy* enemy)->bool
		{
			DeleteGO(enemy);
			return true;
		});

	//GameOver2Dを削除。
	DeleteGO(FindGO<GameOver2D>("GameOver2D"));

}
bool GameScene::Start()
{
	//カメラを初期化。
	CVector3 target;
	target.x = 0.0f;
	target.y = 0.0f;
	target.z = 0.0f;
	CVector3 pos;
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = -10000.0f;
	g_camera3D->SetTarget(target);
	g_camera3D->SetNear(0.1f);
	g_camera3D->SetFar(15000.0f);
	g_camera3D->SetPosition(pos);
	g_camera3D->SetUpdateProjMatrixFunc(CCamera::enUpdateProjMatrixFunc_Ortho);
	g_camera3D->SetWidth(20000.0f);
	g_camera3D->SetHeight(20000.0f * 9.0f / 16.0f);
	g_camera3D->Update();
	//敵機生成器のインスタンスを作成する。
	NewGO<EnemyGenerator>(0, "EnemyGenerator");
	//背景のインスタンスを作成する。
	NewGO<BackGround>(0, "BackGround");
	//プレイヤーのインスタンスを作成。
	NewGO<Player>(0, "Player");
	//BGMを再生
	prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0, "BGM");
	ss->Init("sound/bgm.wav");
	ss->SetVolume(0.03f);
	ss->Play(true);
	return true;
}
void GameScene::Update()
{
}
