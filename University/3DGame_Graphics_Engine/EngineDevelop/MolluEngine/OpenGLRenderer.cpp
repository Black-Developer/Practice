#include "OpenGLRenderer.h"
#include "SceneManager.h"

void Rendering()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFrontFace(GL_CCW);
    glPolygonMode(GL_FRONT, GL_LINE);
    glPolygonMode(GL_BACK, GL_LINE);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    //glFlush();
}

void GLRenderer::Init(int argc, char** argv, int windowWidth,int windowHeight)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2, (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2);
    glutCreateWindow("Mollu Engine With OpenGL");
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void GLRenderer::InitCamera()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
void GLRenderer::Loop()
{
        glutDisplayFunc(Rendering);
        glutMainLoop();
}


void GLRenderer::Terminate()
{

}