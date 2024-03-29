#include "Fragment.hpp"
#include "LOG.hpp"

void Fragment::EmbedAt( Engine::IScene * scene ){
    EmbeddingScene = scene;
}

/// FIXME Not safe (Potential Memory Leak)

void Fragment::AddNewFragment(
		const std::string & name, const std::function < std::list < Engine::IObject * > *() > & Construct ){
        auto ls = Construct();
        for(auto & l : *ls){
            l->Visible = false;
        }
        Map[name] = ls;
        activefrag = name;
}

bool Fragment::ChangeFragment( const std::string & name ){
    if(activefrag == name){
    	return false;
    }
    auto it = Map.find(activefrag);
    if(!activefrag.empty()) {
        auto ls = it->second;
        for (auto & l : *ls) {
            l->Visible = false;
        }
    }
    
    activefrag = name;
    it = Map.find(activefrag);
    if(it != Map.end()){
        auto ls = it->second;
        for(auto & l : *ls){
            l->Visible = true;
        }
    }else{
        throw std::invalid_argument("Cannot change to a unknown fragment.");
    }
    return true;
}

void Fragment::Terminate(){
    for(auto const& it : Map){
        delete it.second;
    }
}

