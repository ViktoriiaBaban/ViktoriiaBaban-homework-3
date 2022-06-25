#pragma once

#include <vector>
#include <algorithm>

#include "job_object.h"
#include "restore_point.h"
#include "repository.h"

class BackupJob {
public:
    BackupJob(const std::string& backup_path = "/", const std::string& type_storage = "split");

    void addOneJobObject(const JobObject &job);
    void addManyJobObjects(std::vector<JobObject> jobObjects);
    void removeOneJobObject(const JobObject &job);
    std::vector<RestorePoint> getRestorePoints();
    RestorePoint runBackupJob();

private:
    std::string storage_type;
    std::vector<JobObject> job_objects;
    std::vector<RestorePoint> restore_points;
    Repository *rep;
};
