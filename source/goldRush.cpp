#include <iostream>
#include <stdlib.h>
#include <list>
#include "goldRush.h"

#define AU 79
#define PILE 1000
#define SEED 342
#define PANS 1000000

using namespace std;

pan::pan()
{
  nChunks=PILE;
  myPile = new int[nChunks];
  for (int i=0;i<nChunks;i++)
    myPile[i]=rand()%100000+1;
}

pan::~pan()
{
  delete myPile;
}

int pan::sift()
{
  int foundGold=0;

  for (int i=0;i<nChunks;i++)
  {
    int trial=myPile[i];
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

  srand(SEED);

  cout << "Gold Rush!" << endl << endl;

  int totalDirt = PANS*PILE;
  cout << "  " << totalDirt/8/1024/1024 << " total MB of dirt" << endl;
  cout << "  " << PANS << " pans" << endl;

  //generate dirt and pans in serial
  //random number generators are not thread safe
  pan* myPans = new pan[PANS];
  list<int> withGold;

  for (int i=0;i<PANS;i++)
  {
    bool gold=myPans[i].hasGold();
    if(gold)
      withGold.push_back(i);
  }

  cout << endl;
  cout << "  found gold in " << withGold.size() << " pans" << endl;
  cout << endl;
  return 0;
}
