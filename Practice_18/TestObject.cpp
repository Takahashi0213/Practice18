#include "stdafx.h"
#include "TestObject.h"
#include "Player.h"

TestObject::TestObject()
{
	//☆のモデルを読み込む。
	//modelRender.Init("Assets/modelData/Food/Sushi.tkm");
	//modelRender.SetScale({ 50.0f,50.0f,50.0f });

	//アニメーションクリップをロードする。
	//animationClips[enAnimationClip_Idle].Load("Assets/animData/BreakBoxAnim/BB_Idle.tka");
	//animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	//animationClips[enAnimationClip_Open].Load("Assets/animData/BreakBoxAnim/BB_Break.tka");
	//animationClips[enAnimationClip_Open].SetLoopFlag(false);
	////ユニティちゃんのモデルを読み込む。
	//modelRender.Init("Assets/modelData/BreakBox/BreakBox.tkm", animationClips, enAnimationClip_Num, enModelUpAxisZ);
	//modelRender.SetPosition({ 0.0f,-80.0f,0.0f });
	//modelRender.SetScale({ 5.0f,5.0f,5.0f });
	//modelRender.PlayAnimation(enAnimationClip_Idle);

	//modelRender.Init("Assets/modelData/SpaceShip/SpaceShip.tkm");

	//modelRender.SetScale({ 10.0f,10.0f,10.0f });

	m_player = FindGO<Player>("player");
}

TestObject::~TestObject()
{

}

void TestObject::Update()
{
	//プレイヤーから☆に向かうベクトルを計算。
	Vector3 diff = m_player->position - position;
	//ベクトルの長さが120.0fより小さかったら。
	if (diff.Length() <= 120.0f && g_pad[0]->IsTrigger(enButtonB))
	{
		//modelRender.PlayAnimation(enAnimationClip_Open);
	}

	//絵描きさんの更新処理。
	modelRender.Update();
}

void TestObject::Render(RenderContext& rc)
{
	//☆を描画する。
	modelRender.Draw(rc);
}