#ifndef FINDER_H
#define FINDER_H

#include <vector>
#include <string>

#include "dataserialization.h"

using std::vector;
using std::string;

class Finder {
public:
    vector<string> FindFiles(string const& index_path, string const& query);
private:
    vector<string> Search(string const& query);

    vector<SuffPair> suff_arr_;
    vector<string> file_paths_;
};

#endif // FINDER_H
