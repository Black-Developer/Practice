#pragma comment(lib, "glaux.lib")

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
}

void GLRenderer::Init(int argc, char** argv, int windowWidth, int windowHeight)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition((
        glutGet(GLUT_SCREEN_WIDTH) - windowWidth) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - windowHeight) / 2
    );
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
}


void GLRenderer::Terminate()
{

}

void GLRenderer::Vertex2f(float x, float y)
{
    glVertex2f(x, y);
}

int GLRenderer::StartTextureRender(const char* path, char** argv)
{
    glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);  //앞면
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);

    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  //뒷면
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);

    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);  //윗면
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);

    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  //아랫면
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, -1.0f, -1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);

    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, -1.0f);  //우측면
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, -1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);

    glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  //좌측면
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, -1.0f);
    
    glEnd();
    glutSwapBuffers();

        int Status = FALSE;
        glClearColor(0.0, 0.0, 0.0, 0.5);
        memset(pTextureImage, 0, sizeof(void*) * 1);    //포인터를 널로

        if (pTextureImage[0] = LoadBMP(path)) {   //비트맵을 로드하고 오류확인
            Status = TRUE;                              //상태 플랙을 True로
            glGenTextures(1, &MyTextureObject[0]);      //텍스쳐 생성
            glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
            glTexImage2D(GL_TEXTURE_2D, 0, 3,
                pTextureImage[0]->sizeX, pTextureImage[0]->sizeY,
                0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[0]->data);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glEnable(GL_TEXTURE_2D);
        }
        if (pTextureImage[0]) {                 //텍스쳐가 존재하면
            if (pTextureImage[0]->data) {       //텍스쳐 영상이 존재하면
                free(pTextureImage[0]->data);   //텍스쳐 영상공간 반납
            }
            free(pTextureImage[0]);             //텍스쳐 반납
        }
        return Status;
}

void GLRenderer::EndTextureRender()
{
    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}
void GLRenderer::LoadTexture()
{
}

AUX_RGBImageRec* GLRenderer::LoadBMP(const char* szFileName)
{
    FILE* pFile = NULL;
    if (!szFileName) {
        return NULL;
    }
    pFile = fopen("Mollu.bmp", "r");
    if (pFile) {
        fclose(pFile);
        return auxDIBImageLoad(L"Mollu.bmp");
    }
    else
    {
        printf("Failed\n");
    }
    return NULL;
}
void GLRenderer::StartRender()
{
    glPushMatrix();
    glBegin(GL_QUADS);
}

void GLRenderer::EndRender()
{
    glEnd();
    glFlush();
    glPopMatrix();
}