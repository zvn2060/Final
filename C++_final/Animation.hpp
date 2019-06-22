#ifndef ANIMATION_HPP
#define ANIMATION_HPP
#include "Point.hpp"
#include "Image.hpp"
#include <map>
#include <vector>
#include <string>
#include <allegro5/allegro.h>

using namespace std;

class Animation {
private:
    vector<shared_ptr<ALLEGRO_BITMAP>> bmps;
    map<string, vector<shared_ptr<ALLEGRO_BITMAP>> > bmps_all;
    vector<Engine::Image*> imgs;
    unsigned int frame;
    unsigned int count = 0;
    int framerate;
    bool loop;
public:
    Animation() {
        this->bmps.push_back(Engine::Resources::GetInstance().GetBitmap("main/animation_not_loaded.png"));

        this->frame = 0;
        this->count = 0;
        this->framerate = 4;
        this->loop = true;
    }
    ~Animation() = default;
    void play(const std::string& name, bool loop = false, int framerate = 4) {
        this->frame = 0;
        this->count = 0;
        this->bmps = this->bmps_all[name];
        this->loop = loop;
        this->framerate = framerate;
    }

    void draw(Engine::Point position, Engine::Point anchor) {
        al_draw_bitmap(
        	this->bmps[this->frame].get(),
            position.x - anchor.x * al_get_bitmap_width(bmps[this->frame].get()),
            position.y - anchor.y * al_get_bitmap_height(bmps[this->frame].get()),
            0
        );


        this->count = (this->count + 1) % this->framerate;
        if (this->count == 0) {
            this->frame++;
            if (this->frame >= this->bmps.size()) {
                if (this->loop) {
                    this->frame = 0;
                }
                else {
                    this->frame = this->bmps.size() - 1;
                }
            }
        }

    }

    void add(const string& animationName, const vector<string>& files) {
        for (auto & file : files) {
            this->bmps_all[animationName].push_back(Engine::Resources::GetInstance().GetBitmap(file));
        }
    }
    
    void addCircular( float x, float y, float w, float winh, const string& file){
    	count = 0;
    	int imgh;
    	auto * img = new Engine::Image(file, 0, 0, w);
    	imgh = img->GetBitmapHeight();
    	
    	delete img;
    	
    	float ancy = imgh - 1.83 * winh;
    	
    	//int startx = -imgw + winw;
    
    	while(ancy <= imgh){
    		imgs.emplace_back(new Engine::Image(file, x, ancy, w, 0, 0, 1.0));
    		ancy += 5;
    	}
    }
	
    void circular(){
    	if(count == imgs.size()){
    		count = 0;
    	}
    	imgs.at(count)->Draw();
    	count++;
    }
    
};

#endif