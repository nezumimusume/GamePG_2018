/*!
 *@brief	main.cpp
 */
#include "stdafx.h"
#include "Player.h"
#include "EnemyGenerator.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	srand((unsigned)time(NULL));
	//tkEngine2の初期化パラメータを設定する。
	SInitParam initParam;
	initParam.nCmdShow = nCmdShow;
	initParam.hInstance = hInstance;
	initParam.screenWidth = 1280;
	initParam.screenHeight = 720;
	initParam.frameBufferWidth = 1280;
	initParam.frameBufferHeight = 720;
	//影の設定。
	initParam.graphicsConfing.shadowRenderConfig.isEnable = true;
	initParam.graphicsConfing.shadowRenderConfig.shadowMapWidth = 1024;
	initParam.graphicsConfing.shadowRenderConfig.shadowMapHeight = 1024;
	initParam.graphicsConfing.shadowRenderConfig.softShadowLevel = EnSoftShadowQualityLevel::eSSSS_PCF;
	//アンチ
	initParam.graphicsConfing.aaConfig.isEnable = false;
	//Bloom
	initParam.graphicsConfing.bloomConfig.isEnable = true;
	//tonemap
	initParam.graphicsConfing.tonemapConfig.isEnable = true;
	initParam.graphicsConfing.tonemapConfig.luminance = 0.8f;
	GraphicsEngine().GetShadowMap().SetFar(1000.0f);
	GraphicsEngine().GetShadowMap().SetNear(50.0f);


	//エンジンを初期化。
	if (Engine().Init(initParam) == true) {
		//カメラを初期化。
		MainCamera().SetTarget({ 0.0f, 0.0f, 0.0f });
		MainCamera().SetNear(0.1f);
		MainCamera().SetFar(15000.0f);
		MainCamera().SetPosition({ 0.0f, 0.0f, -10000.0f });
		MainCamera().SetUpdateProjMatrixFunc(CCamera::enUpdateProjMatrixFunc_Ortho);
		MainCamera().SetWidth(20000.0f);
		MainCamera().SetHeight(20000.0f * 9.0f / 16.0f);
		MainCamera().Update();

		//敵機生成器のインスタンスを作成する。
		NewGO<EnemyGenerator>(0);
		//プレイヤーのインスタンスを作成。
		NewGO<Player>(0);

		//ゲームループを実行。
		Engine().RunGameLoop();
	}
	//エンジンの終了処理。
	Engine().Final();

	return 0;
}

