CC = g++
FLAGES = -std=c++11
GFLAGES = -std=c++11 -lgtest -lgtest_main -lpthread

test:leetcode921.o leetcodeTest.o
	$(CC) -o test $(GFLAGES) leetcode921.o leetcodeTest.o

leetcode921.o:leetcode921.cpp
	$(CC) -c $(FLAGES) leetcode921.cpp

leetcodeTest.o:leetcodeTest.cpp
	$(CC) -c $(GFLAGES) leetcodeTest.cpp

clean:
	@ rm *.o test