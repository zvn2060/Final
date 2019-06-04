#ifndef TITLESCENE_HPP
#define TITLESCENE_HPP

#include "IScene.hpp"
#include "GameEngine.hpp"
#include "Label.hpp"
#include "Flag.hpp"
#include "Image.hpp"
#include "TextButton.hpp"

class TitleScene : public Engine::IScene {
private:
  ALLEGRO_SAMPLE_INSTANCE * bgmInstance;
  static const int btnNum = 4;
  Engine::TextButton* btn[btnNum];
  Flag* flag;
  const int FLAG_KEY_DOWN = 0x1;
  const int FLAG_KEY_UP = 0x2;
  int index;

  int count;
public:
  explicit TitleScene() = default;
  void Initialize() override;
  void Onclick(int btnnum);
  void Terminate() override {
	delete this->flag;
	IScene::Terminate();
  }
};

#endif