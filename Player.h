#include <iostream>
#include <string>
#include<unistd.h>
#include <time.h>
#include <random>
#include <conio.h>
#include <limits>


class Player
{
public:
    std::string player_name;
    int index,runscored,ballsfaced,ballbowled,wicketstaken,runsgiven;
    Player();
};
