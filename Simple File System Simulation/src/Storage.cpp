#include "Storage.h"

#include <fstream>

Storage::Storage(std::string path) : filePath(std::move(path)) {}

bool Storage::save(const std::vector<File>& files, int nextId, std::string& error) const {
    try {
        std::ofstream out(filePath, std::ios::binary | std::ios::trunc);
        if (!out) { error = "Unable to save data."; return false; }
        auto writeText = [&out](const std::string& value) {
            std::size_t length = value.size();
            out.write(reinterpret_cast<const char*>(&length), sizeof(length));
            out.write(value.data(), static_cast<std::streamsize>(length));
        };
        std::size_t count = files.size();
        out.write(reinterpret_cast<const char*>(&nextId), sizeof(nextId));
        out.write(reinterpret_cast<const char*>(&count), sizeof(count));
        for (const auto& file : files) {
            out.write(reinterpret_cast<const char*>(&file.id), sizeof(file.id));
            writeText(file.name); writeText(file.content);
            writeText(file.createdDate); writeText(file.modifiedDate);
        }
        if (!out) { error = "Unable to save data."; return false; }
        return true;
    } catch (...) { error = "Unable to save data."; return false; }
}

bool Storage::load(std::vector<File>& files, int& nextId, std::string& error) const {
    std::ifstream in(filePath, std::ios::binary);
    if (!in) {
        std::ofstream create(filePath, std::ios::binary);
        return static_cast<bool>(create);
    }
    auto readText = [&in](std::string& value) -> bool {
        std::size_t length{};
        if (!in.read(reinterpret_cast<char*>(&length), sizeof(length)) || length > 10'000'000) return false;
        value.resize(length);
        return length == 0 || static_cast<bool>(in.read(&value[0], static_cast<std::streamsize>(length)));
    };
    std::size_t count{};
    if (!in.read(reinterpret_cast<char*>(&nextId), sizeof(nextId)) || !in.read(reinterpret_cast<char*>(&count), sizeof(count)) || count > 1'000'000) { error = "Unable to load data."; return false; }
    std::vector<File> loaded;
    for (std::size_t i = 0; i < count; ++i) {
        File file;
        if (!in.read(reinterpret_cast<char*>(&file.id), sizeof(file.id)) || !readText(file.name) || !readText(file.content) || !readText(file.createdDate) || !readText(file.modifiedDate)) { error = "Unable to load data."; return false; }
        loaded.push_back(std::move(file));
    }
    files = std::move(loaded);
    return true;
}
