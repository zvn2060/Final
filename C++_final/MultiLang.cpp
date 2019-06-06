
#include "MultiLang.hpp"
#include "Util.hpp"


namespace MultiLang{
    json Langjson;
    string TitleScene_play, TitleScene_replay, TitleScene_option, TitleScene_exit;
    string SettingScene_audio, SettingScene_language, SettingScene_display, SettingScene_back;

	void ReadLangFile( const string & lang ){
		const string LangPath = "resources/lang/" + lang + ".json";
		Langjson = Util::readJsonData(LangPath);
	}
	
	void SetLang(){
		SetTitleLang();
		SetSettingLang();
	}

    void SetTitleLang() {
        auto it = Langjson.find("TitleScene")->find("play");
        TitleScene_play = *it;
        it = Langjson.find("TitleScene")->find("replay");
        TitleScene_replay = *it;
        it = Langjson.find("TitleScene")->find("option");
        TitleScene_option = *it;
        it = Langjson.find("TitleScene")->find("exit");
        TitleScene_exit = *it;
    }

    void SetSettingLang() {
        auto it = Langjson.find("SettingScene")->find("audio")->find("tag");
        SettingScene_audio = *it;
        it = Langjson.find("SettingScene")->find("language");
        SettingScene_language = *it;
        it = Langjson.find("SettingScene")->find("display");
        SettingScene_display = *it;
        it = Langjson.find("SettingScene")->find("back");
        SettingScene_back = *it;
    }

}