# define the compiler
CXX = clang++

# define the standard and the library
CXXFLAGS = -std=c++23 -stdlib=libc++ -g

# define the path to the standard headers
INCLUDE_PATH = -I/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1

driver: driver.o
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATH) -o driver driver.o

driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATH) -c driver.cpp

clean:
	rm -f *.o driver

new: 
	make clean
	make