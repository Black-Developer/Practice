#include "GLTextureComponent.h"
#include "glut.h"
#include <iostream>


AUX_RGBImageRec* pTextureImage[1];

int GLTextureComponent::LoadGLTextures(char* szFilePath) {       //파일을 로드하고 텍스쳐로 변환
    int Status = FALSE;
    glClearColor(0.0, 0.0, 0.0, 0.5);
    memset(pTextureImage, 0, sizeof(void*) * 1);    
  
    if (pTextureImage[0] = LoadBMP(szFilePath)) {   
        Status = TRUE;                              
        glGenTextures(1, &MyTextureObject[0]);      
        glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);
        glTexImage2D(GL_TEXTURE_2D, 0, 3,
            pTextureImage[0]->sizeX, pTextureImage[0]->sizeY,
            0, GL_RGB, GL_UNSIGNED_BYTE, pTextureImage[0]->data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glEnable(GL_TEXTURE_2D);
    }
    if (pTextureImage[0]) {              
        if (pTextureImage[0]->data) {    
            free(pTextureImage[0]->data);
        }
        free(pTextureImage[0]);          
    }
    return Status;
}

AUX_RGBImageRec* GLTextureComponent::LoadBMP(char* szFilename)
{
    FILE* pFile = NULL;
    if (!szFilename) {
        return NULL;
    }
    pFile = fopen(szFilename, "r");
    if (pFile) {
        fclose(pFile);
        return auxDIBImageLoadA(szFilename);     //파일로부터 메모리로
    }
    return NULL;
}

void GLTextureComponent::Render()
{
    glBindTexture(GL_TEXTURE_2D, MyTextureObject[0]);

}