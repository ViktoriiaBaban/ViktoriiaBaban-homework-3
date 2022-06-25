#pragma once

#include <iostream>
#include <vector>
#include "job_object.h"

class Storage {
private:
    std::string name;
    std::vector<JobObject> list_of_files;
public:
    Storage(JobObject jobObject, int storage_number);
    Storage(std::vector<JobObject> jobObjects, int storage_number);

    std::string getName();
    std::vector<JobObject> getFiles();
};