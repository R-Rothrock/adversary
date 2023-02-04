// main.cpp

#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

#include "bot.hpp"
#include "rules.hpp"

using namespace rules;

vector<int> player_history;

int play_round(int guess)
{
  /* 1: Computer wins
   * 2: Player wins
   * 3: Tie
   */

  int computer_guess;
  int prediction_ret = bot::predict(player_history);
  cout << "prediction ret: " << prediction_ret << endl;
  switch(bot::predict(player_history))
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

  player_history.push_back(guess); // add current guess to guess history

  int ret = eval(guess, computer_guess);
  cout << "Return of evaluation: " << ret << endl;
  return(ret);
}

int main()
{
  /* The main function isn't very special, as you can see.
   * This is mostly designed for the Python API in the `test`
   * directory.
   */
  
  char ch;
  int nr;

  while(true)
  {
    cout << "What do you play: [1: Rock; 2: Paper; 3: Scissors]: ";
    ch = getchar();
    cout << "char inputed: " << ch << endl;
    nr = (int)ch;
    if(nr)
      break;
  }

  int ret = play_round(nr);
  switch(ret)
  {
    case 1:
      cout << "You lose!\n";
      break;
    case 2:
      cout << "You win!\n";
      break;
    case 3:
      cout << "Tie!\n";
      break;
  }

}
