#include "pan.h"

#include <iostream>
#include <stdlib.h>
#include <list>
#include <omp.h> //only for timing

#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include <cilk/reducer_list.h>

//constants
#define PANS 1000

using namespace std;


int main(int argc, char* argv[]) {

  cout << "Gold Rush!" << endl << endl;

  int totalDirt = PANS*PILE;
  cout << "  " << totalDirt << " total chunks of dirt" << endl;
  cout << "  " << PANS << " pans" << endl;

  //generate dirt and pans in serial
  srand(SEED);
  Pan* myPans = new Pan[PANS];

  //The serial implementation
  list<int> withGoldSerial;
  double startSerial=omp_get_wtime();
  for (int i=0;i<PANS;++i)
  {
    bool gold=myPans[i].hasGold();
    if(gold)
      withGoldSerial.push_back(i);
  }
  double timeSerial = omp_get_wtime() - startSerial;

  //The Cilk Plus implementation
  list<int> withGoldCilk;
  double startCilk=omp_get_wtime();
  cilk::reducer< cilk::op_list_append<int> > reducer_withGold;
  cilk_for (int i=0;i<PANS;++i)
  {
    bool gold=myPans[i].hasGold();
    if(gold)
      reducer_withGold->push_back(i);
  }
  withGoldCilk = reducer_withGold.get_value();
  double timeCilk = omp_get_wtime() - startCilk;


  //Print the results
  cout << endl;
  cout << "  Found gold in " << withGoldCilk.size() << " pans" << endl;

  cout << "  Pan IDs: ";
  list<int>::const_iterator iterator;
  for (iterator = withGoldCilk.begin();iterator != withGoldCilk.end(); ++iterator)
    cout << *iterator << "  ";
  cout << endl;

  cout << endl;
  int retValue=0;
  if (withGoldSerial == withGoldCilk)
    cout << "Cilk identified the correct pans" << endl;
  else {
    cout << "Cilk did not identify the correct pans" << endl;
    retValue=1;
  }
  cout << endl;

  int nworkers=__cilkrts_get_nworkers();
  cout << "serial execution took " << timeSerial << " seconds" << endl;
  cout << endl;
  cout << "parallel execution took " << timeCilk << " seconds" 
    << " on " << nworkers << " workers" << endl;
  cout << "parallel speedup " << timeSerial/timeCilk << endl;
  cout << "paralell efficiency " << timeSerial/nworkers/timeCilk << endl;

  delete[] myPans;

  return retValue;
}
