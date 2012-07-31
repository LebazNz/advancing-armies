#include "Game.h"

Game* Game::pInstance=nullptr;

Game* Game::GetInstance(void)
{
	if(pInstance==nullptr)
		pInstance=new Game();

	return pInstance;
}

void Game::DeleteInstance(void)
{
	if(pInstance!=nullptr)
	{
		delete pInstance;
	}
}

bool Game::Main()
{
	if(Input()==false)
		return false;
	Update();
	Render();
	return true;
}

void Game::Update(void)
{
	DWORD newTime=GetTickCount();
	float fDt=(newTime-Time)/1000.0f;
}

void Game::Render(void)
{
}

bool Game::Input(void)
{
	if(GetAsyncKeyState(VK_ESCAPE)&1)
		return false;

	return true;
}

Game::Game(void)
{
	Time=0;
}

Game::~Game(void)
{
}
