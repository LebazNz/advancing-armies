#ifndef GAME_H
#define GAME_H

#include <Windows.h>

class Direct3D;

class Game
{
public:
	bool Main(void);
	
	void Update(void);
	void Render(void);
	bool Input(void);

	static Game* GetInstance(void);
	static void DeleteInstance(void);

	void Initialize(HWND hWnd, HINSTANCE hInstance, int nScreenWidth, int ScreenHeight, bool bWindowed);

private:
	Game(void);
	~Game(void);
	Game(Game&);
	Game& operator=(Game&);

	static Game* pInstance;
	DWORD Time;
	Direct3D* pD3D;
};
#endif
