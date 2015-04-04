#include <math.h>

class pan {
  public:
    pan();
    ~pan();

    bool hasGold();
    int sift();

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

bool isSafe(int number)
{
  int safe = (number-1)/2;
  return isPrime(safe);
}

long long int factorial(int number)
{
  if(number==0)
    return 1;
  long long int fac=number*factorial(number-1);
  return fac;
}
