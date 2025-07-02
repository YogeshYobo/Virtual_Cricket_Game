#include "Team.h"

class Game
{
public:
    Team teamA,teamB,*battingteam,*bowlingteam;
    Player *batsman,*bowler;
    int maxplayer,maxdeliveries;
    std::string players[11];
    bool firstinning;
    Game();
    void welcomemessage();
    void displayPlayers();
    void selectplayers();
    int typeinteger();
    void showteams();
    void toss();
    int selectionofchoice();
    void play();
    int scorerun();
    void playinning();
    void scorecard();
    void inningswap();
    void playsecond();
    void matchstats(Team);
};
