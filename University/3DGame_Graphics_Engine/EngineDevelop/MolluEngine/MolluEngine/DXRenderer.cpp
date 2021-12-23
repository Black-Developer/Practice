#include "DXRenderer.h"
#include "SceneManager.h"


using namespace DirectX;

#define MAX_NAME_STRING 256
#define HInstance() GetModuleHandle(NULL)
WCHAR WindowClass[MAX_NAME_STRING];
WCHAR WindowTitle[MAX_NAME_STRING];

void DXRenderer::Init(int argc, char** argv, int windowWidth, int windowHeight)
{
	int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR lpCmdLine, INT nCmdShow);
	wcscpy_s(WindowClass, TEXT("Mollu Engine"));
	wcscpy_s(WindowTitle, TEXT("Mollu Engine With Direct X"));

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;

	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION);

	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();

	wcex.lpfnWndProc = DefWindowProc;


	RegisterClassEx(&wcex);

	HWND hWnd = CreateWindow(
		WindowClass,
		WindowTitle,
		WS_EX_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,		
		windowWidth,
		windowHeight,
		nullptr,
		nullptr,
		HInstance(),
		nullptr
	);



	hr = D3D11CreateDeviceAndSwapChain(
		NULL,
		D3D_DRIVER_TYPE_HARDWARE,
		NULL,
		D3D11_CREATE_DEVICE_BGRA_SUPPORT,
		NULL,
		NULL,
		D3D11_SDK_VERSION,
		pSwanChainDesc,
		&pSwapChain,
		&pDevice,
		pFeatureLevel,
		&pContext);
	if (!hWnd || FAILED(hr))
	{
		MessageBox(0, L"Failed To Create Mollu?", 0, 0);
		return;
	}




	ShowWindow(hWnd, SW_SHOW);
}

void DXRenderer::InitCamera()
{
	ID3D11Texture2D* pBackBuffer = NULL;
	if (pSwapChain != NULL)
	{
		HRESULT hr = pSwapChain->GetBuffer(
			0,
			__uuidof(ID3D11Texture2D),
			(LPVOID*)&pBackBuffer);

		hr = pDevice->CreateRenderTargetView(
			pBackBuffer,
			NULL,
			&pRenderTarget
		);

	pBackBuffer->Release();
	}
	pContext->OMSetRenderTargets(1, &pRenderTarget, NULL);
	pContext->Flush();
}
void DXRenderer::Loop()
{
	MSG msg = { 0 };
	if (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}


void DXRenderer::Terminate()
{

}

void DXRenderer::Vertex2f(float x, float y)
{
	vertices = new SimpleVertex2f();
	vertices->position.x = x;
	vertices->position.y = y;
}

int DXRenderer::StartTextureRender(const char* path, char** argv)
{
	return 0;
}

void DXRenderer::EndTextureRender()
{
}

void DXRenderer::LoadTexture()
{

}

void DXRenderer::StartRender()
{
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.ByteWidth = sizeof(SimpleVertex2f) * 2;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;
}

void DXRenderer::EndRender()
{
	D3D11_SUBRESOURCE_DATA InitData;
	InitData.pSysMem = vertices;
	InitData.SysMemPitch = 0;
	InitData.SysMemSlicePitch = 0;
	pDevice->CreateBuffer(&bufferDesc, &InitData, &pBuffer);
	pContext->DrawAuto();
}