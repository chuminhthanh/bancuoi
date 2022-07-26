#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class AiCar1

{
public:
	bool isDie;
	bool stable = true;
	GLfloat countTime = 0.0f;
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat sizeX = 0.0f;
	GLfloat sizeY = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat m_DisapearTime;
	int state;
	float timer;
	//stat
	bool isPlayable;
	bool isFaceRight;
	//decletion
	AiCar1(GLfloat x, GLfloat y, GLfloat m, GLfloat n);
	~AiCar1();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateAiCar1Pos(GLfloat deltaTime);
	// sprite function
	void AiCar1Update(GLfloat deltaTime);
	void AiCar1Draw();
private:
	std::shared_ptr <SpriteAnimation> AiCar1Sprite;
};