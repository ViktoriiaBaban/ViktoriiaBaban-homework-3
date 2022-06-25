#pragma once

#include <vector>
#include <filesystem>
#include <fstream>
#include <sys/stat.h>

#include "restore_point.h"
#include "../libzippp-master/src/libzippp.h"
using namespace libzippp;

class Repository {
public:
    void set_path(const std::string& backup_path);
    std::string getPath();

    void save_split(RestorePoint& restorePoint, const std::string& arch_name);
    void save_single(RestorePoint& restorePoint, const std::string& arch_name);

private:
    std::string path;
};
