#ifndef OPTIONSWITCH_HPP
#define OPTIONSWITCH_HPP

#include "IObject.hpp"
#include "IControl.hpp"
#include "ImageButton.hpp"
#include "Label.hpp"

class OptionButton : public Engine::IObject, public Engine::IControl{
private:
    Engine::ImageButton Lswitch;
    Engine::ImageButton Rswitch;
    Engine::Label current;
    std::vector<std::string> options;
public:
};


#endif //FINALPROJECT_OPTIONSWITCH_HPP
