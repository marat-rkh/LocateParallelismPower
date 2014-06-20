#ifndef DIRDATA_H
#define DIRDATA_H

#include <string>
#include <vector>
#include <boost/filesystem.hpp>
#include <utility>

using std::string;
using std::vector;
using boost::filesystem::path;
using std::pair;

class DirData {
public:
    vector<pair<string, size_t> > suffixes;
    vector<string> file_paths;

    void Add(path const& file_path);
    void Concat(DirData const& other);
};


#endif // DIRDATA_H
