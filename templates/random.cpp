#include <ctime>
#include <random>

std::mt19937_64 rnd(std::time(nullptr));

// rnd() is [0, 2^64)
