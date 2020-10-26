#include "randomnumbergod.h"
#include <random>
#include <QDebug>
#include <QRandomGenerator>

bool RandomNumberGod::roll() {

        std::uniform_int_distribution<> dist(0, 100);
        int value = dist(*QRandomGenerator::global());
        return value<percentage;
}

bool RandomNumberGod::roll(double percentage) {
    std::uniform_int_distribution<> dist(0, 100);
    int value = dist(*QRandomGenerator::global());
    return value<percentage;
}

RandomNumberGod::RandomNumberGod(double percentage) : percentage(percentage) {}

RandomNumberGod::RandomNumberGod() {
    percentage=0;
}

int RandomNumberGod::number_int(int min, int max) {
    std::uniform_int_distribution<> dist(min, max);
    int value = dist(*QRandomGenerator::global());
    return value;
}

double RandomNumberGod::number_double(double min, double max) {
    std::uniform_real_distribution<> dist(min, max);
    double value = dist(*QRandomGenerator::global());
    return value;
}
