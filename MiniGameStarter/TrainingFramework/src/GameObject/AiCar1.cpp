#include "AiCar1.h"
#include "SpriteAnimation.h"

AiCar1 :: AiCar1(GLfloat x, GLfloat y, GLfloat m, GLfloat n)
{
	m_DisapearTime = 0.8f;
	isDie = false;
	posX = x;
	posY = y;
	sizeX = m;
	sizeY = n;
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("Animation");
	auto texture = ResourceManagers::GetInstance()->GetTexture("AiCar1.tga");
	AiCar1Sprite = std::make_shared<SpriteAnimation>(model, shader, texture, 4, 1, 0, 0.1f);
	AiCar1Sprite->SetSize(sizeX, sizeY);
	AiCar1Sprite->Set2DPosition(posX, posY);
	isPlayable = true;
	isFaceRight = true;
}

AiCar1::~AiCar1()
{
}

void AiCar1::Dead(int die)
{

	if (die == 1)
	{
		isDie = true;
		std::printf("Die");
	}
}

void AiCar1::Move(int dir) {

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
		if (posY > 1200 )
		{
			posY = 0;
		}
		break;
	default:
		break;
	}
}


void AiCar1::UpdateAiCar1Pos(GLfloat deltaTime)
{
	AiCar1Sprite->Set2DPosition(posX, posY);

}

void AiCar1::AiCar1Update(GLfloat deltaTime)
{
	countTime += deltaTime;

	if (isDie && m_DisapearTime > 0.0f)
	{
		m_DisapearTime -= deltaTime;
	}
	AiCar1Sprite->Update(deltaTime);
}
void AiCar1::AiCar1Draw()
{
	if (m_DisapearTime >= 0.0f)
	{
		AiCar1Sprite->Draw();
	}
}