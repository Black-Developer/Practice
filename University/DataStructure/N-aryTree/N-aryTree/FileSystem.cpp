#include "FileSystem.h"
#include <iostream>
#include <string>
#include <stack>
enum E_Comnand
{
	isVaild = 0,
	ls,
	cd,
	help
};

FileSystem::FileSystem()
{
	root = new Node{ "/", true, {},nullptr };
	cwd = root;
}

FileSystem::~FileSystem()
{
}

Node* FileSystem::Find(const std::string& path)
{
	if (path[0] == '/')
	{
		return Find_impl(root, path.substr(1));
	}
	else
	{
		return Find_impl(cwd, path);
	}
}

bool FileSystem::Add(const std::string& path, bool isDir)
{
	if (path[0] == '/')
	{
		return Add_impl(root, path.substr(1), isDir);
	}
	else
	{
		return Add_impl(cwd, path, isDir);
	}
	return false;
}

bool FileSystem::ChangeDir(const std::string& path)
{

	Node* found = Find(path);
	if (path.compare("..") == 0)
	{
		if (cwd !=nullptr && cwd->parent == nullptr)
		{
			std::cout << "This is Top Level Directory" << std::endl;
			return false;
		}
		else if (cwd != nullptr && cwd->parent != nullptr)
		{
		cwd = cwd->parent;
		std::cout << "Now Directory: " << cwd->name << std::endl;
		return true;
		}

	}
	if (found && found->isDir)
	{
	cwd = found;
	std::cout << "Now Directory: " << cwd->name << std::endl;
	return true;
	}
	std::cout << path << " Can't Find Path." << std::endl;
	return false;
}

void FileSystem::ShowPath(const std::string& path)
{
	Node* found = Find(path);
	if (!found)
	{
		if (cwd->children.empty())
		{
			std::cout << path << " is empty" << std::endl;
			return;
		}
		else
		{
			for (auto child : cwd->children)
			{
				if(child->isDir)
				{ 
				std::cout << "d " << child->name << std::endl;
				}
				else
				{
					std::cout << "- " << child->name << std::endl;
				}
			}
			return;
		}
	}
	if (found->isDir)
	{
		for (auto child : found->children)
		{
			if (child->isDir)
			{
				std::cout << "d " << child->name << std::endl;
			}
			else
			{
				std::cout << "- " << child->name << std::endl;
			}
		}
	}
	else
	{
		std::cout << "- " << found->name << std::endl;
	}
}
void FileSystem::ShowCurrentPath()
{
	Node* tempCwd;
	std::stack<std::string> currentPath;
	tempCwd = cwd;
	while (tempCwd->parent != nullptr)
	{
		currentPath.push(tempCwd->name + "/");
		tempCwd = tempCwd->parent;
	}

	while (!currentPath.empty())
	{
		std::cout << currentPath.top();
		currentPath.pop();
	}
}

void FileSystem::Input(std::string command)
{
	if (command.compare("ls") == 0)
	{
		ShowPath(cwd->name);
	}
	else if (command.compare("cd") == 0)
	{
		std::string dirName;
		std::cout << "Change Directory Name > ";
		std::cin >> dirName;
		ChangeDir(dirName);

	}
	else if (command.compare("cd ..") == 0)
	{
		ChangeDir("..");
	}
	else if (command.compare("mkdir") == 0)
	{
		std::string dirName;
		std::cout << "Create Directory Name > ";
		std::cin >> dirName;
		Add(dirName, true);
	}
	else if (command.compare("pwd") == 0)
	{
		ShowCurrentPath();
	}
	else if (command.compare("vi") == 0)
	{
		std::string fileName;
		std::cout << "Create File Name > ";
		std::cin >> fileName;
		Add(fileName, false);
	}

	else if (command.compare("help") == 0)
	{
		std::cout << "Command List" << std::endl;
		std::cout << "1. ls\t- File/Directory is Included int this directory" << std::endl;
		std::cout << "2. cd\t- Change Directory" << std::endl;
		std::cout << "3. mkdir- Make Directory" << std::endl;
		std::cout << "4. pwd\t- Print Current Directory Path" << std::endl;
		std::cout << "5. vi\t- Make File" << std::endl;
		std::cout << "6. exit\t- Exit Program" << std::endl;
	}
	else if (command.compare("exit") == 0)
	{
		exit(0);
	}
}

Node* FileSystem::Find_impl(Node* directory, const std::string& path)
{
	if (path.empty())
	{
		return directory;
	}
	auto sep = path.find('/');
	std::string currentPath;
	std::string restPath;

	if (sep == std::string::npos)
	{
		currentPath = path;
	}
	else
	{
		currentPath = path.substr(0, sep);
	}
	if (sep == std::string::npos)
	{
		restPath = "";
	}
	else
	{
		restPath = path.substr(sep + 1);
	}
	auto found = std::find_if(
		directory->children.begin(),
		directory->children.end(),
		[&](const Node* child)
	{
		return child->name == currentPath;
	});
	if (found != directory->children.end())
	{
		return Find_impl(*found, restPath);
	}
	return NULL;
}

bool FileSystem::Add_impl(Node* directory, const std::string& path, bool isDir)
{
	if (!directory->isDir)
	{
		std::cout << directory->name << "is File." << std::endl;
		return false;
	}
	auto sep = path.find('/');
	if (sep == std::string::npos)
	{
		auto found = std::find_if(
			directory->children.begin(),
			directory->children.end(),
			[&](const Node* child)
		{
			return child->name == path;
		});
		if (found != directory->children.end())
		{
			std::cout << directory->name << "File/Directory is alredy exist in " << path << std::endl;
			return false;
		}

		directory->children.push_back(new Node{ path,isDir, {},directory});
		return true;
	}

	std::string nextDir = path.substr(0, sep);
	auto found = std::find_if(
		directory->children.begin(),
		directory->children.end(),
		[&](const Node* child)
	{
		return child->name == nextDir && child->isDir;
	});
	if (found != directory->children.end())
	{
		return Add_impl(*found, path.substr(sep + 1), isDir);
	}
	std::cout << directory->name << " in " << nextDir << "Diretory is Not Exist" << std::endl;
	return false;
}
