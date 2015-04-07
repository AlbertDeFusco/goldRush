#include "pan.h"

#include <unistd.h>
#include <stdlib.h>


Pan::Pan()
{
  nChunks=PILE;
  myPile = new int[nChunks];
  for (int i=0;i<nChunks;++i)
    myPile[i]=rand()%MAX+1;
}

Pan::~Pan()
{
  delete[] myPile;
}

int Pan::sift()
{
  int foundGold=0;

  for (int i=0;i<nChunks;++i)
  {
    if(myPile[i] == AU)
      ++foundGold;
    usleep(AMDAHL);
  }
  return foundGold;
}

bool Pan::hasGold()
{
  int foundGold = sift();
  return (foundGold>0);
}
