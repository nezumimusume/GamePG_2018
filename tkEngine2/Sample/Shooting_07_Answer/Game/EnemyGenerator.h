#pragma once
class EnemyGenerator : public IGameObject
{
public:
	EnemyGenerator();
	~EnemyGenerator();
	void Update();
	bool Start();
	///////////////////////////////
	// ここからメンバ変数
	///////////////////////////////
	int m_timer = 0;		//タイマー。
};


