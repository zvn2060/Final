#ifndef OPTIONSWITCH_HPP
#define OPTIONSWITCH_HPP

#include "IObject.hpp"
#include "IControl.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"
namespace Engine {
    class OptionSwitch : public Engine::IObject, public Engine::IControl {
    private:
        Engine::ImageButton Lswitch;
        Engine::ImageButton Rswitch;
        Engine::Label current;
        std::vector<std::string> options;
        int idx = 0;
        void SwipeOption(bool right);
    public:
        explicit OptionSwitch(float x, float y, const std::vector<std::string>& options);

        void Draw() const override;
        void SetOnClickCallback();
        void OnMouseDown(int button, int mx, int my) override;
        void OnMouseMove(int mx, int my) override;
        void UpDate();
    };
}

#endif //FINALPROJECT_OPTIONSWITCH_HPP
