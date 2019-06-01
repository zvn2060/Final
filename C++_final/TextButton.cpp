#include "TextButton.hpp"

Engine::TextButton::TextButton(
		const std::string & text, const std::string & font, const int size, float x, float y, const char r, const char g, const char b,
		float anchorX, float anchorY ) : Label(text, font, size, x, y, r, g, b, 150, anchorX, anchorY), r(r), g(g), b(b){
	Point mouse = GameEngine::GetInstance().GetMousePosition();
	mouseIn = Collider::IsPointInRect(
			Point((mouse.x - Position.x) * GetTextWidth() / Size.x + Anchor.x * GetTextWidth(), (mouse.y - Position.y) * GetTextHeight() / Size.y + Anchor.y * GetTextHeight()),
			Point(x, y),
			Point(GetTextWidth(), GetTextHeight())
			);
}

void Engine::TextButton::SetOnClickCallback( std::function < void( void ) > onClickCallback ){
	OnClickCallback = onClickCallback;
}

void Engine::TextButton::OnMouseDown( int button, int mx, int my ){
	if ((button & 1) && mouseIn && Enabled) {
		if (OnClickCallback)
			OnClickCallback();
	}
}

void Engine::TextButton::OnMouseMove( int mx, int my ){
	mouseIn = Collider::IsPointInRect(
			Point(mx, my),
			Point(Position.x, Position.y),
			Point(GetTextWidth(), GetTextHeight())
	);
	if (!mouseIn || !Enabled) Color = al_map_rgba(r, g, b, 150);
	else Color = al_map_rgba(r, g, b, 255);
}
