#include <math.h>

class pan {
  public:
    pan();
    ~pan();

    bool hasGold();
    int sift();

  private:
    int nChunks;
    int *myPile;
};
