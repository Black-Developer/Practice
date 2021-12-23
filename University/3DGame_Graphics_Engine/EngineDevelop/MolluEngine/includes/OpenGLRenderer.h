#define GLUT_DISABLE_ATEXIT_HACK

#include "glut.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <freeglut.h>
#include <freeglut_std.h>

#include "IRenderer.h"

class GLRenderer : public IRenderer
{
    //    void Init(int, char**) override;
    void Init(int, char** argv, int, int) override;
    void InitCamera() override;
    void Loop() override;
    void Terminate() override;
    void StartRender() override;
    void EndRender() override;
    void Vertex2f(float, float) override;
};