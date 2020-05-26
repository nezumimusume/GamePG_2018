#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
}
Game::~Game()
{
	DeleteGO(m_player);
	DeleteGO(m_directionLight);
}
bool Game::Start()
{
	//ƒJƒƒ‰‚ğİ’èB
	MainCamera().SetTarget({ 0.0f, 100.0f, 0.0f });
	MainCamera().SetNear(0.1f);
	MainCamera().SetFar(3000.0f);
	MainCamera().SetPosition({ 0.0f, 100.0f, -300.0f });
	MainCamera().Update();

	m_player = NewGO<Player>(0);
	m_backGround = NewGO<BackGround>(0);
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