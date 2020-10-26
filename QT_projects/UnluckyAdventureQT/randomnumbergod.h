#ifndef UNLUCKYADVENTURE_RANDOMNUMBERGOD_H
#define UNLUCKYADVENTURE_RANDOMNUMBERGOD_H


class RandomNumberGod {
private:
    double percentage=0;
public:
    RandomNumberGod(double percentage);
    RandomNumberGod();
    bool roll();
    bool roll(double percentage);
    int number_int(int min, int max);
    double number_double(double min, double max);
};


#endif //UNLUCKYADVENTURE_RANDOMNUMBERGOD_H
