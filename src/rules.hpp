// rules.cpp

namespace rules
{
  #define ROCK 1
  #define PAPER 2
  #define SCISSORS 3

  int eval(int guess, int computer_guess)
  {
    /* 1: computer wins
     * 2: player wins
     * 3: tie
     */
    
    int ret;
  
    switch(guess)
    {
      case ROCK:
        if(computer_guess == ROCK)
          ret = 3;
        if(computer_guess == PAPER)
          ret = 1;
        if(computer_guess == SCISSORS)
          ret = 2;
        break;
      case PAPER:
        if(computer_guess == ROCK)
          ret = 2;
        if(computer_guess == PAPER)
          ret = 3;
        if(computer_guess == SCISSORS)
          ret = 1;
        break;
      case SCISSORS:
        if(computer_guess == ROCK)
          ret = 1;
        if(computer_guess == PAPER)
          ret = 2;
        if(computer_guess == SCISSORS)
          ret = 3;
        break;
    }
    return(ret);
  }
}
