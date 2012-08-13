#ifndef DIRECT_3D
#define DIRECT_3D

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment (lib, "dxguid.lib")

class Direct3D
{
public:
	static Direct3D* GetInstance(void);
	static void DeleteInstance(void);

	void Initialize(HWND hWnd);
	void Shutdown(void);
	void DrawRectangle(int PosX, int PosY, int length, char red, char green, char blue);
	void DrawLine(int StartX, int StartY, int EndX, int EndY, char red, char green, char blue);

	LPDIRECT3DDEVICE9 GetDevice(void) {return pDevice;}
	void BeginDevice();
	void EndDevice();
	void Present();
	void Clear(char red, char green, char blue);


private:
	Direct3D(void);
	~Direct3D(void);
	Direct3D(const Direct3D&);
	Direct3D& operator=(const Direct3D&);

	static Direct3D* pInstance;

	LPDIRECT3D9 pObject;
	LPDIRECT3DDEVICE9 pDevice;
	LPD3DXSPRITE pSprite;
	LPD3DXLINE	pLine;
	LPD3DXFONT	pFont;
	D3DPRESENT_PARAMETERS D3DParams;
};
#endif DIRECT_3D