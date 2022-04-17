#ifndef __FILESYSTEM_H__
#define __FILESYSTEM_H__

#include "N_Ary_Node.h"


class FileSystem
{
public:
	FileSystem();
	~FileSystem();
public:
	Node* Find(const std::string& path);
	bool Add(const std::string& path, bool isDir);
	bool ChangeDir(const std::string& path);
	void ShowPath(const std::string& path);
	void ShowCurrentPath();
	void Input(std::string);
private:
	Node* root;
	Node* cwd;
private:
	Node* Find_impl(Node* directory, const std::string& path);
	bool Add_impl(Node* directory, const std::string& path, bool isDir);
};


#endif // !__FILESYSTEM_H__
