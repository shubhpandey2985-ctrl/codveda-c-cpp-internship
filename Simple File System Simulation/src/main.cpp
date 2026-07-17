#include "FileManager.h"
#include <iomanip>
#include <iostream>
#include <limits>

namespace {
std::string ask(const std::string& prompt) { std::cout << prompt; std::string value; std::getline(std::cin, value); return value; }
std::string contentInput() { std::cout << "Enter content (finish with a line containing only .end):\n"; std::string line, content; while (std::getline(std::cin, line) && line != ".end") { if (!content.empty()) content += '\n'; content += line; } return content; }
void showFile(const File& f) { std::cout << "\nFilename: " << f.name << "\nCreated Date: " << f.createdDate << "\nLast Modified: " << f.modifiedDate << "\n\nContent:\n" << f.content << "\n"; }
void showInfo(const File& f) { std::cout << "\nFilename: " << f.name << "\nID: " << f.id << "\nCreated Date: " << f.createdDate << "\nModified Date: " << f.modifiedDate << "\nCharacter Count: " << f.size() << "\nWord Count: " << f.wordCount() << "\nLine Count: " << f.lineCount() << "\n"; }
void listFiles(const std::vector<const File*>& files) { if (files.empty()) { std::cout << "No files found.\n"; return; } std::cout << "\n" << std::left << std::setw(6) << "ID" << std::setw(26) << "Name" << std::setw(10) << "Size" << std::setw(21) << "Created" << "Modified\n" << std::string(84, '-') << '\n'; for (const auto* f : files) std::cout << std::left << std::setw(6) << f->id << std::setw(26) << f->name << std::setw(10) << f->size() << std::setw(21) << f->createdDate << f->modifiedDate << '\n'; }
void menu() { std::cout << "\n=============================\n Simple File System\n=============================\n1. Create File\n2. Open File\n3. Edit File\n4. Rename File\n5. Delete File\n6. Display All Files\n7. Search File\n8. File Information\n9. Save\n10. Exit\n"; }
}

int main() {
    FileManager manager(Storage("data/filesystem.dat")); std::string error;
    if (!manager.load(error)) std::cerr << "Warning: " << error << " Starting with an empty file system.\n";
    while (true) {
        menu(); std::string choice = ask("Enter Choice: ");
        if (choice == "1") { const auto name = ask("Filename: "); const auto content = contentInput(); if (manager.createFile(name, content, error)) std::cout << "File created successfully.\n"; else std::cout << "Error: " << error << '\n'; }
        else if (choice == "2") { const auto* file = manager.findFile(ask("Filename: ")); if (file) showFile(*file); else std::cout << "Error: File does not exist.\n"; }
        else if (choice == "3") { const auto name = ask("Filename: "); const auto content = contentInput(); if (manager.editFile(name, content, error)) std::cout << "File updated successfully.\n"; else std::cout << "Error: " << error << '\n'; }
        else if (choice == "4") { const auto oldName = ask("Old filename: "); const auto newName = ask("New filename: "); if (manager.renameFile(oldName, newName, error)) std::cout << "File renamed successfully.\n"; else std::cout << "Error: " << error << '\n'; }
        else if (choice == "5") { const auto name = ask("Filename: "); if (!manager.findFile(name)) { std::cout << "Error: File does not exist.\n"; continue; } const auto confirm = ask("Delete " + name + "?\n1 Yes\n2 No\nChoice: "); if (confirm == "1") { if (manager.deleteFile(name, error)) std::cout << "File deleted successfully.\n"; else std::cout << "Error: " << error << '\n'; } else std::cout << "Delete cancelled.\n"; }
        else if (choice == "6") listFiles(manager.allFiles());
        else if (choice == "7") { const auto query = ask("Search filename: "); if (query.empty()) std::cout << "Error: Search text cannot be empty.\n"; else listFiles(manager.search(query)); }
        else if (choice == "8") { const auto* file = manager.findFile(ask("Filename: ")); if (file) showInfo(*file); else std::cout << "Error: File does not exist.\n"; }
        else if (choice == "9") { if (manager.save(error)) std::cout << "Data saved successfully.\n"; else std::cout << "Error: " << error << '\n'; }
        else if (choice == "10") { if (!manager.save(error)) std::cerr << "Error: " << error << '\n'; else std::cout << "Data saved. Goodbye!\n"; break; }
        else std::cout << "Error: Invalid choice.\n";
    }
}
