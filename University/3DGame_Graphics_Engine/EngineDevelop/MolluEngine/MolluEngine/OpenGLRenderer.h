#ifndef __OPENGLRENDERER_H__
#define __OPENGLRENDERER_H__

#pragma warning(disable:4996)


#pragma comment(lib,"legacy_stdio_definitions.lib")

#include "glut.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include "freeglut.h"
#include "freeglut_std.h"
#include "glaux.h"

#include "IRenderer.h"

class GLRenderer : public IRenderer
{
public:
    //    void Init(int, char**) override;
    void Init(int, char** argv, int, int) override;
    void InitCamera() override;
    void Loop() override;
    void Terminate() override;
    void StartRender() override;
    void EndRender() override;
    void Vertex2f(float, float) override;
    int StartTextureRender(const char*, char**) override;
    void EndTextureRender() override;
    void LoadTexture() override;
    AUX_RGBImageRec* LoadBMP(const char* szFileName);
private:
    AUX_RGBImageRec* pTextureImage[1];
    unsigned int MyTextureObject[1];
};
#endif // !__OPENGLRENDERER_H__
