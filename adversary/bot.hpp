// bot.cpp

#include<cstdlib>
#include<iostream>
#include<time.h>
#include<vector>

using namespace std;

namespace bot
{

  int predict(vector<int> guess_history)
  {
    // if history is empty, simple choose randomly
    if(guess_history.size() == 0)
    {
      // 1 = ROCK, 2 = PAPER, 3 = SCISSORS
      srand(time(0)); // initialize RNG
      return(rand() % 3 + 1);
    }
    //cout << endl << guess_history.size() << endl;

    unsigned int rock_count = 0;
    unsigned int paper_count = 0;
    unsigned int scissors_count = 0;

    for(int i : guess_history)
    {
      switch(i)
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

    //cout << rock_count << endl;
    //cout << paper_count << endl;
    //cout << scissors_count << endl;

    int percentage_rock     = rock_count / guess_history.size() * 100;
    int percentage_paper    = paper_count / guess_history.size() * 100;
    int percentage_scissors = scissors_count / guess_history.size() * 100;

    // at the current moment, the algorithm is really mathematically
    // straight forward, but that would be very predictable, and so
    // I want it to be a slight more cunning.

    const int size = guess_history.size();
    int factor;

    // If the last three moves are the same, then that same move is likely.
    // if only the last two moves are the same, then that same move is improbably.

    if(guess_history[size - 1] == guess_history[size - 2])
    {
      srand(time(0)); // RNG for factor definition.

      if(guess_history[size - 1] == guess_history[size - 3])
      {
        factor = rand() % 20;
      } else
      {
        factor = rand() % 30;
      }

      switch(guess_history[size - 1])
      {
        case 1:
          percentage_rock -= factor;
          break;
        case 2:
          percentage_paper -= factor;
          break;
        case 3:
          percentage_scissors -= factor;
          break;
      }
    }

    // A random number gets a 20% increase.
    factor = 20;
    srand(time(0));
    switch(rand() % 3 + 1)
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

    // debug help
    //cout << percentage_rock << endl;
    //cout << percentage_paper << endl;
    //cout << percentage_scissors << endl;

    if(percentage_rock > percentage_paper
    && percentage_rock > percentage_scissors)
    {
      return(1); // rock
    } else if(percentage_paper > percentage_rock
    && percentage_paper > percentage_scissors)
    {
      return(2); // paper
    } else if(percentage_scissors > percentage_rock
    && percentage_scissors > percentage_paper)
    {
      return(3); // scissors
    } else // all values are even (probably 0) random number.
    {
      srand(time(0)); // initialize RNG
      return(rand() % 3 + 1);
    }
  }
}
