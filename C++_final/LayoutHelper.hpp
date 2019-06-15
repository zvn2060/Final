#ifndef LAYOUTHELPER_HPP
#define LAYOUTHELPER_HPP
/// <summary>
/// A Tool class for design layout.
/// </summary>

namespace Engine{
	class LayoutHelper{
	public:
		static float AlignLeft( float margin = 0 );
		
		static float AlignRight( float margin = 0 );
		
		static float AlignTop( float margin = 0 );
		
		static float AlignBottom( float margin = 0 );
		
		static float HorizontalCenter( float margin = 0 );
		
		static float VerticalCenter( float margin = 0 );
		
		static float HorizontalRatio(float ratio);
		static float VeticalRatio(float ratio);
	};
}
#endif //LAYOUTHELPER_HPP
