#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_audio.h>
#include "LOG.hpp"
#include "Allegro5Exception.hpp"
#include "Resources.hpp"

//#include <mutex>
//std::mutex reMutex;

namespace Engine {
    const std::string Resources::bitmapPathPrefix = "resources/images/";
    const std::string Resources::fontPathPrefix = "resources/fonts/";
    const std::string Resources::samplePathPrefix = "resources/audios/";
    Resources::Resources() = default;
    Resources::~Resources() {
        try {
            ReleaseUnused();
        } catch (...) {}
    }

    void Resources::ReleaseUnused() {
        // A better way may be to count the memory usage and release unused resources
        // when the total resource memory exceeds a certain threshold. However, we'll
        // just keep it simple here and only release unused resources in GameEngine when
        // changing between scenes.
        for (auto it = bitmaps.begin(); it != bitmaps.end();) {
            if (it->second.use_count() == 1) {
                LOG(INFO) << "Destroyed Resource<image>";
                it = bitmaps.erase(it);
            } else ++it;
        }
        for (auto it = fonts.begin(); it != fonts.end();) {
            if (it->second.use_count() == 1) {
                LOG(INFO) << "Destroyed Resource<font>";
                it = fonts.erase(it);
            } else ++it;
        }

        for (auto it = samples.begin(); it != samples.end();) {
            if (it->second.use_count() == 1) {
                LOG(INFO) << "Destroyed Resource<audio>";
                it = samples.erase(it);
            } else ++it;
        }

    }

    // accessed by main thread
    // should be mutual exclusive because Resources is a singleton
    std::shared_ptr<ALLEGRO_BITMAP> Resources::GetBitmap(std::string name) {
        //std::unique_lock<std::mutex> lock(reMutex);
        if (bitmaps.count(name) != 0) {
            return bitmaps[name];
        }
        std::string bitmapPath = bitmapPathPrefix + name;
        ALLEGRO_BITMAP* bmp = al_load_bitmap(bitmapPath.c_str());
        if (!bmp) throw Allegro5Exception(("failed to load image: " + bitmapPath).c_str());
        LOG(INFO) << "Loaded Resource<image>: " << bitmapPath;
        bitmaps[name] = std::shared_ptr<ALLEGRO_BITMAP>(bmp, al_destroy_bitmap);
        return bitmaps[name];
    }

    // accessed by preload thread (second thread)
    void Resources::LoadBitmap(std::string name) {
        //std::unique_lock<std::mutex> lock(reMutex);
        if (bitmaps.count(name) != 0) {
            return ;
        }
        std::string bitmapPath = bitmapPathPrefix + name;

        // method 1
        //ALLEGRO_BITMAP* bmp = al_load_bitmap_flags(bitmapPath.c_str(), ALLEGRO_MEMORY_BITMAP);
        // method 2
        ALLEGRO_BITMAP* bmp = al_load_bitmap(bitmapPath.c_str());

        if (!bmp) throw Allegro5Exception(("failed to load image: " + bitmapPath).c_str());
        LOG(INFO) << "Loaded Resource<image>: " << bitmapPath;
        bitmaps.insert({ name, std::shared_ptr<ALLEGRO_BITMAP>(bmp, al_destroy_bitmap) });

        // sleep for nothing but you can observe multi-thread preload more obviously
        //std::chrono::milliseconds timespan(50);
        //std::this_thread::sleep_for(timespan);
    }
    void Resources::convertBitmap(bool* bitmapConvertCompleted) {
        // method 1
        for (auto & bitmap : this->bitmaps) {
            bitmap.second = std::shared_ptr<ALLEGRO_BITMAP>(al_clone_bitmap(bitmap.second.get()), al_destroy_bitmap);
        }

        // method 2
        //for (auto it = this->bitmaps.begin(); it != this->bitmaps.end(); it++) {
        //    al_convert_bitmap(it->second.get());
        //}

        // method 3
        //al_convert_memory_bitmaps();

        *bitmapConvertCompleted = true;
    }


    std::shared_ptr<ALLEGRO_BITMAP> Resources::GetBitmap(const std::string& name, int width, int height) {
        std::string idx = name + '?' + std::to_string(width) + 'x' + std::to_string(height);
        if (bitmaps.count(idx) != 0)
            return bitmaps[idx];
        std::string bitmapPath = bitmapPathPrefix + name;
        ALLEGRO_BITMAP* bmp = al_load_bitmap(bitmapPath.c_str());
        if (!bmp) throw Allegro5Exception(("failed to load image: " + bitmapPath).c_str());

        ALLEGRO_BITMAP *resized_bmp = al_create_bitmap(width, height);
        ALLEGRO_BITMAP *prev_target = al_get_target_bitmap();
        if (!resized_bmp) throw Allegro5Exception(("failed to create bitmap when creating resized image: " + bitmapPath).c_str());
        al_set_target_bitmap(resized_bmp);
        al_draw_scaled_bitmap(bmp, 0, 0,
            al_get_bitmap_width(bmp),
            al_get_bitmap_height(bmp),
            0, 0, width, height, 0);
        al_set_target_bitmap(prev_target);
        al_destroy_bitmap(bmp);

        LOG(INFO) << "Loaded Resource<image>: " << bitmapPath << " scaled to " << width << "x" << height;
        bitmaps[idx] = std::shared_ptr<ALLEGRO_BITMAP>(resized_bmp, al_destroy_bitmap);
        return bitmaps[idx];
    }
    std::shared_ptr<ALLEGRO_FONT> Resources::GetFont(const std::string& name, int fontSize) {
        std::string idx = name + '?' + std::to_string(fontSize);
        if (fonts.count(idx) != 0)
            return fonts[idx];
        std::string fontPath = fontPathPrefix + name;
        ALLEGRO_FONT* font = al_load_font(fontPath.c_str(), fontSize, 0);
        if (!font)
            throw Allegro5Exception(("failed to load font: " + fontPath).c_str());
        LOG(INFO) << "Loaded Resource<font>: " << fontPath << " with size " << fontSize;
        fonts[idx] = std::shared_ptr<ALLEGRO_FONT>(font, al_destroy_font);
        return fonts[idx];
    }
    std::shared_ptr<ALLEGRO_SAMPLE> Resources::GetSample(const std::string& name) {
        if (samples.count(name) != 0)
            return samples[name];
        std::string samplePath = samplePathPrefix + name;
        ALLEGRO_SAMPLE* sample = al_load_sample(samplePath.c_str());
        if (!sample)
            throw Allegro5Exception(("failed to load audio: " + samplePath).c_str());
        LOG(INFO) << "Loaded Resource<audio>: " << samplePath;
        samples[name] = std::shared_ptr<ALLEGRO_SAMPLE>(sample, al_destroy_sample);
        return samples[name];
    }
    Resources& Resources::GetInstance() {
        //std::unique_lock<std::mutex> lock(reMutex);
        // The classic way to lazy initialize a Singleton.
        static Resources instance;
        return instance;
    }
}
