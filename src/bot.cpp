// bot.cpp

#include<cstdlib>
#include<vector>

#include "rules.cpp"

inline int predict(vector<int> guess_history)
{
  // if history is empty, simple choose randomly
  if(guess_history.size() == NULL)
  {
    return(std::rand() % 3 + 1);
  }

  vector<int>::const_interator iter;

  unsigned int rock_count, paper_count, scissors_count;
  for(iter = guess_history.begin(); iter != guess_history.end(); iter++)
  {
    match(*iter)
    {
      case 1:
        rock_count++;
        break;
      case 2:
        paper_count++;
        break;
      case 3:
        scissors_count++;
        break;
    }
  }
  
  int percentage_rock     = rock_count / guess_history.size() * 100;
  int percentage_paper    = paper_count / guess_history.size() * 100;
  int percentage_scissors = scissors_count / guess_history.size() * 100;

  // Because Rock Paper Scissors is generally more randomized than
  // doing basic math, and because guesses are also better educated
  // than basic math, a factor of 20% will be added to a random guess.

  const unsigned int factor = 20;

  switch(std::rand() % 3 + 1)
  {
    case 1:
      percentage_rock += factor;
      break;
    case 2:
      percentage_paper += factor;
      break;
    case 3:
      percentage_scissors += factor;
      break;
  }

  // also, whatever guess was guessed most recently will be decremented
  // by `factor`

  switch(guess_history[guess_history.size() - 1])
  {
    case ROCK:
      percentage_rock -= factor;
      break;
    case PAPER:
      percentage_paper -= factor;
      break;
    case SCISSORS:
      percentage_scissors -= factor;
      break;
  }

  // returning whatever percentage is larger.
  // note: this will technically be most likely to output scissors, so
  // scissors will be decremented 5%
  percentage_scissors -= 5;

  if(percentage_rock > percentage_paper && percentage_rock > percentage_scissors)
  {
    return(ROCK);
  } else if(percentage_paper > percentage_rock && percentage_paper > percentage_scissors)
  {
    return(PAPER);
  } else
  {
    return(SCISSORS);
  }
}
