#ifndef __OPENGLOBJLOADER_H__
#define __OPENGLOBJLOADER_H__

#include "OBJLoader.h"
#include <vector>
#include "../glm/glm.hpp"

class OpenGLOBJLoader : public ObjLoader
{
public:
	OpenGLOBJLoader() {}
	~OpenGLOBJLoader() {}
	bool LoadOBJ(const char* path) override;
	bool ReadObj(const char* path);
private:
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;

	std::vector<glm::vec3> out_Vertices;
	std::vector<glm::vec2> out_UVs;
	std::vector<glm::vec3> out_Normals;
};
#endif // !__OPENGLOBJLOADER_H__