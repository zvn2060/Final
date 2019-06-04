#ifndef MULTILANGUAGE_HPP
#define MULTILANGUAGE_HPP

#include <map>
#include <regex>

namespace MultiLang{
	using namespace std;
	extern map<string, string> table;
	extern string TitleScene_play;
	extern string TitleScene_replay;
	extern string TitleScene_option;
	extern string TitleScene_exit;
	
	void ReadLangFile(const string& lang);
	void SetLang();
}

#endif //FINALPROJECT_LANGUAGE_HPP
