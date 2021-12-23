#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include "OpenGLOBJLoader.h"
#include "OpenGLRenderer.h"

bool OpenGLOBJLoader::LoadOBJ(const char* path)
{
	ReadObj(path);
	return true;
}

bool OpenGLOBJLoader::ReadObj(const char* path)
{
	std::vector<unsigned int> verticsModel;
	std::vector<unsigned int> uvsModel;
	std::vector<unsigned int> normalsModel;
	std::vector<glm::vec3> temp_vertices;
	std::vector<glm::vec2> temp_uvs;
	std::vector<glm::vec3> temp_normals;
	FILE* file = fopen(path, "r");
	try
	{
		if (file == NULL)
		{
			throw "파일이 존재하지 않습니다.";
		}
	}
	catch (const char* error)
	{
		std::cout << error << std::endl;
	}
	while (true)
	{
		char lineReader[256];
		int reader = fscanf(file, "%s", lineReader);
		if (reader == EOF)
		{
			break;
		}

		if (strcmp(lineReader, "v") == 0)
		{
			glm::vec3 vertex;
			fscanf_s(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			temp_vertices.push_back(vertex);
		}
		else if (strcmp(lineReader, "vt") == 0)
		{
			glm::vec2 uv;
			fscanf_s(file, "%f %f\n", &uv.x, &uv.y);
			temp_uvs.push_back(uv);
		}
		else if (strcmp(lineReader, "vn") == 0)
		{
			glm::vec3 normal;
			fscanf_s(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			temp_normals.push_back(normal);
		}
		else if (strcmp(lineReader, "f") == 0)
		{
			std::string vertex1;
			std::string vertex2;
			std::string vertex3;
			int vertexIndex[3], uvIndex[3], normalIndex[3];
			int sync = fscanf_s(
				file,
				"%d/%d/%d %d/%d/%d %d/%d/%d\n",
				&vertexIndex[0],
				&uvIndex[0],
				&normalIndex[0],
				&vertexIndex[1],
				&uvIndex[1],
				&normalIndex[1],
				&vertexIndex[2],
				&uvIndex[2],
				&normalIndex[2]
			);
			try
			{
				if (sync != 9)
				{
					throw "OBJ 파일 로딩 실패";
				}
			}
			catch (const char* error)
			{
				std::cout << error << std::endl;
				return false;
			}

			verticsModel.push_back(vertexIndex[0]);
			verticsModel.push_back(vertexIndex[1]);
			verticsModel.push_back(vertexIndex[2]);
			uvsModel.push_back(uvIndex[0]);
			uvsModel.push_back(uvIndex[1]);
			uvsModel.push_back(uvIndex[2]);
			normalsModel.push_back(normalIndex[0]);
			normalsModel.push_back(normalIndex[1]);
			normalsModel.push_back(normalIndex[2]);

		}
		for (int i = 0; i < verticsModel.size(); i++)
		{
			int vertexIndex = verticsModel[i];
			glm::vec3 vertex = temp_vertices[vertexIndex - 1];
			out_Vertices.push_back(vertex);
		}

		for (int i = 0; i < uvsModel.size(); i++)
		{
			int uvIndex = uvsModel[i];
			glm::vec2 uv = temp_uvs[uvIndex - 1];
			out_UVs.push_back(uv);
		}

		for (int i = 0; i < normalsModel.size(); i++)
		{
			int normalIndex = normalsModel[i];
			glm::vec3 normal = temp_normals[normalIndex - 1];
			out_Normals.push_back(normal);
		}
	}
}