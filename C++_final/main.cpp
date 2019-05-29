// [main.cpp]
// this template is provided for the 2D tower defense game.
// Program entry point.
// Returns program exit code.
#include <vector>
#include <iterator>
#include "GameEngine.hpp"
#include "LOG.hpp"
#include "FileHelper.hpp"
#include "TitleScene.hpp"
#include "MainScene.hpp"

int main(int argc, char **argv) {
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();

	game.AddNewScene("title", new TitleScene());
	game.AddNewScene("main", new MainScene());

	for (std::string it : FileHelper::GetFiles("D:\\Users\\srtm\\Desktop\\C++_final\\C++_final\\resources")) {
	  std::cout << it << std::endl;
	}

	game.Start("title", 60, 1280, 720);

	return 0;
}
