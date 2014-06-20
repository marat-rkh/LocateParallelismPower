#ifndef GLOBAL_PARAMS_H
#define GLOBAL_PARAMS_H

#include <cstdlib>
#include <thread>
#include <utility>
#include <vector>

const size_t ALPHABET_SIZE = 256;
const size_t THREADS_NUM = std::thread::hardware_concurrency() == 0 ? 2 : std::thread::hardware_concurrency();

typedef std::pair<std::string, std::vector<size_t> > SuffPair;

#endif // GLOBAL_PARAMS_H
