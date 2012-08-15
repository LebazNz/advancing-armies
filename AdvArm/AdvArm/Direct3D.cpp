#include "Direct3D.h"

Direct3D* Direct3D::pInstance=nullptr;

Direct3D* Direct3D::GetInstance(void)
{
	if(pInstance==nullptr)
		pInstance=new Direct3D();
	return pInstance;                              
}

void Direct3D::DeleteInstance(void)
{
	if(pInstance!=nullptr)
		delete pInstance;
	pInstance=nullptr;
}

void Direct3D::Initialize(HWND hWnd)
{
	pObject=Direct3DCreate9(D3D_SDK_VERSION);

	D3DParams.hDeviceWindow=hWnd;
	D3DParams.Windowed=true;
	D3DParams.PresentationInterval=D3DPRESENT_INTERVAL_ONE;
	D3DParams.SwapEffect=D3DSWAPEFFECT_DISCARD;
	D3DParams.EnableAutoDepthStencil=true;
	D3DParams.AutoDepthStencilFormat=D3DFMT_D24S8;

	pObject->CreateDevice(0, D3DDEVTYPE_HAL, D3DParams.hDeviceWindow, D3DCREATE_HARDWARE_VERTEXPROCESSING, &D3DParams, &pDevice);
	D3DXCreateSprite(pDevice, &pSprite);
	D3DXCreateLine(pDevice, &pLine);
	pLine->SetWidth(3.0);
}

void Direct3D::Shutdown(void)
{
	if(pLine!=nullptr)
	{
		pLine->Release();
	}
	if(pSprite!=nullptr)
	{
		pSprite->Release();
	}
	if(pDevice!=nullptr)
	{
		pDevice->Release();
	}
	if(pObject!=nullptr)
	{
		pObject->Release();
	}
}

void Direct3D::DrawRectangle(int PosX, int PosY, int length, char red, char green, char blue)
{
	D3DRECT rect;
	rect.x1 = PosX-length/2;
	rect.y1 = PosY-length/2;
	rect.x2 = PosX+length/2;
	rect.y2 = PosY+length/2;

	pDevice->Clear(1, &rect, D3DCLEAR_TARGET, D3DCOLOR_XRGB(red, green, blue), 1.0f, 0);
}

void Direct3D::DrawLine(int StartX, int StartY, int EndX, int EndY, char red, char green, char blue)
{
	D3DXVECTOR2 line[2];

	line[0].x=StartX;
	line[0].y=StartY;
	line[1].x=EndX;
	line[1].y=EndY;

	pLine->Draw(line, 2, D3DCOLOR_XRGB(red, green, blue));
}

void Direct3D::Clear(char red, char green, char blue)
{
	pDevice->Clear(0, 0, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(red, green, blue), 1.0f, 0);
}

void Direct3D::BeginDevice()
{
	pDevice->BeginScene();
	pLine->Begin();
}
	
void Direct3D::EndDevice()
{
	pLine->End();
	pDevice->EndScene();
}
	
void Direct3D::Present()
{
	pDevice->Present(0,0,0,0);
}

Direct3D::Direct3D(void)
{
	pObject=nullptr;
	pDevice=nullptr;
	ZeroMemory(&D3DParams,sizeof(D3DPRESENT_PARAMETERS));
}

Direct3D::~Direct3D(void)
{

}