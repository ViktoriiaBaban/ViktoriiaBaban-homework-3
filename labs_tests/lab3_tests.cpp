#include <gtest/gtest.h>

#include "lab3/job_object.h"
#include "lab3/backup_job.h"
#include "lab3/repository.h"
#include "lab3/restore_point.h"
#include "lab3/storage.h"

TEST(CreateBackups, TwoRestorePointsAndThreeStoragesCreated) {
    std::string path = std::filesystem::current_path().string()+"/";
    BackupJob backupJob(path, "split");

    JobObject FileA("FILE_A"), FileB("FILE_B");
    backupJob.addOneJobObject(FileA);
    backupJob.addOneJobObject(FileB);

    RestorePoint rp_1 = backupJob.runBackupJob();

    backupJob.removeOneJobObject(FileB);
    RestorePoint rp_2 = backupJob.runBackupJob();

    auto jobs1 = rp_1.getJobObjects(), jobs2 = rp_2.getJobObjects();
    auto storages1 = rp_1.getStorages(), storages2 = rp_2.getStorages();
    auto points = backupJob.getRestorePoints();

    ASSERT_EQ(jobs1.size() + jobs2.size(), 3);
    ASSERT_EQ(storages1.size() + storages2.size(), 3);
    ASSERT_EQ(points.size(), 2);
}


