#include "GSPlay.h"

#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "SpriteAnimation.h"
#include "CarPlayer.h"
#include "AiCar1.h"
#include "AiCar2.h"
#include "AiCar3.h"
#include "AiCar4.h"
#include "VachKeDuong.h"



GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bg_main_menu.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_Exit.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 100, 50);
	button->SetSize(100, 50);
	button->SetOnClick([this]() {
			GameStateMachine::GetInstance()->PopState();
			ResourceManagers::GetInstance()->StopSound(name);
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("arialbd.ttf");
	m_score = std::make_shared< Text>(shader, font, " ", TextColor::RED, 2.0);

	m_score->Set2DPosition(Vector2(15, 45));
	//car player
	std::shared_ptr<CarPlayer> Obj = std::make_shared<CarPlayer>(240.0f, 820, 100, 100);
	pointerCarPlayer = Obj;
	m_listCarPlayerAnimation.push_back(Obj);
	
	m_KeyPress = 0;

	std::shared_ptr<VachKeDuong> vachKeDuong = std::make_shared<VachKeDuong>(200, 0);
	pointerVachKeDuong = vachKeDuong;
	m_listVachKeDuongAnimation.push_back(vachKeDuong);

	std::shared_ptr<VachKeDuong> vachKeDuong2 = std::make_shared<VachKeDuong>(430, 0);
	pointerVachKeDuong2 = vachKeDuong2;
	m_listVachKeDuongAnimation2.push_back(vachKeDuong2);

	// AiCar1
	std::shared_ptr<AiCar1> aiCar1 = std::make_shared<AiCar1>		(140, 0, 100, 100);
	pointerAiCar1 = aiCar1; 
	m_listAiCar1Animation.push_back(aiCar1);
			//1.1
		std::shared_ptr<AiCar1> aiCar11 = std::make_shared<AiCar1>	(360, -500, 100, 100);
		pointerAiCar11 = aiCar11;
		m_listAiCar11Animation.push_back(aiCar11);


	// AiCar2
	std::shared_ptr<AiCar2> aiCar2 = std::make_shared<AiCar2>		(240, -500,100,100);
	pointerAiCar2 = aiCar2;
	m_listAiCar2Animation.push_back(aiCar2);
			//2.1
		std::shared_ptr<AiCar2> aiCar21 = std::make_shared<AiCar2>	(480, -1000, 200, 200);
		pointerAiCar21 = aiCar21;
		m_listAiCar21Animation.push_back(aiCar21);


	// AiCar3
	std::shared_ptr<AiCar3> aiCar3 = std::make_shared<AiCar3>		(360, -1000, 100, 100);
	pointerAiCar3 = aiCar3;
	m_listAiCar3Animation.push_back(aiCar3);
			//3.1
		std::shared_ptr<AiCar3> aiCar31 = std::make_shared<AiCar3>	(480, -1500, 200, 200);
		pointerAiCar31 = aiCar31;
		m_listAiCar31Animation.push_back(aiCar31);

	// AiCar4
	std::shared_ptr<AiCar4> aiCar4 = std::make_shared<AiCar4>		(480, 0, 200, 200);
	pointerAiCar4 = aiCar4;
	m_listAiCar4Animation.push_back(aiCar4);
			//4.1
		std::shared_ptr<AiCar4> aiCar41 = std::make_shared<AiCar4>	(140, -1000, 100, 100);
		pointerAiCar41 = aiCar41;
		m_listAiCar41Animation.push_back(aiCar41);

	ResourceManagers::GetInstance()->PlaySound(name);

}

void GSPlay::Exit()
{
}


void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}


void GSPlay::HandleEvents()
{
}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	if (bIsPressed)
	{
		switch (key)
		{
		case KEY_MOVE_LEFT:
			m_KeyPress |= 1;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress |= 1<<1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress |= 1<<2;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress |= 1<<3;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case KEY_MOVE_LEFT:
			m_KeyPress ^= 1;
			break;
		case KEY_MOVE_BACKWORD:
			m_KeyPress ^= 1 << 1;
			break;
		case KEY_MOVE_RIGHT:
			m_KeyPress ^= 1 << 2;
			break;
		case KEY_MOVE_FORWORD:
			m_KeyPress ^= 1 << 3;
			break;
		default:
			break;
		}
	}
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

bool GSPlay:: checkCollision(std::shared_ptr<CarPlayer> rect1, std::shared_ptr<AiCar1>  rect2)
{
	int left_a = rect1 -> posX;
	int right_a = rect1 -> posX + rect1 ->sizeX;
	int top_a = rect1->posY;
	int bottom_a = rect1->posY + rect1->sizeY;

	int left_b = rect2->posX;
	int right_b = rect2->posX + rect2->sizeX;
	int top_b = rect2->posY;
	int bottom_b = rect2->posY + rect2->sizeY;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 < size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}
bool GSPlay::checkCollision1(std::shared_ptr<CarPlayer> rect1, std::shared_ptr<AiCar2>  rect2)
{
	int left_a = rect1->posX;
	int right_a = rect1->posX + rect1->sizeX;
	int top_a = rect1->posY;
	int bottom_a = rect1->posY + rect1->sizeY;

	int left_b = rect2->posX;
	int right_b = rect2->posX + rect2->sizeX;
	int top_b = rect2->posY;
	int bottom_b = rect2->posY + rect2->sizeY;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 < size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}
bool GSPlay::checkCollision2(std::shared_ptr<CarPlayer> rect1, std::shared_ptr<AiCar3>  rect2)
{
	int left_a = rect1->posX;
	int right_a = rect1->posX + rect1->sizeX;
	int top_a = rect1->posY;
	int bottom_a = rect1->posY + rect1->sizeY;

	int left_b = rect2->posX;
	int right_b = rect2->posX + rect2->sizeX;
	int top_b = rect2->posY;
	int bottom_b = rect2->posY + rect2->sizeY;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 < size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}
bool GSPlay::checkCollision3(std::shared_ptr<CarPlayer> rect1, std::shared_ptr<AiCar4>  rect2)
{
	int left_a = rect1->posX;
	int right_a = rect1->posX + rect1->sizeX;
	int top_a = rect1->posY;
	int bottom_a = rect1->posY + rect1->sizeY;

	int left_b = rect2->posX;
	int right_b = rect2->posX + rect2->sizeX;
	int top_b = rect2->posY;
	int bottom_b = rect2->posY + rect2->sizeY;

	// Case 1: size object 1 < size object 2
	if (left_a > left_b && left_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (left_a > left_b && left_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (top_a > top_b && top_a < bottom_b)
		{
			return true;
		}
	}

	if (right_a > left_b && right_a < right_b)
	{
		if (bottom_a > top_b && bottom_a < bottom_b)
		{
			return true;
		}
	}

	// Case 2: size object 1 < size object 2
	if (left_b > left_a && left_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (left_b > left_a && left_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (top_b > top_a && top_b < bottom_a)
		{
			return true;
		}
	}

	if (right_b > left_a && right_b < right_a)
	{
		if (bottom_b > top_a && bottom_b < bottom_a)
		{
			return true;
		}
	}

	// Case 3: size object 1 = size object 2
	if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
	{
		return true;
	}

	return false;
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}


void GSPlay::Update(float deltaTime)
{
	countTime += deltaTime;
	m_score->SetText(std::to_string(int(countTime)));

	if (checkCollision(pointerCarPlayer, pointerAiCar1) == true || checkCollision1(pointerCarPlayer, pointerAiCar2) == true || checkCollision1(pointerCarPlayer, pointerAiCar21) == true  || checkCollision2(pointerCarPlayer, pointerAiCar3) == true || checkCollision2(pointerCarPlayer, pointerAiCar31) == true  || checkCollision3(pointerCarPlayer, pointerAiCar4) == true || checkCollision3(pointerCarPlayer, pointerAiCar41) == true || checkCollision(pointerCarPlayer, pointerAiCar11) == true )
	{
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_DIE);
		ResourceManagers::GetInstance()->StopSound(name);
	}	

	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}

	for (auto it : m_listCarPlayerAnimation)
	{
		it->UpdateCarPlayerPos(deltaTime);
	}
	for (auto it : m_listVachKeDuongAnimation)
	{
		it->UpdateVachKeDuongPos(deltaTime);
	}	
	for (auto it : m_listVachKeDuongAnimation2)
	{
		it->UpdateVachKeDuongPos(deltaTime);
	}

	// AiCar1
	for (auto it : m_listAiCar1Animation)
	{
		it->UpdateAiCar1Pos(deltaTime);
	}
	//1.1
	for (auto it : m_listAiCar11Animation)
	{
		it->UpdateAiCar1Pos(deltaTime);
	}
	//2
	for (auto it : m_listAiCar2Animation)
	{
		it->UpdateAiCar2Pos(deltaTime);
	}
	//2.1
	for (auto it : m_listAiCar21Animation)
	{
		it->UpdateAiCar2Pos(deltaTime);
	}


	//3
	for (auto it : m_listAiCar3Animation)
	{
		it->UpdateAiCar3Pos(deltaTime);
	}
	//3.1
	for (auto it : m_listAiCar31Animation)
	{
		it->UpdateAiCar3Pos(deltaTime);
	}

	//4
	for (auto it : m_listAiCar4Animation)
	{
		it->UpdateAiCar4Pos(deltaTime);
	}
	//4
	for (auto it : m_listAiCar41Animation)
	{
		it->UpdateAiCar4Pos(deltaTime);
	}

	pointerVachKeDuong->Move(1);
	pointerVachKeDuong2->Move(1);
	pointerAiCar1->Move(1);
	pointerAiCar11->Move(1);
	pointerAiCar2->Move(1);
	pointerAiCar21->Move(1);
	pointerAiCar3->Move(1);
	pointerAiCar31->Move(1);
	pointerAiCar4->Move(1);
	pointerAiCar41->Move(1);

	if (m_KeyPress == 0)
	{
		pointerCarPlayer->Move(0);
	}
	else if (m_KeyPress == 1)
	{
		pointerCarPlayer->Move(1);
	}
	else if (m_KeyPress == 4)
	{
		pointerCarPlayer->Move(4);
	}
	else if (m_KeyPress ^= 1)
	{
		pointerCarPlayer->Move(1);
	}
	else if (m_KeyPress ^= 1 << 2)
	{
		pointerCarPlayer->Move(4);
	}

	for (auto it : m_listCarPlayerAnimation)
	{
		it->CarPlayerUpdate(deltaTime);
	}
	for (auto it : m_listAiCar1Animation)
	{
		it->AiCar1Update(deltaTime);
	}
	//1.1
	for (auto it : m_listAiCar11Animation)
	{
		it->AiCar1Update(deltaTime);
	}	

	for (auto it : m_listAiCar2Animation)
	{
		it->AiCar2Update(deltaTime);
	}
	for (auto it : m_listAiCar21Animation)
	{
		it->AiCar2Update(deltaTime);
	}
	for (auto it : m_listAiCar3Animation)
	{
		it->AiCar3Update(deltaTime);
	}
	for (auto it : m_listAiCar31Animation)
	{
		it->AiCar3Update(deltaTime);
	}
	for (auto it : m_listAiCar4Animation)
	{
		it->AiCar4Update(deltaTime);
	}
	for (auto it : m_listAiCar41Animation)
	{
		it->AiCar4Update(deltaTime);
	}
	for (auto it : m_listVachKeDuongAnimation)
	{
			it->VachKeDuongUpdate(deltaTime);
	}
	for (auto it : m_listVachKeDuongAnimation2)
	{
		it->VachKeDuongUpdate(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	m_score->Draw();
	for (auto& it : m_listVachKeDuongAnimation)
	{
		it->VachKeDuongDraw();
	}
	for (auto& it : m_listVachKeDuongAnimation2)
	{
		it->VachKeDuongDraw();
	}
	for (auto it : m_listAnimation)
	{
		it->Draw();
	}
	for (auto& it : m_listCarPlayerAnimation)
	{
		it->CarPlayerDraw();
	}
	for (auto& it : m_listAiCar1Animation)
	{
		it->AiCar1Draw();
	}
	//1.1
	for (auto& it : m_listAiCar11Animation)
	{
		it->AiCar1Draw();
	}	

	for (auto& it : m_listAiCar2Animation)
	{
		it->AiCar2Draw();
	}
	for (auto& it : m_listAiCar21Animation)
	{
		it->AiCar2Draw();
	}
	for (auto& it : m_listAiCar3Animation)
	{
		it->AiCar3Draw();
	}
	for (auto& it : m_listAiCar31Animation)
	{
		it->AiCar3Draw();
	}
	for (auto& it : m_listAiCar4Animation)
	{
		it->AiCar4Draw();
	}
	for (auto& it : m_listAiCar41Animation)
	{
		it->AiCar4Draw();
	}
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}
