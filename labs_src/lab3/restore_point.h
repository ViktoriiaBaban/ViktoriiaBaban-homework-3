#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>

#include "storage.h"
#include "job_object.h"

class RestorePoint {
public:
    RestorePoint(const int &num);

    void addJobObjects(std::vector<JobObject> new_job_objects);
    void addStorages(std::vector<Storage> new_storages);
    void addStorage(const Storage& new_storage);

    std::vector<JobObject> getJobObjects();
    std::vector<Storage> getStorages();
    std::time_t getTime() const;
    std::string getTimeAsString() const;

private:
    int number;
    std::vector<Storage> storages;
    std::vector<JobObject> jobObjects;
    std::time_t time_create;
};
