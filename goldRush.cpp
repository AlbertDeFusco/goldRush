#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "goldRush.h"

using namespace std;

pan::pan(int n)
{
  nRandom=n;
  myStream = new int[nRandom];
  for (int i=0;i<nRandom;i++)
    myStream[i]=rand()%100+1;

  foundGold=0;
}

pan::~pan()
{
  delete myStream;
}

void pan::sift()
{
  cout << endl;
  for (int i=0;i<nRandom;i++)
  {
    if(isPrime(myStream[i]))
      foundGold++;
  }
}

bool pan::hasGold()
{
  return !(bool)(foundGold%79);
}



int main(int argc, char* argv[]) {

  int n = atoi(argv[1]);
  srand( atoi(argv[2]) );

  pan thisPan(n);

  thisPan.sift();
  bool gold = thisPan.hasGold();

  cout << boolalpha << gold << endl;
  return 0;
}
