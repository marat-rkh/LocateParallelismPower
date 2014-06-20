#include "dirdata.h"

#include <algorithm>
#include <functional>

using std::string;

void DirData::Add(path const& file_path) {
    file_paths.push_back(file_path.generic_string());
    string filename = file_path.filename().generic_string();
    for(size_t i = 0; i != filename.size(); ++i) {
        suffixes.push_back(std::make_pair(filename.substr(i), file_paths.size() - 1));
    }
}

void DirData::Concat(DirData const& other) {
    suffixes.insert(suffixes.end(), other.suffixes.begin(), other.suffixes.end());
    std::function<void(pair<string, size_t> &)> shift = [=](pair<string, size_t> &elem){ elem.second += file_paths.size(); };
    std::for_each(suffixes.end() - other.suffixes.size(), suffixes.end(), shift);
    file_paths.insert(file_paths.end(), other.file_paths.begin(), other.file_paths.end());
}
