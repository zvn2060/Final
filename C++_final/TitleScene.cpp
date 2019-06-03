#include "TitleScene.hpp"
#include "Label.hpp"
#include "LOG.hpp"
#include "AudioHelper.hpp"


void TitleScene::Initialize(){
	
	flag = new Flag();
	index = 0;
	count = -1;
	AddNewObject( new Engine::Image( "background/title.png", 0, 0, 1280, 720 ) );
	
	btn[ 0 ] = new Engine::TextButton( "start", "FOT-SkipStd-B.otf", 48, 200, 400, 0xff, 0xff, 0xff, 0, 0 );
	btn[ 1 ] = new Engine::TextButton( "replay", "FOT-SkipStd-B.otf", 48, 200, 460, 0xff, 0xff, 0xff, 0, 0  );
	btn[ 2 ] = new Engine::TextButton( "option", "FOT-SkipStd-B.otf", 48, 200, 520, 0xff, 0xff, 0xff, 0, 0  );
	btn[ 3 ] = new Engine::TextButton( "quit", "FOT-SkipStd-B.otf", 48, 200, 580, 0xff, 0xff, 0xff, 0, 0  );
	for ( int i = 0 ; i < btnNum ; i++ ) {
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
