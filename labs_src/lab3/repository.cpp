#include "repository.h"

void Repository::set_path(const std::string& backup_path) {
    path = backup_path + "backups/";
    std::cout << (path) << std::endl;
    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }
}

std::string Repository::getPath() {
    return this->path;
}

void RepositoryForSingleStorages::save(RestorePoint& restorePoint, const std::string& rep_name) {

    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }

    ZipArchive zip_file(this->path + rep_name + "_" + restorePoint.getTimeAsString() + "/" + rep_name + ".zip");
    zip_file.open(ZipArchive::Write);

    for (auto storage : restorePoint.getStorages()) {
        const char *textData = "It's test text. Have a nice day!"; // !
        zip_file.addData(storage.getName(), textData, 12);
    }

    zip_file.close();
}

void RepositoryForSplitStorages::save(RestorePoint& restorePoint, const std::string& rep_name) {

    if (!std::filesystem::exists(path)) {
        std::filesystem::create_directory(path);
    }
    for (auto storage : restorePoint.getStorages()) {

        ZipArchive zip_file(this->path + rep_name + "_" + restorePoint.getTimeAsString() + "/" + storage.getName() + ".zip");
        zip_file.open(ZipArchive::Write);
        auto *textData = "It's test text. Have a nice day!"; // !
        zip_file.addData(storage.getName(), textData, 12);
        zip_file.close();
    }
}

RepositoryForSplitStorages::RepositoryForSplitStorages(std::string path) {
this->path = path;
}

RepositoryForSingleStorages::RepositoryForSingleStorages(std::string path) {
    this->path = path;
}
