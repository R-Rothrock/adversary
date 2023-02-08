// rules.cpp

namespace rules
{
  #define ROCK 1
  #define PAPER 2
  #define SCISSORS 3

  inline int eval(int guess, int computer_guess)
  {
    /* 1: computer wins
     * 2: player wins
     * 3: tie
     */

    switch(guess)
    {
      case 1:
        if(computer_guess == 2)
          return(1);
        else if(computer_guess == 3)
          return(2);
        else
          return(0);
        break;
      case 2:
        if(computer_guess == 1)
          return(2);
        else if(computer_guess == 3)
          return(1);
        else
          return(0);
        break;
      case 3:
        if(computer_guess == 1)
          return(1);
        else if(computer_guess == 2)
          return(2);
        else
          return(0);
        break;
      default:
        if(guess == computer_guess)
          return(3);
        else
          return(5); // I don't know how we'd get here...
        break;
    }
  }
}
