#include "Random.h"

std::mt19937 Random::seed_(std::random_device{}());

Random::Random() {
}

Random::~Random() {
}
