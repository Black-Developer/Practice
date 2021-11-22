#include "./external_Library/glut.h"
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <GL/freeglut_std.h>

#include "IRenderer.h"

class GLRenderer : public IRenderer
{
    void Init(int argc, char** argv) override;
    void InitCamera() override;
    void Loop() override;
    void Terminate() override;
};