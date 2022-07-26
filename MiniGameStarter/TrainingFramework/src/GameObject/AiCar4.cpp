#include "AiCar4.h"
#include "SpriteAnimation.h"

AiCar4::AiCar4(GLfloat x, GLfloat y, GLfloat m, GLfloat n)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	sizeX = m;
	sizeY = n;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiCar4.tga");
	AiCar4Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 4, 1, 0, 0.1f);
	AiCar4Sprite->SetSize(sizeX, sizeY);
	AiCar4Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiCar4::~AiCar4()
{
}

void AiCar4::Dead(int die)
{

	if (die == 1)
	{
		isDie = true;
		std::printf("Die");
	}
}

void AiCar4::Move(int dir) {

	switch (dir)
	{
	case 1:
		//move tren xuong

		if (countTime < 10.0f) {
			XX_Val = 1.3f;
		}
		else if (countTime >= 10.0f && countTime < 20.0f) {
			XX_Val = 1.5f;
		}
		else if (countTime >= 20.0f && countTime < 30.0f) {
			XX_Val = 1.7f;
		}
		posY += XX_Val;
		if (posY > 1200)
		{
			posY = 0;
		}
		break;
	default:
		break;
	}
}


void AiCar4::UpdateAiCar4Pos(GLfloat deltaTime)
{
	AiCar4Sprite->Set2DPosition(posX, posY);

}

void AiCar4::AiCar4Update(GLfloat deltaTime)
{

	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiCar4Sprite->Update(deltaTime);
}
void AiCar4::AiCar4Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiCar4Sprite->Draw();
	}
}