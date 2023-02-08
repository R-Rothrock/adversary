// randoms.cpp
#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int main()
{
  srand(time(0));
  int nr = rand();
  cout << nr << endl;
  cout << nr % 3 + 1 << endl;
  return(0);
}