// main.cpp

#include<cassert>
#include<cstdlib>
#include<iostream>
#include<vector>

#define ROCK     1
#define PAPER    2
#define SCISSORS 3

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

  if(guess == computer_guess)
  {
    return(3); // tie
  } else if(computer_guess == guess++ || guess == SCISSORS && computer_guess == ROCK)
  {
    return(1); // computer wins
  } else if(computer_guess == guess-- || guess == ROCK && computer_guess == SCISSORS)
  {
    return(2); // player wins (:
  }
}
