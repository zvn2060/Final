#include <allegro5/allegro.h>
#include "IObject.hpp"
#include "IControl.hpp"
#include "IScene.hpp"
#include "GameEngine.hpp"
#include "Image.hpp"

namespace Engine {
    void IScene::SetBackGround(const std::string& background) {
        AddNewObject(new Engine::Image(background, 0, 0, Engine::GameEngine::GetInstance().GetScreenWidth(), Engine::GameEngine::GetInstance().GetScreenHeight()));
    }
    void IScene::Terminate() {
		Clear();
	}
	void IScene::Draw() const {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		Group::Draw();
	}
}
