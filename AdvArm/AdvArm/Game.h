#ifndef GAME_H
#define GAME_H

#include <Windows.h>

class Game
{
public:
	bool Main(void);
	
	void Update(void);
	void Render(void);
	bool Input(void);

	static Game* GetInstance(void);
	static void DeleteInstance(void);

private:
	Game(void);
	~Game(void);
	Game(Game&);
	Game& operator=(Game&);

	static Game* pInstance;
	DWORD Time;
};
#endif
