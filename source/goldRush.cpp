#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <list>

#ifdef CILK
#include <cilk/cilk.h>
#include <cilk/reducer_list.h>
#endif //CILK

#include "goldRush.h"

#define AU 79
#define PILE 100
#define SEED 342
#define PANS 1000
#define MAX 10000
#define AMDAHL 1

using namespace std;

pan::pan()
{
  nChunks=PILE;
  myPile = new int[nChunks];
  for (int i=0;i<nChunks;i++)
    myPile[i]=rand()%MAX+1;
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
    usleep(AMDAHL);
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
  cout << "  " << totalDirt/8/1024 << " total kB of dirt" << endl;
  cout << "  " << PANS << " pans" << endl;

  //generate dirt and pans in serial
  pan* myPans = new pan[PANS];
  list<int> withGold;

#ifdef CILK
  cilk::reducer< cilk::op_list_append<int> > reducer_withGold;
  int n=PANS;
  cilk_for (int i=0;i<n;++i)
  {
    bool gold=myPans[i].hasGold();
    if(gold)
      reducer_withGold->push_back(i);
  }
  withGold = reducer_withGold.get_value();
#else
  for (int i=0;i<PANS;i++)
  {
    bool gold=myPans[i].hasGold();
    if(gold)
      withGold.push_back(i);
  }
#endif //CILK

  cout << endl;
  cout << "  Found gold in " << withGold.size() << " pans" << endl;

  list<int>::const_iterator iterator;
  cout << "  ";
  for (iterator = withGold.begin();iterator != withGold.end(); ++iterator)
    cout << *iterator << "  ";
  cout << endl;
  return 0;
}
