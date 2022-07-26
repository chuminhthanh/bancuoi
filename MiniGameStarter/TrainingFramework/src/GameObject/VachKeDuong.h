#include "SpriteAnimation.h"
#include "ResourceManagers.h"
#include <GameStates/GameStateMachine.h>

class SpriteAnimation;

class VachKeDuong

{
public:
	bool isDie;
	bool stable = true;
	GLfloat posX = 0.0f;
	GLfloat posY = 0.0f;
	GLfloat XX_Val = 0.0f;
	GLfloat m_DisapearTime;
	int state;
	float timer;
	//stat
	bool isPlayable;
	bool isFaceRight;
	//decletion
	VachKeDuong(float x, float y);
	~VachKeDuong();
	//function
	void Move(int dir);
	void Dead(int die);
	// caculate function
	void UpdateVachKeDuongPos(GLfloat deltaTime);
	// sprite function
	void VachKeDuongUpdate(GLfloat deltaTime);
	void VachKeDuongDraw();
private:
	std::shared_ptr <SpriteAnimation> VachKeDuongSprite;
};
