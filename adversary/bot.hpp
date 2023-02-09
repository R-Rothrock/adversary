// bot.cpp

#include<cstdlib>
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
      srand(time(0));
      return(rand() % 3 + 1);
    }
    //cout << endl << guess_history.size() << endl;

    unsigned int rock_count, paper_count, scissors_count;
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
  
    int percentage_rock     = rock_count / guess_history.size() * 100;
    int percentage_paper    = paper_count / guess_history.size() * 100;
    int percentage_scissors = scissors_count / guess_history.size() * 100;

    // Because Rock Paper Scissors is generally more randomized than
    // doing basic math, a factor of 20% will be added to a random guess.

    const unsigned int factor = 20;

    srand(time(0));
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
    cout << guess_history[guess_history.size() - 1];

    if(percentage_rock > percentage_paper && percentage_rock > percentage_scissors)
    {
      return(1); // rock
    } else if(percentage_paper > percentage_rock && percentage_paper > percentage_scissors)
    {
      return(2); // paper
    } else
    {
      return(3); // scissors
    }
  }
}
