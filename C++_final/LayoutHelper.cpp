#include "LayoutHelper.hpp"
#include "GameEngine.hpp"

namespace Engine{
	float LayoutHelper::AlignLeft( float margin ){
		return margin;
	}
	
	float LayoutHelper::AlignRight( float margin ){
		return GameEngine::GetInstance().GetScreenWidth() - margin;
	}
	
	float LayoutHelper::AlignTop( float margin ){
		return margin;
	}
	
	float LayoutHelper::AlignBottom( float margin ){
		return GameEngine::GetInstance().GetScreenHeight() - margin;
	}
	
	float LayoutHelper::HorizontalCenter( float margin ){
		return GameEngine::GetInstance().GetScreenWidth() / 2 + margin;
	}
	
	float LayoutHelper::VerticalCenter( float margin ){
		return GameEngine::GetInstance().GetScreenHeight() / 2 + margin;
	}
	
	float LayoutHelper::HorizontalRatio( float ratio ){
		return GameEngine::GetInstance().GetScreenWidth() * ratio;
	}
	
	float LayoutHelper::VeticalRatio( float ratio ){
		return GameEngine::GetInstance().GetScreenHeight() * ratio;
	}
}