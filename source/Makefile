CC = icc
CCLFAGS = -openmp

all = goldRush

goldRush: goldRush.cpp goldRush.h
	$(CC) $(CCLFAGS) -o $@ $<

clean:
	$(RM) $(all)
