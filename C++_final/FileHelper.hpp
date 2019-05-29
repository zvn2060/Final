#ifndef FINALPROJECT_FILEHELPER_HPP
#define FINALPROJECT_FILEHELPER_HPP

#include "allegro5/allegro.h"
#include <vector>
#include <string>
class FileHelper{
private:

public:
	static std::vector<std::string> GetFiles(const std::string& dir);
};


#endif //FINALPROJECT_FILEHELPER_HPP
