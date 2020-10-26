#ifndef UNLUCKYADVENTURE_GAME_H
#define UNLUCKYADVENTURE_GAME_H

#include <vector>
//#include "player.h"
#include "field.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

//#include "dice.h"
class Game {
private:
    int num_of_players;
    QGraphicsScene *scene;
    QGraphicsView *view;
    //std::vector<Player*> players;
    std::vector<Field*> fields;
    //Dice dice;
public:
    Game(int players);

    virtual ~Game();

    void turn();

    void static start();

    void generateMonsters();

    void monsterCombat(int,int);

    int fieldHasPlayer(int position);

    void PvP(int p1, int p2);
};


#endif //UNLUCKYADVENTURE_GAME_H
