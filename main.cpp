#include "Game.h"

using namespace std;

int main()
{
    Game g;
    g.welcomemessage();
    cout<<"Press Enter to Continue....."<<endl;
    getch();
    g.displayPlayers();
    cout<<"Press Enter to Continue....."<<endl;
    getch();
    g.selectplayers();
    cout<<"Press Enter to Continue....."<<endl;
    getch();
    g.showteams();
    cout<<"Press Enter to Continue....."<<endl;
    getch();
    g.toss();
    cout<<"Press Enter to Continue....."<<endl;
    getch();
    g.firstinning=true;
    g.playinning();
    cout<<"Press Enter to Start Second inning....."<<endl;
    getch();
    g.firstinning=false;
    g.playinning();




    return 0;
}
