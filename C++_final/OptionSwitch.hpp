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
        std::function <void(void)> OnClickCallback;
        void SwipeOption(bool right);
    public:
        explicit OptionSwitch(float x, float y, const std::vector<std::string>& options, const std::string& init);
        std::string GetCurrentOption();
        void Draw() const override;
        void SetOnClickCallback(std::function<void(void)> onClickCallback);
        void OnMouseDown(int button, int mx, int my) override;
        void OnMouseMove(int mx, int my) override;
        void UpDate();
    };
}

#endif //FINALPROJECT_OPTIONSWITCH_HPP
