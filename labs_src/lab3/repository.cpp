#include "repository.h"

void Repository::set_path(const std::string& backup_path) {
    _path = backup_path + "backups/";
    std::cout << (_path) << std::endl;
    if (!std::filesystem::exists(_path)) {
        std::filesystem::create_directory(_path);
    }
}

std::string Repository::getPath() {
    return this->_path;
}

void RepositoryForSingleStorages::save(RestorePoint& restorePoint, const std::string& rep_name) {

    if (!std::filesystem::exists(_path)) {
        std::filesystem::create_directory(_path);
    }

    ZipArchive zip_file(this->getPath() + rep_name + "_" + restorePoint.getTimeAsString() + "/" + rep_name + ".zip");
    zip_file.open(ZipArchive::Write);

    for (auto storage : restorePoint.getStorages()) {
        const char *textData = "It's test text. Have a nice day!"; // !
        zip_file.addData(storage.getName(), textData, 12);
    }

    zip_file.close();
}

void RepositoryForSplitStorages::save(RestorePoint& restorePoint, const std::string& rep_name) {

    if (!std::filesystem::exists(_path)) {
        std::filesystem::create_directory(_path);
    }
    for (auto storage : restorePoint.getStorages()) {

        ZipArchive zip_file(this->getPath() + rep_name + "_" + restorePoint.getTimeAsString() + "/" + storage.getName() + ".zip");
        zip_file.open(ZipArchive::Write);
        auto *textData = "It's test text. Have a nice day!"; // !
        zip_file.addData(storage.getName(), textData, 12);
        zip_file.close();
    }
}

RepositoryForSplitStorages::RepositoryForSplitStorages(std::string path) {
this->_path = path;
}

RepositoryForSingleStorages::RepositoryForSingleStorages(std::string path) {
    this->_path = path;
}
