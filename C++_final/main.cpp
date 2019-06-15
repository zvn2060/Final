#include "GameEngine.hpp"
#include "LOG.hpp"
#include "TitleScene.hpp"
#include "MainScene.hpp"
#include "SettingScene.hpp"

int main(int argc, char **argv) {
	
	Engine::LOG::SetConfig(true);
	Engine::GameEngine& game = Engine::GameEngine::GetInstance();

	game.AddNewScene("title", new TitleScene());
	game.AddNewScene("main", new MainScene());
	game.AddNewScene("setting", new SettingScene());
	
	game.Start("title");
	
	return 0;
}
