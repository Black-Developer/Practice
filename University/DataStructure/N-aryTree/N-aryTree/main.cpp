#include "FileSystem.h"
#include <iostream>

using namespace std;

void main()
{
	FileSystem fileSystem;
	string command;

	fileSystem.Add("usr", true);
	fileSystem.Add("etc", true);
	fileSystem.Add("etc/Downoads", true);
	fileSystem.Add("var", true);
	fileSystem.Add("temp_File", false);
	fileSystem.Add("Git", true);
	fileSystem.Add("Git/Downloads", true);
	fileSystem.Add("Git/Downloads/HelloWorld.cpp", false);

	while (true)
	{
		cout << "> ";
		cin >> command;
		fileSystem.Input(command);
	}
}