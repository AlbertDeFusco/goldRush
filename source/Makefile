CC = icc
CCLFAGS = -openmp

source = goldRush.cpp pan.cpp
header = pan.h

all = goldRush

goldRush: $(source) $(header)
	$(CC) $(CCLFAGS) -o $@ $(source)

clean:
	$(RM) $(all)
