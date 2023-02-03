// main.cpp

#include<cassert>
#include<cstdlib>
#include<iostream>
#include<vector>

#include "bot.cpp"
#include "rules.cpp"

using namespace std;

vector<int> player_history;

int play_round(int guess)
{
  /* 1: Computer wins
   * 2: Player wins
   * 3: Tie
   */

  assert(guess == ROCK || guess == PAPER || guess == SCISSORS);

  int computer_guess;
  
  switch(predict(player_history))
  {
    case ROCK:
      computer_guess = PAPER;
      break;
    case PAPER:
      computer_guess = SCISSORS;
      break;
    case SCISSORS:
      computer_guess = ROCK;
      break;
  }

  playerhistory.push_back(guess); // add current guess to guess history

  return(eval(guess, computer_guess));
}

int main()
{
  /* The main function isn't very special, as you can see.
   * This is mostly designed for the Python API in the `test`
   * directory.
   */
  
  int in;
  cout << "What do you play: [1: Rock; 2: Paper; 3: Scissors]: ";
  in = (int)getchar(); // this might crash the program. Just FYI.

  switch(play_round(in))
  {
    case 1:
      cout << "You lose!";
      break;
    case 2:
      cout << "You win!";
      break;
    case 3:
      cout << "Tie!";
      break;
  }

}
