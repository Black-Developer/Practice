#include "OpenGLRenderer.h"
#include "SceneManager.h"

void MyDisplay()
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
    glRotatef(30.0, 1.0, 1.0, 1.0);
    glFlush();
}

void GLRenderer::Init(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

void GLRenderer::InitCamera()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
void GLRenderer::Loop()
{
    while (true)
    {
        SceneManager::getInstance().PlayScene();
        glutDisplayFunc(MyDisplay);
        glutMainLoopEvent();

    }
}


void GLRenderer::Terminate()
{

}