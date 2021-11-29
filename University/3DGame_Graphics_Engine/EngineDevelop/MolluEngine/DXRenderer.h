
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <Windows.h>


#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include "IRenderer.h"

class DXRenderer : public IRenderer
{
public:
    void Init(int argc, char** argv,int, int) override;
    void InitCamera() override;
    void Loop() override;
    void Terminate() override;
private:
    ID3D11Device* device;
    ID3D11DeviceContext* context;
    IDXGISwapChain* swapChain;
private:
    ID3D11RenderTargetView* target;
    ID3D11DepthStencilView* buffer;
    ID3D11RasterizerState* rState;
};