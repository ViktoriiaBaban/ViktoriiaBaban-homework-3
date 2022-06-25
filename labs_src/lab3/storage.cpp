#include "storage.h"
#include <filesystem>
#include <fstream>

Storage::Storage(JobObject jobObject, int storage_number) {
    name = jobObject.getName() + "_" + std::to_string(storage_number);
}
Storage::Storage(std::vector<JobObject> jobObjects, int storage_number) {
    for (auto obj: jobObjects) {
        name = obj.getName() + "_" + std::to_string(storage_number);
    }
}

std::string Storage::getName() {
    return this->name;
}
std::vector<JobObject> Storage::getFiles() {
    return this->list_of_files;
}

