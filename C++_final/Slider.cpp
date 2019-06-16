#include <utility>

#include <utility>

#include "Slider.hpp"
#include <algorithm>

Slider::Slider( const std::string& tag, const std::string& font, int size, float x, float y, float w, float h , char r, char g, char b, char a) :
ImageButton( "slider/slider.png", "slider/slider-blue.png", x, y ),
Bar( "slider/bar.png", x + w / 2, y + h / 2, w, h , 0.5, 0.5),
End1( "slider/end.png", x, y + h / 2, 0, 0, 0.5, 0.5 ),
End2( "slider/end.png", x + w, y + h / 2, 0, 0, 0.5, 0.5 ),
Tag(tag, font, size, x - w / 3, y + h / 2 + 20, r, g, b, a, 0.5, 0.5){
	Position.x += w;
	Position.y += h / 2;
	Anchor = Engine::Point( 0.5, 0.5 );
}

void Slider::Draw() const {

	Bar.Draw();
	End1.Draw();
	End2.Draw();
	Tag.Draw();
	ImageButton::Draw();
}

void Slider::SetOnValueChangedCallback( std::function < void( float value ) > onValueChangedCallback ){
	OnValueChangedCallback = std::move(onValueChangedCallback);
}

void Slider::SetValue( float value ){
	if ( value != this->value ) {
		Position.x = value * ( End2.Position.x - End1.Position.x ) + End1.Position.x;
		this->value = value;
		OnValueChangedCallback( value );
	}
}

void Slider::OnMouseDown( int button, int mx, int my ){
	if ( ( button & 1 ) && mouseIn && Enabled ) {
		Down = true;
	}
}

void Slider::OnMouseUp( int button, int mx, int my ){
	if ( ( button & 1 ) && !mouseIn ){
		SetValue( ( Position.x - End1.Position.x ) / ( End2.Position.x - End1.Position.x ) );
		Down = false;
	}

}

void Slider::OnMouseMove( int mx, int my ){
	
	mouseIn = Engine::Collider::IsPointInBitmap(
			Engine::Point( ( mx - Position.x ) * GetBitmapWidth() / Size.x + Anchor.x * GetBitmapWidth(),
						   ( my - Position.y ) * GetBitmapHeight() / Size.y + Anchor.y * GetBitmapHeight() ), bmp );
	
	if ( ( !mouseIn || !Enabled ) && !Down )
		bmp = imgOut;
	else {
		bmp = imgIn;
		if ( Down && End1.Position.x <= mx && mx <= End2.Position.x ) {
			Position.x = mx;
		} else {
			if ( End1.Position.x > mx ) {
				Position.x = End1.Position.x;
			} else if ( mx > End2.Position.x ) {
				Position.x = End2.Position.x;
			}
		}
	}
}

void Slider::Enable(){
	Enabled = true;
}

void Slider::Disable(){
	Enabled = false;
}


