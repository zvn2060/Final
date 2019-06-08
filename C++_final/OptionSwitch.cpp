#include <utility>

#include "OptionSwitch.hpp"
namespace Engine {
    OptionSwitch::OptionSwitch(float x, float y, const std::vector<std::string>& options) :
     Lswitch("optionswitch/left.png", "optionswitch/left_in.png", x - 200, y, 153, 111, 0.5, 0.5),
     Rswitch("optionswitch/right.png", "optionswitch/right_in.png", x + 200, y, 153, 111, 0.5, 0.5),
     current("", "FOT-SkipStd-B.otf", 48, x, y + 20, 255, 255, 255, 255, 0.5, 0.5)
     {
        this->options = options;
        current = Label(options.at(0), "FOT-SkipStd-B.otf", 48, x, y + 20, 255, 255, 255, 255, 0.5, 0.5);
     }

    void OptionSwitch::Draw() const {
        Lswitch.Draw();
        Rswitch.Draw();
        current.Draw();
    }

    void OptionSwitch::SetOnClickCallback() {
        Lswitch.SetOnClickCallback(std::bind(&OptionSwitch::SwipeOption, this, false));
        Rswitch.SetOnClickCallback(std::bind(&OptionSwitch::SwipeOption, this, true));
    }

    void OptionSwitch::OnMouseMove(int mx, int my) {
        Lswitch.OnMouseMove(mx, my);
        Rswitch.OnMouseMove(mx, my);
    }

    void OptionSwitch::OnMouseDown(int button, int mx, int my) {
        Lswitch.OnMouseDown(button, mx, my);
        Rswitch.OnMouseDown(button, mx, my);
    }

    void OptionSwitch::UpDate(){
        current.Text = options.at(idx);
    }

    void OptionSwitch::SwipeOption(bool right) {
        if(right){

            idx++;
            idx %= options.size();
        }else{

            idx--;
            if(idx == -1){
                idx += options.size();
            }
        }
        UpDate();
    }
}