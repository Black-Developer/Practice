#include "BoxRenderer.h"
#include "DXRenderer.h"
#include "OpenGLRenderer.h"


void GL_BoxRenderer::Render()
{

	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex2f(transform.position.x + (transform.scale.x / 2), transform.position.y - (transform.scale.y / 2));
	glVertex2f(transform.position.x - (transform.scale.x / 2), transform.position.y - (transform.scale.y / 2));
	glVertex2f(transform.position.x - (transform.scale.x / 2), transform.position.y + (transform.scale.y / 2));
	glVertex2f(transform.position.x + (transform.scale.x / 2), transform.position.y + (transform.scale.y / 2));
	glEnd();
	glFlush();
	glPopMatrix();
}

void DX_BoxRenderer::Render()
{	

}