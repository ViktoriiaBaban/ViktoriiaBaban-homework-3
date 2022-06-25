#pragma once

#include <vector>
#include <filesystem>
#include <fstream>
#include <sys/stat.h>

#include "restore_point.h"
#include "../libzippp-master/src/libzippp.h"
using namespace libzippp;

struct Repository {
public:
    virtual void set_path(const std::string& backup_path);
    virtual void save(RestorePoint& restorePoint, const std::string& arch_name) = 0;
    virtual std::string getPath();
protected:
    std::string path;
};

class RepositoryForSplitStorages : public Repository {
public:
    RepositoryForSplitStorages(std::string path);
    void save(RestorePoint& restorePoint, const std::string& rep_name) override;
};

class RepositoryForSingleStorages : public Repository {
public:
    RepositoryForSingleStorages(std::string path);
    void save(RestorePoint& restorePoint, const std::string& rep_name) override;
};