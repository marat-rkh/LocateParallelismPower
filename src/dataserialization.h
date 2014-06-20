#ifndef DATASERIALIZATION_H
#define DATASERIALIZATION_H

#include <fstream>
#include <tuple>
#include <utility>

#include "global_params.h"

using std::string;
using std::vector;
using std::tuple;
using std::pair;

void SaveData(string const& path, vector<SuffPair> const& suff_arr, vector<string> const& file_paths);
tuple<vector<SuffPair>, vector<string> > LoadData(string const& path);

#endif // DATASERIALIZATION_H
