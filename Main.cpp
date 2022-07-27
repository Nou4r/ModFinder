#include "Globals/Include.hpp"

int main()
{
	SetConsoleTitleA("ModFinder");

	std::cout << "Process name -> ";
	std::getline(std::cin, Globals::procName);

	if (Globals::procName.find(".exe") == std::string::npos)
		Globals::procName += ".exe";

	if (Process::GetHandle(Globals::procName.c_str()))
	{
		system("cls");
		Query::MemoryRegions();
	}
	else
	{
		system("cls");
		printf("Unable to parse process\nClosing in five seconds");
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		exit(-1);
	}
}