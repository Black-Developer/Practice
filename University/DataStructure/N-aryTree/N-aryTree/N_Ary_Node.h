#ifndef __N_ARY_NODE_H__
#define __N_ARY_NODE_H__

#include <string>
#include <vector>

struct N_Ary_Node
{
	std::string name;
	bool isDir;
	std::vector<N_Ary_Node*> children;
	N_Ary_Node* parent;
};
#define Node N_Ary_Node
#endif // !__N_ARY_NODE_H__