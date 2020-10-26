#include <iostream>
#include "game.h"
#include "randomnumbergod.h"
//#include "Shop.h"
Game::Game(int players, int numberOfFields, int diceSides) {
    this->num_of_players = players;
    //this->players = std::vector<Player*>(players);
    this->fields = std::vector<Field*>(numberOfFields);
    //this->dice = Dice(diceSides);
    for(int i=0;i<players;i++){
        //this->players[i] = new Player(i+1);
    }
    for(int i=0;i<numberOfFields;i++){
        this->fields[i] = new Field();
    }
    this->fields[0]->NormalField();
}

/*Game::~Game() {
    for (int i = 0; i < num_of_players ; i++) {
        delete this->players[i];
    }
    for (int i = 0; i < this->fields.size() ; i++) {
        delete this->fields[i];
    }
    for (int i = 1; i < this->fields.size(); ++i) {
        if (this->fields[i]->isMonsterField()){
            delete fields[i]->getMonster();
        }
    }
}*/

/*void Game::turn() {
    bool check=true;
    for(int i = 0; i < num_of_players; i++) {
        //if all players die the game ends
        bool test_alive=false;
        bool test_end=false;
        int j=0;
        for(j=0;j<num_of_players;j++){
            if(this->players[j]->isAlive())test_alive=true;
            if(this->players[j]->getPosition()== this->fields.size()){
                test_end = true;
                break;
            }
        }
        if(!test_alive){
            std::cout<<std::endl<<"All players are dead. GG UNLUCKY"<<std::endl;
            throw 1;
        }
        if(test_end){
            std::cout<<"Player "<<j+1<<" has won the game."<<std::endl;
            throw 1;
        }

        if (!this->players[i]->isAlive())continue;

        //check is for the forward and backward fields to avoid dialogue
    if (check){
        std::cout << std::endl <<"Player " << i + 1 << " turn." << std::endl;
        char temp;
        while (1) {
            std::cout << R"("R" to roll the dice, "S" to open shop, "F" to forfeit)" << std::endl;
            std::cin >> temp;
            if (temp == 'R' || temp == 'S' || temp == 'F' || temp == 'r' || temp == 's' || temp == 'f') break;
            std::cout << "Unknown character, please try again." << std::endl;
        }
        if (temp == 'R' || temp == 'r') {
            int result = this->dice.Roll();
            if(this->players[i]->hasLuckyBoots()){
                result*=2;
                std::cout<<"Due to Lucky Boots you have moved "<<result<<" fields."<<std::endl;
            }
            this->players[i]->move_relative(result, fields.size());
        }
        if (temp == 'S' || temp == 's') {

            Shop::displayShop(this->players[i]);

            continue;
        }
        if (temp == 'F' || temp == 'f') {
            this->players[i]->kill();
            if(!this->players[i]->isAlive())std::cout << "You have blown yourself out of existence." << std::endl;
            continue;
        }
    }check=true;
        if(this->fields[this->players[i]->getPosition()]->isBlackholeField()){
            std::cout<<"You have stepped on a black hole and blew yourself out of existence."<<std::endl;
            this->players[i]->kill();
            continue;
        }
        if(this->fields[this->players[i]->getPosition()]->isWormholeField()){
            std::cout<<"You have stepped on a wormhole and teleported to the beginning."<<std::endl;
            this->players[i]->move_absolute(0, this->fields.size());
            continue;
        }
        if(this->fields[this->players[i]->getPosition()]->isNormalField()){
            std::cout<<"You have moved to position "<<this->players[i]->getPosition()<<"."<<std::endl;
        }
        if(this->fields[this->players[i]->getPosition()]->isForwardField()){
            check = false;
            int result = this->dice.RollSilent();
            std::cout<<"You have moved to a Forward field at the position "<< this->players[i]->getPosition()<<" and have to move "<< result <<" fields forward"<<std::endl;
            this->players[i]->move_relative(result, this->fields.size());
            i--;
            continue;
        }
        if(this->fields[this->players[i]->getPosition()]->isBackwardField()){
            check = false;
            int result = this->dice.RollSilent();
            std::cout<<"You have moved to a Backward field at the position "<< this->players[i]->getPosition()<<" and have to move "<< result <<" fields backwards."<<std::endl;
            this->players[i]->move_relative(-result, this->fields.size());
            i--;
            continue;
        }
        if(this->fields[this->players[i]->getPosition()]->isMonsterField() && this->fields[this->players[i]->getPosition()]->getMonster()->isAlive()){
            this->monsterCombat(this->players[i]->getPosition(),i);
        }
        if(this->fieldHasPlayer(this->players[i]->getPosition())>-1 && this->fieldHasPlayer(this->players[i]->getPosition()) != i && this->players[i]->getPosition()!=0){
            std::cout<<"You have moved to position "<<this->players[i]->getPosition()<<" and ran into Player "<<this->fieldHasPlayer(this->players[i]->getPosition())+1<<"."<<std::endl;
            this->PvP(i, this->fieldHasPlayer(this->players[i]->getPosition()));
        }

    }
}
*/
void Game::start() {
    std::cout<<"What is the number of great adventurers ?"<<std::endl;
    int num;
    do {
        std::cin >> num;
        std::cin.clear();
        std::cin.ignore();
        if(num < 1)std::cout << "Please enter a valid number of players." << std::endl;
    } while (num < 1);
    std::cout<<"How many fields do you wish to have ?"<<std::endl;
    int field;
    do {
        std::cin >> field;
        if(field < 50)std::cout << "Please enter a valid number of fields. (>=50)" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    } while (field < 50);
    int dice;
    do {
        std::cout<<"How many dice sides do you wish to have ?"<<std::endl;
        std::cin >> dice;
        if(dice < 6)std::cout << "Please enter a valid number of dice sides. (>=6)" << std::endl;
        std::cin.clear();
        std::cin.ignore();
    } while (dice < 6);
    Game g(num,field,dice);
    char monst;
    do {
        std::cout<<"Do you wish to have monsters in your game ? (Y - Yes, N - No)"<<std::endl;
        std::cin >> monst;
        if(monst != 'y' && monst != 'Y' && monst != 'N' && monst != 'n')std::cout << "Please enter a valid character." << std::endl;
        std::cin.clear();
        std::cin.ignore();
    } while (monst != 'y' && monst != 'Y' && monst != 'N' && monst != 'n');
    if (monst == 'y' || monst == 'Y')g.generateMonsters();

    /*
        int monster = 0, black = 0, worm = 0, forward = 0, backward = 0;
        for (int i = 0; i < 100000; ++i) {
            if (g.fields[i]->isMonsterField())monster++;
            if (g.fields[i]->isBackwardField())backward++;
            if (g.fields[i]->isForwardField())forward++;
            if (g.fields[i]->isWormholeField())worm++;
            if (g.fields[i]->isBlackholeField())black++;
        }
        std::cout << "Monster " << monster << std::endl;
        std::cout << "Backward " << backward << std::endl;
        std::cout << "Forward " << forward << std::endl;
        std::cout << "Worm " << worm << std::endl;
        std::cout << "Black " << black << std::endl;
    */

    while(1){
        try {
            g.turn();
        } catch (...) {
            break;
        }
    }

}

void Game::generateMonsters() {
    for (int i = 1; i < this->fields.size(); ++i) {
        this->fields[i]->GenerateMonsters();
    }
}
/*
void Game::monsterCombat(int i, int j) {
    std::vector<float> run = {70, 50, 30, 20};
    std::vector<float> fight = {50, 25, 15, 7};
    int multiplication=1;
    if(this->players[j]->hasSword())multiplication+=1;
    if(this->players[j]->hasShield())multiplication+=0.5;
    int monster_tier = this->fields[i]->getMonster()->getTier();
    std::cout<<"You ran into a Level "<< monster_tier<<" monster."<<std::endl;
    std::cout<<"Do you wish to fight the monster or run away from it ? (R - run, F - Fight)"<<std::endl;
    char monst;
    do {
        std::cin >> monst;
        if(monst != 'R' && monst != 'r' && monst != 'f' && monst != 'F')std::cout << "Please enter a valid character." << std::endl;
        std::cin.clear();
        std::cin.ignore();
    } while (monst != 'R' && monst != 'r' && monst != 'F' && monst != 'f');

    if (monst == 'r' || monst == 'R'){
        RandomNumberGod run_rng(run[monster_tier-1]*multiplication);
        if(!run_rng.roll()){
            std::cout<<"A great tragedy happened while runing away from a Level "<<monster_tier<<" monster."<<std::endl;
            std::cout<<"You have been returned to the start."<<std::endl;
            this->players[j]->move_absolute(0,this->fields.size());
        }else{
            this->players[j]->move_absolute(this->players[j]->getPreviousPosition(),this->fields.size());
            std::cout<<"You have returned to the previous position safely. (field "<<this->players[j]->getPosition()<<")"<<std::endl;
        }
    } else{
        RandomNumberGod fight_rng(fight[monster_tier-1]*multiplication);
        if(!fight_rng.roll()){
            std::cout<<"A great tragedy happened while trying to fight a Level "<<monster_tier<<" monster."<<std::endl;
            RandomNumberGod coin_flip(50);
            if(coin_flip.roll()) {
                std::cout << "You have been returned to the start." << std::endl;
                this->players[j]->move_absolute(0, this->fields.size());
            } else{
                this->players[j]->move_absolute(this->players[j]->getPreviousPosition(), this->fields.size());
                std::cout << "The Gods of Death were amazed by your bravery and you were returned to the previous field. (field "<<this->players[j]->getPosition()<<")" << std::endl;
            }
        }else{
            this->players[j]->move_absolute(this->players[j]->getPreviousPosition(),this->fields.size());
            this->players[j]->giveGold(monster_tier*monster_tier);
            std::cout<<"You have slain a Level "<<monster_tier<<" monster and have earned "<<monster_tier*monster_tier<<" gold."<<std::endl;
            this->fields[i]->getMonster()->kill();
            this->fields[i]->NormalField();
        }
    }
}

int Game::fieldHasPlayer(int position) {
    int i;
    for ( i= 0; i < this->players.size(); ++i) {
        if(this->players[i]->getPosition() == position && this->players[i]->isAlive())break;
    }
    if(i==this->players.size())return -1;
    return i;
}

void Game::PvP(int p1, int p2) {
    int multiplication1=1, multiplication2=1;
    if(this->players[p1]->hasShield())multiplication1+=1;
    if(this->players[p1]->hasSword())multiplication1+=2;
    if(this->players[p2]->hasShield())multiplication2+=1;
    if(this->players[p2]->hasSword())multiplication2+=2;
    double rand=p1/p2*50;
    RandomNumberGod rng(rand);
    if(rng.roll()){
        std::cout<<"In a fearsome battle Player "<< p1+1<< " has slain Player "<< p2+1 <<" ."<<std::endl;
        this->players[p2]->kill();
    }else{
        std::cout<<"In a fearsome battle Player "<< p2+1<< " has slain Player "<< p1+1 <<" ."<<std::endl;
        this->players[p1]->kill();
    }
}*/
