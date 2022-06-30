#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet()
{
	modelRender.SetRaytracingWorld(false);
	modelRender.Init("Assets/modelData/star.tkm");
	sw = modelRender.GetStopWatch();
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	Move();

	modelRender.Update();

	Limit -= g_gameTime->GetFrameDeltaTime();
	if (Limit <= 0.0f) {
		DeleteGO(this);
	}

}

void Bullet::Move()
{
	position += moveSpeed;

	modelRender.SetPosition(position);
}

void Bullet::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}
