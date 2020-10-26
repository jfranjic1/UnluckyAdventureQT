#include <iostream>
#include "field.h"
#include "randomnumbergod.h"
#include <QGraphicsRectItem>

Field::Field(){
    RandomNumberGod black_hole_perc(1);
    RandomNumberGod wormhole_perc(5);
    RandomNumberGod forward_perc(9);
    RandomNumberGod backward_perc(10);

    if(black_hole_perc.roll()){
        this->blackhole_field=true;
        return;
    }

    if(wormhole_perc.roll()){
        this->wormhole_field=true;
        return;
    }

    if(forward_perc.roll()){
        this->forward_field=true;
        return;
    }

    if(backward_perc.roll()){
        this->backward_field=true;
        return;
    }

    this->normal_field = true;
}

bool Field::isNormalField() const {
    return normal_field;
}

bool Field::isForwardField() const {
    return forward_field;
}

bool Field::isBackwardField() const {
    return backward_field;
}

bool Field::isWormholeField() const {
    return wormhole_field;
}

bool Field::isBlackholeField() const {
    return blackhole_field;
}

void Field::GenerateMonsters() {
    int monsterperc = 20;
    RandomNumberGod rng(monsterperc);
    if(this->isNormalField() && rng.roll()){
    //this->monster = new Monster();
    this->monster_field =true;
    this->normal_field=false;
 }
}

bool Field::isMonsterField() const {
    return monster_field;
}


void Field::NormalField() {
    normal_field = true;
    this->monster_field= false;
    this->backward_field=false;
    this->wormhole_field=false;
    this->blackhole_field= false;
    this->forward_field=false;
}
/*
 Monster *Field::getMonster() const {
    return monster;
}*/



