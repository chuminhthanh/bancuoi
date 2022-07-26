#pragma once
#include "GameStateBase.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class SpriteAnimation;
class CarPlayer;
class AiCar1;
class AiCar2;
class AiCar3;
class AiCar4;
class VachKeDuong;
class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();
	std::string name = "SoundBG.wav";
	GLfloat		countTime = 0.0f;
	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	bool	checkCollision(std::shared_ptr<CarPlayer> rect1, std::shared_ptr<AiCar1>  rect2);
	bool	checkCollision1(std::shared_ptr<CarPlayer> rect1, std::shared_ptr<AiCar2>  rect2);
	bool	checkCollision2(std::shared_ptr<CarPlayer> rect1, std::shared_ptr<AiCar3>  rect2);
	bool	checkCollision3(std::shared_ptr<CarPlayer> rect1, std::shared_ptr<AiCar4>  rect2);
	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;
	int m_KeyPress;

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Text>		m_score;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	std::shared_ptr<CarPlayer> pointerCarPlayer;
	std::list<std::shared_ptr<CarPlayer>>	m_listCarPlayerAnimation;
	//
	std::shared_ptr<VachKeDuong> pointerVachKeDuong;
	std::list<std::shared_ptr<VachKeDuong>>	m_listVachKeDuongAnimation;
	std::shared_ptr<VachKeDuong> pointerVachKeDuong2;
	std::list<std::shared_ptr<VachKeDuong>>	m_listVachKeDuongAnimation2;

	//AiPlay
	std::list<std::shared_ptr<AiCar1>>	m_listAiCar1Animation;
	std::shared_ptr<AiCar1> pointerAiCar1;
	//1.1
	std::list<std::shared_ptr<AiCar1>>	m_listAiCar11Animation;
	std::shared_ptr<AiCar1> pointerAiCar11;
		//2	
		std::list<std::shared_ptr<AiCar2>>	m_listAiCar2Animation;
		std::shared_ptr<AiCar2> pointerAiCar2;
		//21	
		std::list<std::shared_ptr<AiCar2>>	m_listAiCar21Animation;
		std::shared_ptr<AiCar2> pointerAiCar21;

		//3	
		std::list<std::shared_ptr<AiCar3>>	m_listAiCar3Animation;
		std::shared_ptr<AiCar3> pointerAiCar3;
		//3	
		std::list<std::shared_ptr<AiCar3>>	m_listAiCar31Animation;
		std::shared_ptr<AiCar3> pointerAiCar31;
		//4	
		std::list<std::shared_ptr<AiCar4>>	m_listAiCar4Animation;
		std::shared_ptr<AiCar4> pointerAiCar4;
		//4	
		std::list<std::shared_ptr<AiCar4>>	m_listAiCar41Animation;
		std::shared_ptr<AiCar4> pointerAiCar41;
};

