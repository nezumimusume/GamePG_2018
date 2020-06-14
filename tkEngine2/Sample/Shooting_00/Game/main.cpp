/*!
 *@brief	main.cpp
 */
#include "stdafx.h"


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
		g_camera3D->SetTarget({ 0.0f, 0.0f, 0.0f });
		g_camera3D->SetNear(0.1f);
		g_camera3D->SetFar(15000.0f);
		g_camera3D->SetPosition({ 0.0f, 0.0f, -10000.0f });
		g_camera3D->Update();

		//プレイヤーのインスタンスを作成。
		

		//ゲームループを実行。
		Engine().RunGameLoop();
	}
	//エンジンの終了処理。
	Engine().Final();
	return 0;
}

