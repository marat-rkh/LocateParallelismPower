#include "suffixarraybuilder.h"
#include "global_params.h"

#include <algorithm>
#include <cmath>
#include <tbb/parallel_sort.h>

using std::string;
using std::vector;
using std::thread;
using std::pair;
using std::make_pair;

vector<SuffPair> MergeSameElems(vector<pair<string, size_t> > & suffixes);

vector<SuffPair> BuildSuffArr(vector<pair<string, size_t> > suffixes) {
    tbb::parallel_sort(suffixes.begin(), suffixes.end());
    return MergeSameElems(suffixes);
}

vector<SuffPair> MergeSameElems(vector<pair<string, size_t> > & suffixes) {
    vector<SuffPair> res;
    res.push_back(make_pair(suffixes[0].first, vector<size_t>(1, suffixes[0].second)));
    for(size_t i = 1; i != suffixes.size(); ++i) {
        if(res.back().first == suffixes[i].first) {
            res.back().second.push_back(suffixes[i].second);
        }
        else {
            res.push_back(make_pair(suffixes[i].first, vector<size_t>(1, suffixes[i].second)));
        }
    }
    return res;
}
