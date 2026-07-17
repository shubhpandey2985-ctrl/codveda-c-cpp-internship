#pragma once

#include "File.h"
#include "Storage.h"
#include <string>
#include <vector>

class FileManager {
public:
    explicit FileManager(Storage storage);
    bool load(std::string& error);
    bool save(std::string& error) const;
    bool createFile(const std::string& name, const std::string& content, std::string& error);
    bool editFile(const std::string& name, const std::string& content, std::string& error);
    bool renameFile(const std::string& oldName, const std::string& newName, std::string& error);
    bool deleteFile(const std::string& name, std::string& error);
    const File* findFile(const std::string& name) const;
    std::vector<const File*> search(const std::string& query) const;
    std::vector<const File*> allFiles() const;

private:
    std::vector<File> files;
    int nextId{1};
    Storage storage;
    static bool validName(const std::string& name, std::string& error);
    static std::string now();
    File* findMutable(const std::string& name);
};
