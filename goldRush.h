#include <math.h>

class pan {
  public:
    pan(int n);
    ~pan();

    bool hasGold();
    void sift();

  private:
    int nRandom;
    int *myStream;
    int foundGold;

};

bool isPrime(int number)
{
  if(number<2)
    return false;

  for(int i=2;i<number;i++)
    if(number%i==0)
      return false;

  return true;
}

bool isThabit(int number)
{
  int star = log2((number+1)/3);
  return isPrime(star);
}

