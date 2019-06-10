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
    static const int btnNum = 4;
    Engine::TextButton* btn[btnNum]{};
  
public:
    explicit TitleScene() = default;
    void Initialize() override;
    void Onclick(int btnnum);
};

#endif