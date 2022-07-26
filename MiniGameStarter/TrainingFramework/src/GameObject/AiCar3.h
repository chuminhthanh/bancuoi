#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class AiCar3

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
	AiCar3(GLfloat x, GLfloat y, GLfloat m, GLfloat n);
	~AiCar3();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateAiCar3Pos(GLfloat deltaTime);
	// sprite function
	void AiCar3Update(GLfloat deltaTime);
	void AiCar3Draw();
private:
	std::shared_ptr <SpriteAnimation> AiCar3Sprite;
};