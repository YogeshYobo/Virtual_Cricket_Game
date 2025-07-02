#include "Game.h"
#include <iostream>
using namespace std;

Game:: Game()
{
    maxplayer=4;
    maxdeliveries=6;
    players[0]="S.Gill";
    players[1]="R.Sharma";
    players[2]="V.Kohli";
    players[3]="K.L.Rahul";
    players[4]="S.Yadav";
    players[5]="R.Jadeja";
    players[6]="H.Pandya";
    players[7]="K.Yadav";
    players[8]="J.Bumrah";
    players[9]="M.Siraj";
    players[10]="M.Shami";
    firstinning=false;
}
void Game::welcomemessage()
{
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"|===============VIRTUAL CRICKET GAME====================|"<<endl;
    cout<<"|                                                       |"<<endl;
    cout<<"---------------------------------------------------------\n\n"<<endl;
    usleep(1000000);

    cout<<"-------------------------------------------------"<<endl;
    cout<<"|===============INSTRUCTIONS====================|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|                                               |"<<endl;
    cout<<"| 1.Create 2 teams(Team-A and Team-B with 4     |"<<endl;
    usleep(1000000);
    cout<<"| players each) from the given 11 player.       |"<<endl;
    usleep(1000000);
    cout<<"| 2.Lead the toss and decide the choice of play.|"<<endl;
    usleep(1000000);
    cout<<"| 3.Each inning will be of 6 balls.             |"<<endl;
    usleep(1000000);
    cout<<"-------------------------------------------------\n\n"<<endl;
}

void Game::displayPlayers()
{
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|===============POOL OF PLAYERS==================|"<<endl;
    cout<<"-------------------------------------------------"<<endl;
    for (int i=0;i<=10;i++)
    {
        cout<<"\t\t"<<i<<". "<<players[i]<<endl;
        usleep(1000000);
    }
    cout<<"\n\n";
}

void Game::selectplayers()
{
    cout<<"-------------------------------------------------"<<endl;
    cout<<"|==========Create Team A and Team B==============|"<<endl;
    cout<<"-------------------------------------------------\n"<<endl;
    for (int i=0;i<maxplayer;i++)
    {
        label2:
        cout<<"Select Player "<<i+1<<" of Team A:";
        int x=typeinteger();
        if(x>=0 && x<=10)
        {
            if (!(players[x]=="NULL"))
            {
                Player p;
                p.player_name=players[x];
                teamA.players.push_back(p);
                players[x]="NULL";
            }

            else
            {
                cout<<"Player has already selected. Please select other player."<<endl;
                goto label2;
            }
        }
        else
        {
             cout<<"Player has already selected. Please select other player."<<endl;
            goto label2;
        }


    label3:
        cout<<"Select Player "<<i+1<<" of Team B:";
        int y=typeinteger();
        if (y>=0 && y<=10)
        {
            if (!(players[y]=="NULL"))
            {
                Player p;
                p.player_name=players[y];
                teamB.players.push_back(p);
                players[y]="NULL";
            }
            else
            {
                cout<<"Player has already selected. Please select other player."<<endl;
                goto label3;
            }
        }
        else
        {
            cout<<"You Entered integer out of range. Please type a valid integer.";
            goto label3;
        }
    }

}
int Game::typeinteger()
{
    label1:
    int n;
    while(!(cin>>n))
    {
        cout<<"Oops! You Entered an something wrong please enter an integer digit only..."<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        goto label1;
    }
    return n;
}
void Game::showteams()
{
    teamA.team_name="Team A";
    teamB.team_name="Team B";
    cout<<"----------------\t\t----------------"<<endl;
    cout<<"|====Team A====|\t\t|====Team B====|"<<endl;
    cout<<"----------------\t\t----------------"<<endl;
    for(int i=0;i<maxplayer;i++)
    {
        cout<<"|"<<i+1<<"."<<teamA.players[i].player_name<<"\t|\t\t|"<<i+1<<"."<<teamB.players[i].player_name<<"\t|"<<endl;
        usleep(1000000);
    }
    cout<<"----------------\t\t----------------\n"<<endl;
}
void Game::toss()
{
    cout<<"---------------------------------------------"<<endl;
    cout<<"|===============Let's Toss==================|"<<endl;
    cout<<"---------------------------------------------\n"<<endl;
    cout<<"Tossing the coin...."<<endl;
    usleep(1000000);
    int n;
    srand(time(NULL));
    n=rand()%2;
    if(n)      //teamA wins the toss
    {
        cout<<"Team A wins the toss"<<endl;
        int x=selectionofchoice();
        if(x==1)        //teamA batting first
        {
            cout<<"Team A elected to bat first."<<endl;
            battingteam=&teamA;
            bowlingteam=&teamB;
            batsman=&teamA.players[0];
            bowler=&teamB.players[0];
        }
        else        //teamB batting first
        {
            cout<<"Team A elected to bowl first."<<endl;
            battingteam=&teamB;
            bowlingteam=&teamA;
            batsman=&teamB.players[0];
            bowler=&teamA.players[0];
        }
    }
    else    //teamB wins the toss
    {
        cout<<"Team B wins the toss"<<endl;
        int x=selectionofchoice();
        if(x==2)        //teamA batting first
        {
            cout<<"Team B elected to bowl first."<<endl;
            battingteam=&teamA;
            bowlingteam=&teamB;
            batsman=&teamA.players[0];
            bowler=&teamB.players[0];
        }
        else        //teamB batting first
        {
            cout<<"Team B elected to bat first."<<endl;
            battingteam=&teamB;
            bowlingteam=&teamA;
            batsman=&teamB.players[0];
            bowler=&teamA.players[0];
        }
    }


}
int Game::selectionofchoice()
{
    cout<<"Enter 1 to Bat or 2 to Bowl first"<<endl;
    cout<<"1. Bat"<<endl<<"2.Bowl"<<endl;
    int n=typeinteger();
    if ((n!=1) && (n!=2))
    {
        cout<<"You entered wrong choice please press enter."<<endl;
        getch();
        return selectionofchoice();
    }
    return n;
}
void Game::playinning()
{
    if (firstinning==true)  //first inning
    {
        cout<<"\n\n|||First Inning Start|||\n"<<endl;
        cout<<battingteam->team_name<<" - "<<batsman->player_name<<" is batting."<<endl;
        cout<<bowlingteam->team_name<<" - "<<bowler->player_name<<" is bowling.\n"<<endl;
        play();
        cout<<"\n\n|||First Inning Ends|||\n"<<endl;
        cout<<battingteam->team_name<<" "<<battingteam->totalrun<<"-"<<battingteam->wicketlost
        <<" ("<<battingteam->ballsfaced<<")"<<endl;
        cout<<bowlingteam->team_name<<" needs "<<battingteam->totalrun+1<<" runs to win the match"<<endl;
    }
    else
    {
        this->inningswap();
        cout<<"\n\n|||Second Inning Start|||\n"<<endl;
        cout<<battingteam->team_name<<" - "<<batsman->player_name<<" is batting."<<endl;
        cout<<bowlingteam->team_name<<" - "<<bowler->player_name<<" is bowling.\n"<<endl;
        playsecond();

    }

}
int Game::scorerun()
{
    int n;
    srand(time(NULL));
    n=rand()%7;
    return n;
}
void Game::scorecard()
{
    cout<<"------------------------------------------------------------"<<endl;
    cout<<"\t"<<battingteam->team_name<<"  "<<battingteam->totalrun<<"-"<<battingteam->wicketlost
    <<" ("<<bowlingteam->ballsbowled<<") | "<<batsman->player_name<<" "<<batsman->runscored
    <<"("<<batsman->ballsfaced<<")\t"<<bowler->player_name<<" "<<bowler->ballbowled
    <<"-"<<bowler->runsgiven<<"-"<<bowler->wicketstaken<<endl;
    cout<<"------------------------------------------------------------"<<endl;
}
void Game::play()
{
    for (int i=1;i<=maxdeliveries;i++)
        {
            cout<<"Press Enter to bowl..."<<endl;
            getch();
            cout<<"Bowling..."<<endl;
            usleep(1000000);
            int run=scorerun();
            if (run==5)  //wicket taken
            {
                cout<<bowler->player_name<<" to "<<batsman->player_name<<" OUT!. "<<endl;
                bowler->wicketstaken+=1;
                bowler->ballbowled+=1;

                batsman->ballsfaced+=1;

                battingteam->wicketlost+=1;
                battingteam->ballsfaced+=1;

                bowlingteam->ballsbowled+=1;

                scorecard();
                int wicket=battingteam->wicketlost;
                batsman=&battingteam->players[wicket];
            }
            else        //run scored
            {
                cout<<bowler->player_name<<" to "<<batsman->player_name<<" "<<run<<" runs!"<<endl;
                bowler->ballbowled+=1;
                bowler->runsgiven+=run;

                batsman->runscored+=run;
                batsman->ballsfaced+=1;


                battingteam->totalrun+=run;
                battingteam->ballsfaced+=1;

                bowlingteam->ballsbowled+=1;

                scorecard();

            }
        }
}
void Game::inningswap()
{
    Team *temp;
    temp=battingteam;
    battingteam=bowlingteam;
    bowlingteam=temp;

    batsman=&battingteam->players[0];
    bowler=&bowlingteam->players[0];
}
void Game::playsecond()
{
    for (int i=1;i<=maxdeliveries;i++)
        {
            cout<<"Press Enter to bowl..."<<endl;
            getch();
            cout<<"Bowling..."<<endl;
            usleep(1000000);
            int run=scorerun();
            if (run==5)  //wicket taken
            {
                cout<<bowler->player_name<<" to "<<batsman->player_name<<" OUT!. "<<endl;
                bowler->wicketstaken+=1;
                bowler->ballbowled+=1;

                batsman->ballsfaced+=1;

                battingteam->wicketlost+=1;
                battingteam->ballsfaced+=1;

                bowlingteam->ballsbowled+=1;

                scorecard();
                int wicket=battingteam->wicketlost;
                batsman=&battingteam->players[wicket];
            }
            else        //run scored
            {
                cout<<bowler->player_name<<" to "<<batsman->player_name<<" "<<run<<" runs!"<<endl;
                bowler->ballbowled+=1;
                bowler->runsgiven+=run;

                batsman->runscored+=run;
                batsman->ballsfaced+=1;


                battingteam->totalrun+=run;
                battingteam->ballsfaced+=1;

                bowlingteam->ballsbowled+=1;

                scorecard();

            }
        if((battingteam->totalrun) > (bowlingteam->totalrun))
        {
            cout<<"\n"<<battingteam->team_name<<" WON THE MATCH"<<endl;
            break;
        }
        }


            if((battingteam->totalrun) < (bowlingteam->totalrun))
            {
                cout<<"\n"<<bowlingteam->team_name<<" WON THE MATCH"<<endl;
            }
            else if((battingteam->totalrun) == (bowlingteam->totalrun))
                cout<<"\nMATCH TIED."<<endl;


        usleep(1000000);
        cout<<"\n\t\t|||MATCH ENDS|||"<<endl;
        matchstats(teamA);
        matchstats(teamB);
}
void Game::matchstats(Team t)
{


    cout<<"\n"<<t.team_name<<" "<<t.totalrun<<"-"<<t.wicketlost<<"  ("<<t.ballsfaced<<")"<<endl;
    cout<<"==========================================="<<endl;
    cout<<"Player\t\tBatting\t\tBowling"<<endl;
    for (int i=0;i<maxplayer;i++)
    {
    cout<<"-------------------------------------------"<<endl;
        cout<<" ["<<i<<"]"<<t.players[i].player_name<<"\t"<<t.players[i].runscored<<"("<<t.players[i].ballsfaced<<")\t\t"
        <<t.players[i].ballbowled<<"-"<<t.players[i].runsgiven<<"-"<<t.players[i].wicketstaken<<endl;
    }
    cout<<"===========================================\n"<<endl;
}
