#include "finder.h"
#include "dataserialization.h"
#include "global_params.h"

#include <tuple>
#include <boost/filesystem.hpp>
#include <algorithm>
#include <functional>
#include <boost/algorithm/string/predicate.hpp>

using std::vector;
using std::string;

vector<string> Finder::FindFiles(string const& index_path, string const& query) {
    tuple<vector<SuffPair>, vector<string> > loaded = LoadData(index_path);
    suff_arr_ = std::get<0>(loaded);
    file_paths_ = std::get<1>(loaded);
    return Search(query);
}

vector<string> Finder::Search(string const& query) {
    using namespace boost::algorithm;
    vector<SuffPair>::iterator lbound = std::lower_bound(suff_arr_.begin(), suff_arr_.end(), query,
                                        [](SuffPair const& p, string const& e) { return p.first.compare(e) < 0; });
    vector<string> paths;
    for(; starts_with(lbound->first, query); ++lbound) {
        for(size_t & num : lbound->second) {
            paths.push_back(file_paths_[num]);
        }
    }
    return paths;
}
