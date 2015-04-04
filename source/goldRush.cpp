#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "goldRush.h"

#define AU 79
#define heap 100

using namespace std;

pan::pan()
{
  nRandom=heap;
  myStream = new int[nRandom];
  for (int i=0;i<nRandom;i++)
    myStream[i]=rand()%10000+1;
}

pan::~pan()
{
  delete myStream;
}

int pan::sift()
{
  int foundGold=0;

  for (int i=0;i<nRandom;i++)
  {
    int trial=myStream[i];
    if(trial == AU)
      foundGold++;
  }
  return foundGold;
}

bool pan::hasGold()
{
  int foundGold = this->sift();
  return (foundGold>0);
}



int main(int argc, char* argv[]) {

  srand( atoi(argv[1]) );

  int nPans = 100000;
  pan* myPans = new pan[nPans];

  int total=0;
  for (int i=0;i<nPans;i++)
  {
    bool gold=myPans[i].hasGold();
    if(gold)
      total++;
  }
  cout << total << endl;
  return 0;
}
