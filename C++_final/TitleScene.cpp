#include "TitleScene.hpp"
#include "Label.hpp"
#include "LOG.hpp"
#include "AudioHelper.hpp"
#include "LayoutHelper.hpp"
#include "MultiLang.hpp"


void TitleScene::Initialize(){
    SetBackGround("background/title.png");
	std::string text[4]{
		MultiLang::TitleScene_play,
		MultiLang::TitleScene_replay,
		MultiLang::TitleScene_option,
		MultiLang::TitleScene_exit
	};
    for ( int i = 0 ; i < btnNum ; i++ ) {
    	btn [ i ] = new Engine::TextButton(
    			text[i], "FOT-SkipStd-B.otf", 48,
    			Engine::LayoutHelper::AlignLeft(200),
    			Engine::LayoutHelper::AlignBottom( 320 - 60 * i ),
    			0xff, 0xff, 0xff, 0, 0 );
    	
        btn[i]->SetOnClickCallback(std::bind(&TitleScene::Onclick, this, i));
        AddNewControlObject( btn[i] );
    }
    AudioHelper::PlayBGM("BGM/title.ogg");
}

void TitleScene::Onclick(int btnnum) {
    switch (btnnum){
        case 0 :
            Engine::GameEngine::GetInstance().ChangeScene("main");
            break;
        case 1 :
            //Engine::GameEngine::GetInstance().ChangeScene("replay");
            break;
        case 2 :
            Engine::GameEngine::GetInstance().ChangeScene("setting");
            break;
        case 3 :
            exit(0);
        default:
            ;
    }
}
