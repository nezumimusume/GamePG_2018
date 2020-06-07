#pragma once 
class Player;
class Star : public IGameObject
{
public:
    ~Star();
    bool Start();
    void Update();
////////////////////////////////////////////////////
//メンバ変数
////////////////////////////////////////////////////

    //prefab::CSkinModelRender*型のメンバ変数を追加。 
    prefab::CSkinModelRender* skinModelRender = nullptr;

    CVector3 position;    //スターの座標（位置）。
    float angle = 0.0f;    //回転角度。 
    Player* player = nullptr; //キャラクターの情報。
    int moveCount = 0;        //スターを上下に動かすためのカウント。
};
