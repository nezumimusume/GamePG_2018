#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Star.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
}
Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_directionLight);
	DeleteGO(m_gameCamera);
	for (auto star : m_starList) {
		DeleteGO(star);
	}
}
bool Game::Start()
{
	//カメラを設定。
	MainCamera().SetTarget({ 0.0f, 100.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(3000.0f);
	MainCamera().SetPosition({ 0.0f, 500.0f, -600.0f });
	MainCamera().Update();

	m_player = NewGO<Player>(0, "UnityChan");
	m_backGround = NewGO<BackGround>(0);
	m_gameCamera = NewGO<GameCamera>(0);

	m_directionLight = NewGO<prefab::CDirectionLight>(0);
	CVector3 lightDir = { 0.0f, -0.707, 0.707 };
	lightDir.Normalize();
	m_directionLight->SetDirection(lightDir);
	m_directionLight->SetColor({ 1.0f, 1.0f, 1.0f, 1.0f } );

	GraphicsEngine().GetShadowMap().SetLightDirection(lightDir);

	//星を配置。
	CLocData locData;
	locData.Load(L"loc/star.tks"); //配置情報をロード。
	for (int i = 0; i < locData.GetNumObject(); i++) {
		//星を一つづつ作成していく。
		CQuaternion qRot;
		qRot.SetRotationDeg(g_vec3AxisY, 180.0f);
		auto star = NewGO<Star>(0);
		star->position = locData.GetObjectPosition(i);
		qRot.Multiply(star->position);
		m_starList.push_back(star);
	}
	return true;
}
void Game::Update()
{
}
void Game::Render(CRenderContext& rc)
{
}