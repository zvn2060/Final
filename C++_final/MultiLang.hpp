#ifndef MULTILANGUAGE_HPP
#define MULTILANGUAGE_HPP

#include "Util.hpp"

namespace MultiLang{
    using namespace std;
    extern json Langjson;
    extern string TitleScene_play, TitleScene_replay, TitleScene_option, TitleScene_exit;
    extern string SettingScene_audio, SettingScene_audio_BGM, SettingScene_audio_SFX, SettingScene_language, SettingScene_display, SettingScene_back;
    extern void ReadLangFile(const string& lang);
    extern void SetLang();
    extern void SetTitleLang();
    extern void SetSettingLang();

}

#endif //FINALPROJECT_LANGUAGE_HPP
