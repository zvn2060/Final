#include "TitleScene.hpp"
#include "Label.hpp"
#include "LOG.hpp"
#include "AudioHelper.hpp"


void TitleScene::Initialize(){
	
	this->flag = new Flag();
	this->index = 0;
	this->count = -1;
	AddNewObject( new Engine::Image( "background/title.png", 0, 0, 1280, 720 ) );
	this->btn[ 0 ] = new Engine::Label( "start", "FOT-SkipStd-B.otf", 48, 200, 400, 255, 255, 255, 255, 0, 0 );
	this->btn[ 1 ] = new Engine::Label( "replay", "FOT-SkipStd-B.otf", 48, 200, 460, 255, 255, 255, 150, 0, 0 );
	this->btn[ 2 ] = new Engine::Label( "option", "FOT-SkipStd-B.otf", 48, 200, 520, 255, 255, 255, 150, 0, 0 );
	this->btn[ 3 ] = new Engine::Label( "quit", "FOT-SkipStd-B.otf", 48, 200, 580, 255, 255, 255, 150, 0, 0 );
	for ( int i = 0 ; i < this->btnNum ; i++ ) {
		AddNewObject( this->btn[ i ] );
	}
	AddNewObject(
			new Engine::Label( "some background", "FOT-SkipStd-B.otf", 60, 640, 300, 240, 240, 215, 150, 0.5, 0.5 ) );
	AddNewObject(
			new Engine::Label( "and maybe some effects", "FOT-SkipStd-B.otf", 60, 640, 360, 240, 240, 215, 150, 0.5, 0.5 ) );
	
	AudioHelper::PlayBGM("BGM/title.ogg");
}

void TitleScene::OnKeyDown( int keycode ){
	
	if ( keycode == ALLEGRO_KEY_UP ) {
		this->flag->setFlag( this->FLAG_KEY_UP );
		
	}
	if ( keycode == ALLEGRO_KEY_DOWN ) {
		this->flag->setFlag( this->FLAG_KEY_DOWN );
		
	}
	
	if ( keycode == ALLEGRO_KEY_Z ) {
		switch ( this->index ) {
			case 0:
				Engine::GameEngine::GetInstance().ChangeScene( "main" );
				break;
			case 2:
				Engine::GameEngine::GetInstance().ChangeScene( "setting" );
				break;
			case 3:
				exit( 0 );
				break;
		}
	}
}

void TitleScene::OnKeyUp( int keycode ){
	if ( keycode == ALLEGRO_KEY_UP ) {
		
		this->flag->clearFlag( this->FLAG_KEY_UP );
		this->count = -1;
	}
	if ( keycode == ALLEGRO_KEY_DOWN ) {
		
		this->flag->clearFlag( this->FLAG_KEY_DOWN );
		this->count = -1;
	}
}

void TitleScene::Update( float deltaTime ){
	if ( this->flag->isFlagSet( this->FLAG_KEY_DOWN ) || this->flag->isFlagSet( this->FLAG_KEY_UP ) ) {
		this->count = ( this->count + 1 ) % 10;
		if ( this->count == 0 ) {
			int prev = this->index;
			AudioHelper::PlayAudio( "btn_switch.ogg" );
			this->index = this->flag->isFlagSet( this->FLAG_KEY_DOWN ) ? ( this->index + 1 ) % this->btnNum :
						  this->index - 1;
			if ( this->index < 0 )
				this->index += this->btnNum;
			this->btn[ this->index ]->Color = al_map_rgba( 255, 255, 255, 255 );
			this->btn[ prev ]->Color = al_map_rgba( 255, 255, 255, 150 );
		}
	}
}