#pragma once

#include <vector>

#include "storage.h"
#include "repository.h"
#include "job_object.h"
/*
class RestorePoint {
private:
    std::vector<JobObject> jobObjects;
    std::vector<Storage> storages;
    std::time_t time_create;
    std::string name;
public:
    void setTimeCreate();
    ~RestorePoint();

};
*/

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
