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
