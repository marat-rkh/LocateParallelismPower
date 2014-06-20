#include "dataserialization.h"

#include <boost/serialization/vector.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

void SaveData(string const& path, vector<SuffPair> const& suff_arr, vector<string> const& file_paths) {
    std::ofstream ofs(path);
    boost::archive::binary_oarchive oa(ofs);
    oa << suff_arr;
    oa << file_paths;
}

tuple<vector<SuffPair>, vector<string> > LoadData(string const& path) {
    std::ifstream ifs(path);
    boost::archive::binary_iarchive ia(ifs);
    vector<pair<string, vector<size_t> > > suff_arr;
    ia >> suff_arr;
    vector<string> file_paths;
    ia >> file_paths;
    return std::make_tuple(suff_arr, file_paths);
}
