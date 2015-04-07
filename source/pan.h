//constants
#define AU 79
#define AMDAHL 1
#define MAX 10000
#define SEED 342
#define PILE 100

class Pan {
  public:
    Pan();
    ~Pan();

    bool hasGold();
    int sift();

  private:
    int nChunks;
    int *myPile;
};

