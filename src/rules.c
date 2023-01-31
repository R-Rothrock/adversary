// rules.c
// rules for rock paper scissors

#include<rules.h>

int eval(int player1_move, int player2_move)
{
  /* evaluates the moves of both players and ascertains who has a
   * winning outcome.
   */
  int winner;

  if(player1_move == ROCK && player2_move == PAPER) ||
  (player1_move == PAPER && player2_move == SCISSORS) ||
  (player1_move == SCISSORS && player2_move == ROCK)
  {
    winner = 2;
  } else if (player1_move == player2_move)
  {
    winner = 0;
  } else
  {
    winner = 1;
  }

  return(winner);
}
