#include "restore_point.h"


RestorePoint::RestorePoint(const int& num) {
    this->number = num;
    this->time_create = time(nullptr);
}

void RestorePoint::addJobObjects(std::vector<JobObject> new_job_objects) {
    this->jobObjects.insert(this->jobObjects.end(), new_job_objects.begin(), new_job_objects.end());
}

void RestorePoint::addStorages(std::vector<Storage> new_storages) {
    this->storages.insert(this->storages.end(), new_storages.begin(), new_storages.end());
}

void RestorePoint::addStorage(const Storage& new_storage) {
    storages.push_back(new_storage);
}

std::vector<JobObject> RestorePoint::getJobObjects() {
    return this->jobObjects;
}

std::vector<Storage> RestorePoint::getStorages() {
    return this->storages;
}

std::time_t RestorePoint::getTime() const {
    return this->time_create;
}
std::string RestorePoint::getTimeAsString() const {
    auto time = this->getTime();
    std::stringstream s;
    s<< mktime(&*std::localtime(&time));
    return s.str();
}

