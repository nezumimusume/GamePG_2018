/*!
 *@brief	main.cpp
 */
#include "stdafx.h"
#include "Player.h"



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//エンジンを使うおまじない。
	CEngine::Boot();

	srand((unsigned)time(NULL));
	//tkEngine2の初期化パラメータを設定する。
	SInitParam initParam;
	initParam.nCmdShow = nCmdShow;
	initParam.hInstance = hInstance;
	initParam.screenWidth =  1280;
	initParam.screenHeight =  720;
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

	g_engine->SetShadowMapFar(1000.0f);
	g_engine->SetShadowMapNear(50.0f);

	

	//エンジンを初期化。
	if (g_engine->Init(initParam) == true) {

		//カメラを初期化。
		CVector3 target;
		target.x = 0.0f;
		target.y = 0.0f;
		target.z = 0.0f;
		CVector3 pos;
		pos.x = 0.0f;
		pos.y = 0.0f;
		pos.z = -10000.0f;

		g_camera3D->SetTarget( target );
		g_camera3D->SetNear( 0.1f );
		g_camera3D->SetFar( 15000.0f );
		g_camera3D->SetPosition( pos );
		g_camera3D->SetUpdateProjMatrixFunc(CCamera::enUpdateProjMatrixFunc_Ortho);
		g_camera3D->SetWidth(20000.0f);
		g_camera3D->SetHeight(20000.0f * 9.0f / 16.0f);
		g_camera3D->Update();


		//プレイヤーのインスタンスを作成。
		NewGO<Player>(0);

		//敵機生成器のインスタンスを作成する。
		

		//ゲームループを実行。
		g_engine->RunGameLoop();
	}
	//エンジンの終了処理。
	g_engine->Final();
	return 0;
}

