#pragma once

class Player;
class TestObject : public IGameObject
{
public:
	TestObject();
	~TestObject();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);

	enum EnAnimationClip {		//アニメーション。
		enAnimationClip_Idle,
		enAnimationClip_Open,
		enAnimationClip_Num
	};
	AnimationClip animationClips[enAnimationClip_Num];		//アニメーションクリップ。

	//メンバ変数。
	ModelRender modelRender;	//モデルレンダ―。
	Vector3 position;		//座標。
	Player* m_player;

};

