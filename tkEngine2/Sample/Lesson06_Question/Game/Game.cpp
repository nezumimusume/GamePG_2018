#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"

// HandsOn1　Starクラスの機能を使いたいのでヘッダーファイルをインクルードする


#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
}
Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_directionLight);
	DeleteGO(m_gameCamera);
}
bool Game::Start()
{
	//カメラを設定。
	g_camera3D->SetTarget({ 0.0f, 100.0f, 0.0f });
	g_camera3D->SetNear(0.1f);
	g_camera3D->SetFar(3000.0f);
	g_camera3D->SetPosition({ 0.0f, 500.0f, -600.0f });
	g_camera3D->Update();

	m_player = NewGO<Player>(0, "UnityChan");
	m_backGround = NewGO<BackGround>(0);
	m_gameCamera = NewGO<GameCamera>(0);
	
	//HandsOn2　Starクラスのオブジェクトを作成
	

	m_directionLight = NewGO<prefab::CDirectionLight>(0);
	CVector3 lightDir = { 0.0f, -0.707, 0.707 };
	lightDir.Normalize();
	m_directionLight->SetDirection(lightDir);
	m_directionLight->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f } );

	GraphicsEngine().GetShadowMap().SetLightDirection(lightDir);

	return true;
}
void Game::Update()
{
}
void Game::Render(CRenderContext& rc)
{
}