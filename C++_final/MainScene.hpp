#include "IScene.hpp"
#include "GameEngine.hpp"
#include "Label.hpp"
#include "Flag.hpp"
#include "Fighter.hpp"

class MainScene : public Engine::IScene {
private:
  ALLEGRO_SAMPLE_INSTANCE * bgmInstance;
  Flag* flag;
  const int FLAG_KEY_LEFT = 0x1;
  const int FLAG_KEY_RIGHT = 0x2;
  const int FLAG_KEY_DOWN = 0x4;
  const int FLAG_KEY_UP = 0x8;

  Fighter* fighter;

  int count;
public:
  explicit MainScene() = default;
  void Initialize() override {
	this->flag = new Flag();
	this->fighter = new Fighter();
	this->count = 0;
  }

  void OnKeyDown(int keycode) override {
	if (keycode == ALLEGRO_KEY_LEFT) {
	  this->flag->setFlag(this->FLAG_KEY_LEFT);
	  this->fighter->animation->play("move_left", false, 4);
	}
	if (keycode == ALLEGRO_KEY_RIGHT) {
	  this->flag->setFlag(this->FLAG_KEY_RIGHT);
	  this->fighter->animation->play("move_right", false, 4);
	}
	if (keycode == ALLEGRO_KEY_DOWN) {
	  this->flag->setFlag(this->FLAG_KEY_DOWN);
	}
	if (keycode == ALLEGRO_KEY_UP) {
	  this->flag->setFlag(this->FLAG_KEY_UP);
	}
  }
  void OnKeyUp(int keycode) override {
	if (keycode == ALLEGRO_KEY_LEFT) {
	  this->flag->clearFlag(this->FLAG_KEY_LEFT);
	  this->fighter->animation->play("stand", true, 4);
	  if (this->flag->isFlagSet(this->FLAG_KEY_RIGHT)) {
		this->fighter->animation->play("move_right", false, 4);
	  }
	}
	if (keycode == ALLEGRO_KEY_RIGHT) {
	  this->flag->clearFlag(this->FLAG_KEY_RIGHT);
	  this->fighter->animation->play("stand", true, 4);
	  if (this->flag->isFlagSet(this->FLAG_KEY_LEFT)) {
		this->fighter->animation->play("move_left", false, 4);
	  }
	}
	if (keycode == ALLEGRO_KEY_DOWN) {
	  this->flag->clearFlag(this->FLAG_KEY_DOWN);
	}
	if (keycode == ALLEGRO_KEY_UP) {
	  this->flag->clearFlag(this->FLAG_KEY_UP);
	}
  }

  void Update(float deltaTime) override {
	this->fighter->update();
  }

  void Draw() const override {
	IScene::Draw();
	this->fighter->draw();
  }

  void Terminate() override {
	delete this->flag;
	delete this->fighter;
	IScene::Terminate();
  }

};