#include "Fragment.hpp"
#include "LOG.hpp"

void Fragment::EmbedAt( Engine::IScene * scene ){
	EmbeddingScene = scene;
}

/// FIXME Not safe (Potential Memory Leak)

void Fragment::AddNewFragemt(
		const std::string & name, const std::function < std::list < Engine::IObject * > * (  ) >& Construct ){
		auto ls = Construct();
		Engine::LOG(Engine::DEBUG)<<"A";
		for(auto & l : *ls){
			l->Visible = false;
		}
		Map[name] = ls;
}

void Fragment::ChangeFragment( const std::string & name ){
	
	auto it = Map.find(activefrag);
	auto ls = it->second;
	if(!activefrag.empty()) {
		for (auto & l : *ls) {
			l->Visible = false;
		}
	}
	
	activefrag = name;
	it = Map.find(activefrag);
	if(it != Map.end()){
		ls = it->second;
		for(auto & l : *ls){
			l->Visible = true;
		}
	}else{
		throw std::invalid_argument("Cannot change to a unknown fragment.");
	}
}

void Fragment::Terminate(){
	for(auto const& it : Map){
		delete it.second;
	}
}