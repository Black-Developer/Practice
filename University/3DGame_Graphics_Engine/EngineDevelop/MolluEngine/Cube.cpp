#include "MolluEngine.h"
#include "BoxRenderer.h"

class Cube : public MonoBehaviour
{
		GameObject cube;
	void Start()
	{
		//cube.AddComponent(new GL_BoxRenderer);
		//cube.AddComponent(new DX_BoxRenderer);
		//cube.AddComponent(new BoxRender());
		cube.transform.SetPosition(Vector3(0, 0, 0));
	}
	void Update()
	{
	}
};