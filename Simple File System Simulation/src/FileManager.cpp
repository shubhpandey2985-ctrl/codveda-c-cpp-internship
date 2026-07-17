#include "FileManager.h"

#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

FileManager::FileManager(Storage value) : storage(std::move(value)) {}
bool FileManager::load(std::string& error) { return storage.load(files, nextId, error); }
bool FileManager::save(std::string& error) const { return storage.save(files, nextId, error); }

std::string FileManager::now() {
    const auto current = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    const std::tm* localTime = std::localtime(&current);
    std::tm local = localTime ? *localTime : std::tm{};
    std::ostringstream out;
    out << std::put_time(&local, "%Y-%m-%d %H:%M:%S");
    return out.str();
}

bool FileManager::validName(const std::string& name, std::string& error) {
    if (name.empty()) { error = "Filename cannot be empty."; return false; }
    if (name.size() > 50) { error = "Filename must be 50 characters or fewer."; return false; }
    if (name.find_first_of("\\/:*?\"<>|") != std::string::npos) { error = "Filename contains invalid characters."; return false; }
    return true;
}

File* FileManager::findMutable(const std::string& name) {
    auto it = std::find_if(files.begin(), files.end(), [&name](const File& f) { return f.name == name; });
    return it == files.end() ? nullptr : &*it;
}
const File* FileManager::findFile(const std::string& name) const {
    auto it = std::find_if(files.begin(), files.end(), [&name](const File& f) { return f.name == name; });
    return it == files.end() ? nullptr : &*it;
}
bool FileManager::createFile(const std::string& name, const std::string& content, std::string& error) {
    if (!validName(name, error) || content.size() > 5000) { if (content.size() > 5000) error = "Content must be 5000 characters or fewer."; return false; }
    if (findFile(name)) { error = "File already exists."; return false; }
    const auto stamp = now(); files.push_back({nextId++, name, content, stamp, stamp}); return true;
}
bool FileManager::editFile(const std::string& name, const std::string& content, std::string& error) {
    auto* file = findMutable(name); if (!file) { error = "File does not exist."; return false; }
    if (content.size() > 5000) { error = "Content must be 5000 characters or fewer."; return false; }
    file->content = content; file->modifiedDate = now(); return true;
}
bool FileManager::renameFile(const std::string& oldName, const std::string& newName, std::string& error) {
    auto* file = findMutable(oldName); if (!file) { error = "File does not exist."; return false; }
    if (!validName(newName, error)) return false;
    if (oldName != newName && findFile(newName)) { error = "File already exists."; return false; }
    file->name = newName; file->modifiedDate = now(); return true;
}
bool FileManager::deleteFile(const std::string& name, std::string& error) {
    auto it = std::find_if(files.begin(), files.end(), [&name](const File& f) { return f.name == name; });
    if (it == files.end()) { error = "File does not exist."; return false; }
    files.erase(it); return true;
}
std::vector<const File*> FileManager::search(const std::string& query) const {
    std::vector<const File*> result; for (const auto& file : files) if (file.name.find(query) != std::string::npos) result.push_back(&file);
    std::sort(result.begin(), result.end(), [](const File* a, const File* b) { return a->name < b->name; }); return result;
}
std::vector<const File*> FileManager::allFiles() const { return search(""); }
