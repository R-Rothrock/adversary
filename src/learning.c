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
  int percent_rock     = (int)total_rock_played / move_count;
  int percent_paper    = (int)total_paper_played / move_count;
  int percent_scissors = (int)total_scissors_played / move_count;

  // calculating the most used option
  // returning it, as well

  if(percent_rock == percent_paper && percent_paper == percent_scissors)
  {
    // all values are the same, just choose randomly
    time_t t;
    srand((unsigned) time(&t));
    return(rand( % 2) + 1);
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