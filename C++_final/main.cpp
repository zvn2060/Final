// [main.cpp]
// this template is provided for the 2D tower defense game.
// Program entry point.
// Returns program exit code.
#include "GameEngine.hpp"
#include "LOG.hpp"
#include "FileHelper.hpp"
#include <vector>
#include <iterator>
int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();

	for (std::string it : FileHelper::GetFiles("D:\\Users\\srtm\\Desktop\\C++_final\\C++_final\\resources")) {
	  std::cout << it << std::endl;
	}

	system("pause");
	
	return 0;
}
