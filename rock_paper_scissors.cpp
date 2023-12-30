// C++ Program to play Rock-Paper-Scissors
#include <iostream>
#include <ctime>
#include <cstdlib>

// Enums for simplifying results
enum Weapon  {Rock, Paper, Scissor};
enum Result  {Tie,  Comp_Win, User_Win};
Result actionMatrix[3][3] = {{Tie, Comp_Win,User_Win},
                                {User_Win,Tie, Comp_Win},
                                {Comp_Win,User_Win,Tie}};

std::ostream& operator<<(std::ostream& s, Weapon w)
{
    return s << ((w == Rock) ? "Rock" : (w == Paper) ? "Paper" : "Scissor");
}
std::ostream& operator<<(std::ostream& s, Result r)
{
    return s << ((r == Tie) ? "Tie" : (r == Comp_Win) ? "Computer Wins" : "User Wins");
}

Weapon getComputerMove() {
    int move;
    Weapon weapon;
    std:srand(time(NULL));
    move = rand() % 3;
    switch(move) {
        case 0: weapon = Rock; break;
        case 1: weapon =  Paper; break;
        case 2: weapon =  Scissor; break;
    }
    return weapon;
}

// Get human's move
Weapon getHumanMove() {
    char move;
    Weapon weapon;
    while(true) {
        std::cout << "Rock(r), Paper(p), or Scissors(s)? ";
        std::cin >> move;
        switch(move) {
            case 'r': weapon = Rock; break;
            case 'p': weapon = Paper; break;
            case 's': weapon = Scissor; break;
            default: std::cout << "Please enter r,p,or s" << std::endl; continue;
        }
        break;
    }
    return weapon;
}

Result show_winner(Weapon user, Weapon comp)
   {
      // Notice don't use std::endl unless you want to flush the output.
      // If you use std::endl all the time you waste the buffer that is being used
      // to make the stream effecient.
      std::cout << "User:     " << user << "\n"
                << "Computer: " << comp << "\n"
                << std::endl;
       for (time_t t = time(0) + 1; time(0) < t;) {}   
       std::cout << actionMatrix[user][comp] << std::endl;
       return actionMatrix[user][comp];
   }

void start_game() {
    int ties = 0;
    int comp_wins = 0;
    int human_wins = 0;
    while(comp_wins < 2 && human_wins < 2) {
        Weapon human_value = getHumanMove();
        Weapon computer_value = getComputerMove();
        show_winner(human_value,computer_value);
        if (actionMatrix[human_value][computer_value] == Comp_Win) {
            comp_wins++;
        }
        if (actionMatrix[human_value][computer_value] == User_Win) {
            human_wins++;
        }
        if (actionMatrix[human_value][computer_value] == Tie) {
            ties++;
        }
    }
    if (comp_wins > human_wins) {
        std::cout << "Computer WON in " << comp_wins + human_wins + ties << " turns" << std::endl;
    }
    else {
        std::cout << "Human WON in " << comp_wins + human_wins + ties << " turns" << std::endl;
    }
}

int main() {
    char replay = 'y';
    do {
        start_game();
        std::cout << "Replay(y/n)? ";
        std::cin >> replay;
    } while (replay == 'y' || replay == 'Y');
}