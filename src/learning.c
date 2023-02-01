//learning.c

#include<learning.h>

int predict(int[] historical_moves)
{
  /* Looks at the historical moves of the opponent and predicts
   * their next move.
   */

  unsigned int move_count = sizeof(historical_moves)/sizeof(int);

  // getting data on all historical moves
  // getting total times played
  int total_rock_played;
  int total_paper_played;
  int total_scissors_played;

  for(int i = 0; i < move_count; i++)
  {
    switch(historical_moves[i])
    {
      case 1:
        total_rock_played++;
        break;
      case 2:
        total_paper_played;
        break;
      case 3:
        total_scissors_played;
        break;
    }
  }

  // getting percentages
  int percent_rock     = (int)total_rock_played / move_count * 10;
  int percent_paper    = (int)total_paper_played / move_count * 10;
  int percent_scissors = (int)total_scissors_played / move_count * 10;

  // calculating the most used option
  // returning it, as well

  // because I don't want the program to keep guessing rock when its
  // opponent keeps doing paper, I'm adding a slight randomization to
  // the prediction, making it's predictions closer to an "educated
  // guess" much like another person playing rock paper scissors.

  time_t t;
  srand((unsigned) time(&t));

  // increases an random option by %15

  const unsigned int factor = 15;

  switch(rand() % 3 + 1)
  {
    case 1:
      percent_rock + factor;
      break;
    case 2:
      percent_paper + factor;
      break;
    case 3:
      percent_scissors + factor;
      break;
  }

  if(percent_rock == percent_paper && percent_paper == percent_scissors)
  {
    // all values are the same, just choose randomly
    time_t t;
    srand((unsigned) time(&t));
    return(rand() % 3 + 1);
  }

  if(percent_rock > percent_paper)
  {
    if(percent_rock > percent_scissors)
      return(ROCK);
    else
      return(SCISSORS);
  } else
  {
    if(percent_paper > percent_scissors)
      return(PAPER);
    else
      return(SCISSORS);
  }
}
