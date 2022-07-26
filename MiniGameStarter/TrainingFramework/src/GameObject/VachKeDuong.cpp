#include "VachKeDuong.h"
#include "SpriteAnimation.h"

VachKeDuong::VachKeDuong(float x, float y)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("VachKeDuong.tga");
	VachKeDuongSprite = std::make_shared<SpriteAnimation>(model, shader, texture, 5, 1, 0, 0.1f);
	VachKeDuongSprite->SetSize(200, 2700);
	VachKeDuongSprite->Set2DPosition(posX, posY);
	isPlayable = true;

	isFaceRight = true;
}

VachKeDuong::~VachKeDuong()
{
}

void VachKeDuong::Dead(int die)
{

	if (die == 1)
	{
		isDie = true;
		std::printf("Die");
	}
}

void VachKeDuong::Move(int dir) {

	switch (dir)
	{
	case 1:
		//move tren xuong

		XX_Val = 4.0f;
		posY += XX_Val;
		if (posY > 900)
		{
			posY = 0;
		}
		break;
	default:
		break;
	}
}


void VachKeDuong::UpdateVachKeDuongPos(GLfloat deltaTime)
{
	VachKeDuongSprite->Set2DPosition(posX, posY);

}

void VachKeDuong::VachKeDuongUpdate(GLfloat deltaTime)
{

	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	VachKeDuongSprite->Update(deltaTime);
}
void VachKeDuong::VachKeDuongDraw()
{
	if (m_DisapearTime >= 0.0f)
	{
		VachKeDuongSprite->Draw();
	}
}