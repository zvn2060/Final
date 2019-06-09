#include "LOG.hpp"
#include "FileHelper.hpp"
#include <regex>

void purefilename(std::string& path){
    const size_t last_slash_idx = path.find_last_of("\\/");
    if (std::string::npos != last_slash_idx)
    {
        path.erase(0, last_slash_idx + 1);
    }

// Remove extension if present.
    const size_t period_idx = path.rfind('.');
    if (std::string::npos != period_idx)
    {
        path.erase(period_idx);
    }
}

std::vector <std::string> FileHelper::GetFiles( const std::string & dir ){

	ALLEGRO_FS_ENTRY* directory = al_create_fs_entry(dir.c_str());
	std::vector<std::string> filelist;
	std::string tmp;
	if(al_open_directory(directory)){
		ALLEGRO_FS_ENTRY* file;
		while((file = al_read_directory(directory))){
    	    tmp = al_get_fs_entry_name(file);
    	    purefilename(tmp);
		    filelist.emplace_back(tmp);
			al_destroy_fs_entry(file);
		}
	} else {
		Engine::LOG(Engine::INFO)<<"read files error";
	}
	return filelist;
}