// rules.cpp

#define ROCK 1
#define PAPER 2
#define SCISSORS 3

int eval(int guess, int computer_guess)
{
  /* 1: computer wins
   * 2: player wins
   * 3: tie
   */

  if(guess == ROCK)
  {
    if(computer_guess == PAPER)
      return(1);
    else if(computer_guess == SCISSORS)
      return(2);
    else
      return(3);
  } else if(guess == PAPER)
  {
    if(computer_guess == SCISSORS)
      return(1);
    else if (computer_guess == ROCK)
      return(2);
    else
      return(3);
  } else // if(guess == SCISSORS)
  {
    if(computer_guess == ROCK)
      return(1);
    else if(computer_guess == PAPER)
      return(2);
    else
      return(3);
  }
}
