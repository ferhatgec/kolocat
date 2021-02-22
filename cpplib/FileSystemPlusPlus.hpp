/*# MIT License
# Cleaned version of FileSystemPlusPlus library.
# Copyright (c) 2020-2021 Ferhat Geçdoğan All Rights Reserved.
# Distributed under the terms of the MIT License.
#*/

#ifndef FILE_SYSTEM_PLUS_PLUS_HPP
#define FILE_SYSTEM_PLUS_PLUS_HPP

#include <cstring>
#include <iostream>
#include <pwd.h>
#include <dirent.h>
#include <fstream>
#include <sys/stat.h>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#define FS_PLUS_PLUS_VERSION "0.2-beta-1"

namespace fsplusplus {
	static std::string GetCurrentWorkingDir(void) {
  		char buff[FILENAME_MAX];
  		
        GetCurrentDir( buff, FILENAME_MAX );
  		std::string current_working_dir(buff);

  		return current_working_dir;
	}

	static bool IsExistFile(std::string path) {
        struct stat buffer;
    	return (stat(path.c_str(), &buffer) == 0);
	}
}

#endif // FILE_SYSTEM_PLUS_PLUS_HPP
