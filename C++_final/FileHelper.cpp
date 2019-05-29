#include "LOG.hpp"
#include "FileHelper.hpp"

std::vector <std::string> FileHelper::GetFiles( const std::string & dir ){
	ALLEGRO_FS_ENTRY* directory = al_create_fs_entry(dir.c_str());
	std::vector<std::string> filelist;
	if(al_open_directory(directory)){
		ALLEGRO_FS_ENTRY* file;
		while((file = al_read_directory(directory))){
			filelist.emplace_back(std::string(al_get_fs_entry_name(file)));
			al_destroy_fs_entry(file);
		}
	} else {
		Engine::LOG(Engine::INFO)<<"read files error";
	}
	return filelist;
}