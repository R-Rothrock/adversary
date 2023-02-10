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
  
    cout << rock_count << endl;
    cout << paper_count << endl;
    cout << scissors_count << endl;

    int percentage_rock     = rock_count / guess_history.size() * 100;
    int percentage_paper    = paper_count / guess_history.size() * 100;
    int percentage_scissors = scissors_count / guess_history.size() * 100;
    
    // at the current moment, the algorithm is really mathematically
    // straight forward, but that would be very predictable, and so
    // I want it to be a slight more cunning.
  
    cout << percentage_rock << endl;
    cout << percentage_paper << endl;
    cout << percentage_scissors << endl;
    if(percentage_rock > percentage_paper
    && percentage_rock > percentage_scissors)
    {
      return(1); // rock
    } else if(percentage_paper > percentage_rock
    && percentage_paper > percentage_scissors)
    {
      return(2); // paper
    } else
    {
      return(3); // scissors
    }
  }
}
