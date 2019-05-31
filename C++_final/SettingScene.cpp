#include "SettingScene.hpp"
#include "AudioHelper.hpp"

void SettingScene::Initialize(){
	this->flag = new Flag();
	this->index = 0;
	this->count = -1;
	AddNewObject( new Engine::Image( "background/title.png", 0, 0, 1280, 720 ) );
	AudioHelper::PlayBGM("BGM/title.ogg");
	
	btn[0] = new Engine::Label("sound", "FOT-SkipStd-B.otf", 48, 100, 80, 255, 255, 255, 150, 0.5, 0.5);
	btn[1] = new Engine::Label("display", "FOT-SkipStd-B.otf", 48, 300, 80, 255, 255, 255, 150, 0.5, 0.5);
	btn[2] = new Engine::Label("language", "FOT-SkipStd-B.otf", 48, 550, 80, 255, 255, 255, 150, 0.5, 0.5);
	btn[3] = new Engine::Label("back", "FOT-SkipStd-B.otf", 48, 200, 600, 255, 255, 255, 150, 0.5, 0.5);
	for ( int i = 0 ; i < btnNum ; i++ ) {
		AddNewObject( btn[ i ] );
	}

}


void SettingScene::OnKeyDown( int keycode ){
	
	if ( keycode == ALLEGRO_KEY_UP ) {
		this->flag->setFlag( this->FLAG_KEY_UP );
		
	}
	if ( keycode == ALLEGRO_KEY_DOWN ) {
		this->flag->setFlag( this->FLAG_KEY_DOWN );
		
	}
	
	if ( keycode == ALLEGRO_KEY_Z ) {
		switch ( this->index ) {
			case 0:
				
				break;
			case 2:
				
				break;
			case 3:
				Engine::GameEngine::GetInstance().ChangeScene( "title" );
				break;
		}
	}
}

void SettingScene::OnKeyUp( int keycode ){
	if ( keycode == ALLEGRO_KEY_UP ) {
		AudioHelper::PlayAudio( "btn_switch.ogg" );
		this->flag->clearFlag( this->FLAG_KEY_UP );
		this->count = -1;
	}
	if ( keycode == ALLEGRO_KEY_DOWN ) {
		AudioHelper::PlayAudio( "btn_switch.ogg" );
		this->flag->clearFlag( this->FLAG_KEY_DOWN );
		this->count = -1;
	}
}

void SettingScene::Update( float deltaTime ){
	if ( this->flag->isFlagSet( this->FLAG_KEY_DOWN ) || this->flag->isFlagSet( this->FLAG_KEY_UP ) ) {
		this->count = ( this->count + 1 ) % 10;
		if ( this->count == 0 ) {
			int prev = this->index;
			this->index = this->flag->isFlagSet( this->FLAG_KEY_DOWN ) ? ( this->index + 1 ) % this->btnNum :
						  this->index - 1;
			if ( this->index < 0 )
				this->index += this->btnNum;
			this->btn[ this->index ]->Color = al_map_rgba( 255, 255, 255, 255 );
			this->btn[ prev ]->Color = al_map_rgba( 255, 255, 255, 150 );
		}
	}
}