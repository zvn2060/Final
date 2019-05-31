#ifndef AUDIOHELPER_HPP
#define AUDIOHELPER_HPP
#include "allegro5/allegro_acodec.h"
class AudioHelper {
private:
	AudioHelper() = default;
	enum {
	  SE_MENU_MOVE
	} SE;
public:
	static float BGMVolume;
	static float SFXVolume;
	static ALLEGRO_SAMPLE* GetSample(const std::string& audio);
	static ALLEGRO_SAMPLE_ID PlayAudio(const std::string& audio);
	static ALLEGRO_SAMPLE_ID PlayBGM(const std::string& audio);
	static void StopBGM(ALLEGRO_SAMPLE_ID sample);
};
#endif // AUDIOHELPER_HPP
