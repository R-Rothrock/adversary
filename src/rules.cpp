// data.cpp
// defines useful stuff

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

inline int eval(int guess, int computer_guess)
{
  if(guess == computer_guess)
  {
    return(3); // tie ~}:
  } else if(computer_guess == guess++ || guess == SCISSORS && computer_guess == ROCK)
  {
    return(1); // computer wins ):
  } else if(computer_guess == guess-- || guess == ROCK && computer_guess == SCISSORS)
  {
    return(2); // player wins (:
  }
}