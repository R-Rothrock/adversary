// adversary
// copyright 2023 Roan Rothrock

#include<stdio.h>

#include "learning.c"
#include "rules.c"

int main()
{
  /* As you can see, the `main` function isn't very special. If you
   * look at the Python script in the test directory, you'll see that
   * only `play_round` is used with a Python-made GUI interface.
   */
  
  int[] player_guess_history;
  int player_guess;
  while(1)
  {
    printf("What do you play? [1: rock; 2: paper; 3: scissors]: ");
    player_guess = (int)(getchar()); // warning: suspectable to crashes
    switch(play_round())
    {
      case 1:
        printf("You lost! ):");
        break;
      case 2:
        printf("You win! (:");
        break;
      case 3:
        printf("Tie! ~};");
        break;
    }

  }
  return(0);
}


int play_round(int opponent_guess, int[] opponent_history)
{
  /* 0: tie (~}:)
   * 1: computer wins ):
   * 2: human wins (:
   */
  
  const unsigned int computer_guess;

  switch(predict(opponent_history))
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

  return(eval(computer_guess, opponent_guess));
}