#pragma once
class Bullet : public IGameObject
{
public:
	Bullet();
	~Bullet();
	//更新処理。
	void Update();
	//描画処理。
	void Render(RenderContext& rc);
	//移動処理。
	void Move();

	//メンバ変数。
	ModelRender modelRender;	//モデルレンダ―。
	Vector3 position;		//座標。
	Vector3 moveSpeed = Vector3::Zero;
	Stopwatch* sw = nullptr;

	float Limit = 120.0f;
};
