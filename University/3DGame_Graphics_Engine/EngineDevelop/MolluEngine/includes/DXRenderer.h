#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include <Windows.h>


#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
#include "IRenderer.h"
#include "Vector.h"


struct SimpleVertex2f
{
    DirectX::XMFLOAT2 position;
};
class DXRenderer : public IRenderer
{
public:
    void Init(int argc, char** argv, int, int) override;
    void InitCamera() override;
    void Loop() override;
    void Terminate() override;
    void StartRender() override;
    void EndRender() override;
    void Vertex2f(float, float) override;
private:
    HRESULT hr;
    ID3D11Device* pDevice;
    ID3D11DeviceContext* pContext;
    D3D_FEATURE_LEVEL* pFeatureLevel;
    DXGI_SWAP_CHAIN_DESC* pSwanChainDesc;
    IDXGISwapChain* pSwapChain;
private:
    ID3D11RenderTargetView* pRenderTarget;
    ID3D11Buffer* pBuffer;
    ID3D11DepthStencilView* pDepthBuffer;
    ID3D11RasterizerState* p_RasterState;
private:
    DirectX::XMFLOAT2 *pVertex2f;
    D3D11_BUFFER_DESC bufferDesc;
    struct SimpleVertex2f* vertices;
};