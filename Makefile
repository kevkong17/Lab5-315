CXX = g++
CXXFLAGS = -g -Wall -O3
CXXSRC = matmul.cpp matmul-driver.cpp 
OUT = mm

all:
	$(CXX) $(CXXFLAGS) -c $(CXXSRC)
	$(CXX) $(CXXFLAGS) -o $(OUT) *.o

clean:
	rm -f *.o