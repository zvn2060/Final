#ifndef FRAGMENT_HPP
#define FRAGMENT_HPP

#include "IScene.hpp"
#include "functional"
#include <map>
#include <list>

class Fragment{
private:
	std::map<std::string, std::list<Engine::IObject*> * > Map;
	Engine::IScene* EmbeddingScene;
	std::string activefrag = "";
public:
	void EmbedAt(Engine::IScene* scene);
	void AddNewFragemt(const std::string& name, const std::function<std::list<Engine::IObject*> * ()>& Construct);
	void ChangeFragment(const std::string& name);
	void Terminate();
};

#endif //FINALPROJECT_FRAGMENT_HPP
