#define AU 79
#define AMDAHL 1
#define MAX 10000
#define SEED 342
#define PILE 100

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

pan::pan()
{
  nChunks=PILE;
  myPile = new int[nChunks];
  for (int i=0;i<nChunks;i++)
    myPile[i]=rand()%MAX+1;
}

pan::~pan()
{
  delete[] myPile;
}

int pan::sift()
{
  int foundGold=0;

  for (int i=0;i<nChunks;i++)
  {
    if(myPile[i] == AU)
      foundGold++;
    usleep(AMDAHL);
  }
  return foundGold;
}

bool pan::hasGold()
{
  int foundGold = sift();
  return (foundGold>0);
}
