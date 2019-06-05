#include <fstream>
#include <regex>
#include "MultiLang.hpp"
#include <iostream>
namespace MultiLang{

	map<string, string> table{
			{"TitleScene_play", "play"},
			{"TitleScene_replay", "replay"},
			{"TitleScene_option", "option"},
			{"TitleScene_exit", "exit"}
	};
	
	string TitleScene_play;
	string TitleScene_replay;
	string TitleScene_option;
	string TitleScene_exit;
	regex keyvaluePair("(.*)=(.*)");
	smatch sm;
	void ReadLangFile( const string & lang ){
		const string LangPath = "resources/lang/" + lang;
		string pair, key, value;
		ifstream fin(LangPath);
		
		while(getline(fin, pair)){
			regex_match(pair, sm, keyvaluePair);
			key = sm[1];
			value = sm[2];
			table[key] = value;
		}
		
		fin.close();
		
		SetLang();
	}
	
	void SetLang(){
		
		auto it = table.find("TitleScene_play");
		TitleScene_play = it->second;
		it = table.find("TitleScene_replay");
		TitleScene_replay = it->second;
		it = table.find("TitleScene_option");
		TitleScene_option = it->second;
		it = table.find("TitleScene_exit");
		TitleScene_exit = it->second;
		
	}
}