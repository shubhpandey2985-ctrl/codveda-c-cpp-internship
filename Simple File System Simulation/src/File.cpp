#include "File.h"

#include <cctype>
#include <sstream>

std::size_t File::size() const { return content.size(); }

std::size_t File::wordCount() const {
    std::istringstream input(content);
    std::string word;
    std::size_t count = 0;
    while (input >> word) ++count;
    return count;
}

std::size_t File::lineCount() const {
    if (content.empty()) return 0;
    std::size_t count = 1;
    for (char ch : content) if (ch == '\n') ++count;
    return count;
}
