#include "randomnumbergod.h"
#include "random"

bool RandomNumberGod::roll() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist_blackhole(0, 100);
    return dist_blackhole(mt)<percentage;
}

bool RandomNumberGod::roll(double percentage) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist_blackhole(0, 100);
    return dist_blackhole(mt)<percentage;
}

RandomNumberGod::RandomNumberGod(double percentage) : percentage(percentage) {}

RandomNumberGod::RandomNumberGod() {
    percentage=0;
}

int RandomNumberGod::number_int(int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist_blackhole(min, max);
    return dist_blackhole(mt);
}

double RandomNumberGod::number_double(double min, double max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist_blackhole(min, max);
    return dist_blackhole(mt);
}
