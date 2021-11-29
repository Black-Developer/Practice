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
	wcex.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);

	wcex.hIcon = LoadIcon(0, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(0, IDI_APPLICATION);

	wcex.lpszClassName = WindowClass;
	wcex.lpszMenuName = nullptr;

	wcex.hInstance = HInstance();

	wcex.lpfnWndProc = DefWindowProc;


	RegisterClassEx(&wcex);

	HWND hWnd = CreateWindow(WindowClass, WindowTitle, WS_EX_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, windowWidth, windowHeight, nullptr, nullptr, HInstance(), nullptr);

	if (!hWnd)
	{
		MessageBox(0, L"Failed To Create Mollu?", 0, 0);
		return;
	}
		ShowWindow(hWnd, SW_SHOW);


}

void DXRenderer::InitCamera()
{
}
void DXRenderer::Loop()
{
	MSG msg = { 0 };
	while (msg.message != WM_QUIT)
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