#ifndef TEXTBUTTON_HPP
#define TEXTBUTTON_HPP
#include <memory>
#include <functional>
#include <allegro5/allegro.h>
#include "IControl.hpp"
#include "Label.hpp"
#include "Collider.hpp"
#include "GameEngine.hpp"

namespace Engine {
	/// <summary>
	/// A clickable button, changes image when mouse move.
	/// </summary>
	class TextButton: public Label, public IControl {
	private:
		char r, g, b;
		int x, y;
		std::string audiopath;
	protected:
		// Determines whether mouse is in the button.
		bool mouseIn = false;
		// The smart pointer that points to bitmap for mouse-out display.
		// The smart pointer that points to bitmap for mouse-in display.
		// The callback function to call when button clicked.
		std::function<void()> OnClickCallback;
	public:
		// Whether the button can be pressed.
		bool Enabled = true;
		/// <summary>
		/// Construct a image object.
		/// </summary>
		/// <param name="img">The mouse-out image path in 'resources/images/'</param>
		/// <param name="imgIn">The mouse-in image path in 'resources/images/'</param>
		/// <param name="x">X-coordinate.</param>
		/// <param name="y">Y-coordinate.</param>
		/// <param name="w">Width of the image, 0 indicates original size.</param>
		/// <param name="h">Height of the image, 0 indicates original size.</param>
		/// <param name="anchorX">The centerX of the object. (0, 0) means top-left, while (1, 0) means top-right.</param>
		/// <param name="anchorY">The centerY of the object. (0, 1) means bottom-left, while (1, 1) means bottom-right.</param>
		explicit TextButton( const std::string& text, const std::string& font, const int size, float x, float y, const char r = 255, const char g = 255,const char b = 255, float anchorX = 0, float anchorY = 0);
		/// <summary>
		/// Set the callback function when clicked.
		/// </summary>
		/// <param name="onClickCallback"></param>
		void SetOnClickCallback(std::function<void(void)> onClickCallback);
		/// <summary>
		/// Delegated from scene when mouse button down.
		/// </summary>
		/// <param name="button">The button pressed.</param>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		void OnMouseDown(int button, int mx, int my) override;
		/// <summary>
		/// Delegated from scene when mouse move.
		/// </summary>
		/// <param name="mx">Mouse x coordinate in window space.</param>
		/// <param name="my">Mouse y coordinate in window space.</param>
		void OnMouseMove(int mx, int my) override;
		/// <summary>
		/// Set the audio when mouse on it
		/// </summary>
		/// <param name="path">The filepath of the audio.</param>
		void SetMouseInSFX(const std::string& path);
		
	};
}
#endif //TEXTBUTTON_HPP
