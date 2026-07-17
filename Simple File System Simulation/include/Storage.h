#pragma once

#include "File.h"
#include <string>
#include <vector>

class Storage {
public:
    explicit Storage(std::string filePath);
    bool load(std::vector<File>& files, int& nextId, std::string& error) const;
    bool save(const std::vector<File>& files, int nextId, std::string& error) const;

private:
    std::string filePath;
};
