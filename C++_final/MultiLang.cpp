
#include "MultiLang.hpp"
#include "Util.hpp"


namespace MultiLang{
    json Langjson;
    string TitleScene_play, TitleScene_replay, TitleScene_option, TitleScene_exit;
    string SettingScene_audio, SettingScene_audio_BGM, SettingScene_audio_SFX, SettingScene_language, SettingScene_display, SettingScene_back;

	void ReadLangFile( const string & lang ){
		const string LangPath = "resources/lang/" + lang + ".json";
		Langjson = Util::readJsonData(LangPath);
	}
	
	void SetLang(){
		SetTitleLang();
		SetSettingLang();
	}

    void SetTitleLang() {

        TitleScene_play = Langjson["TitleScene"].value("play", "play");
        TitleScene_replay = Langjson["TitleScene"].value("replay", "replay");
        TitleScene_option = Langjson["TitleScene"].value("option", "option");
        TitleScene_exit = Langjson["TitleScene"].value("exit", "exit");
    }

    void SetSettingLang() {
        SettingScene_audio = Langjson["SettingScene"]["audio"].value("tag", "audio");
        SettingScene_audio_BGM = Langjson["SettingScene"]["audio"].value("BGM", "BGM");
        SettingScene_audio_SFX = Langjson["SettingScene"]["audio"].value("SFX", "SFX");
        SettingScene_language = Langjson["SettingScene"].value("language", "language");
        SettingScene_display = Langjson["SettingScene"].value("display", "display");
        SettingScene_back = Langjson["SettingScene"].value("back", "back");
    }

}