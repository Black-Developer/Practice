#include "BoxRender.h"
#include "DXRenderer.h"
#include "OpenGLRenderer.h"


void BoxRender::Render()
{
	renderer->StartRender();
	renderer->Vertex2f(transform->position.x + (transform->scale.x/2), transform->position.y-(transform->scale.y/2));
	renderer->Vertex2f(transform->position.x - (transform->scale.x/2), transform->position.y-(transform->scale.y/2));
	renderer->Vertex2f(transform->position.x - (transform->scale.x/2), transform->position.y+(transform->scale.y/2));
	renderer->Vertex2f(transform->position.x + (transform->scale.x/2), transform->position.y+(transform->scale.y/2));
	renderer->EndRender();
}