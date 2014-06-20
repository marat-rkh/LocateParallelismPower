#ifndef SUFFIXARRAYBUILDER_H
#define SUFFIXARRAYBUILDER_H

#include <string>
#include <vector>
#include <utility>

#include "global_params.h"

using std::vector;
using std::string;
using std::pair;

vector<SuffPair> BuildSuffArr(vector<pair<string, size_t> > suffixes);

#endif // SUFFIXARRAYBUILDER_H
