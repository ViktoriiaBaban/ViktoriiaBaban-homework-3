#include "backup_job.h"

BackupJob::BackupJob(const std::string& backup_path, const std::string& type_storage) {
    if (type_storage == "split"){
        rep_split->set_path(backup_path);
        storage_type = type_storage;
    } else if (type_storage == "single") {
        rep_single->set_path(backup_path);
        storage_type = type_storage;
    }else{
        throw std::runtime_error("Incorrect type.");
    }
}

void BackupJob::addOneJobObject(const JobObject &job) {
    this->job_objects.push_back(job);
}

void BackupJob::addManyJobObjects(std::vector<JobObject> jobs) {
    this->job_objects.insert(this->job_objects.end(), jobs.begin(), jobs.end());
}

void BackupJob::removeOneJobObject(const JobObject &job) {
    this->job_objects.erase(std::remove(this->job_objects.begin(), this->job_objects.end(), job),
                            this->job_objects.end());

}

std::vector<RestorePoint> BackupJob::getRestorePoints() {
    return this->restore_points;
}

RestorePoint BackupJob::runBackupJob() {
    int backup_number = restore_points.size() + 1;
    RestorePoint restorePoint(backup_number);
    for(auto job_object : job_objects) {
        Storage storage(job_object, backup_number);
        restorePoint.addStorage(storage);
    }
    restore_points.push_back(restorePoint);
    if (storage_type == "split"){
        rep_split->save(restorePoint, "backup_" + std::to_string(backup_number) + "_" + storage_type);
    } else {
        rep_single->save(restorePoint, "backup_" + std::to_string(backup_number) + "_" + storage_type);
    }
    return restorePoint;
}
