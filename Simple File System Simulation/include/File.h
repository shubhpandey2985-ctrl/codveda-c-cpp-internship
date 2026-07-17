#pragma once

#include <string>

class File {
public:
    int id{};
    std::string name;
    std::string content;
    std::string createdDate;
    std::string modifiedDate;

    std::size_t size() const;
    std::size_t wordCount() const;
    std::size_t lineCount() const;
};
