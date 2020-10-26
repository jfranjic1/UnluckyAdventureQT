#ifndef UNLUCKYADVENTURE_GAME_H
#define UNLUCKYADVENTURE_GAME_H

#include <vector>
//#include "player.h"
#include "field.h"
//#include "dice.h"
class Game {
private:
    int num_of_players;
    //std::vector<Player*> players;
    std::vector<Field*> fields;
    //Dice dice;
public:
    Game(int players, int numberOfFields, int diceSides);

    virtual ~Game();

    void turn();

    void static start();

    void generateMonsters();

    void monsterCombat(int,int);

    int fieldHasPlayer(int position);

    void PvP(int p1, int p2);
};


#endif //UNLUCKYADVENTURE_GAME_H
