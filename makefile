# define the compiler
CXX = /opt/homebrew/bin/g++-14

# define the standard and the library
CXXFLAGS = -std=c++23 -Wall -Wextra -g

# standard header path definition
INCLUDE_PATH = -I/opt/homebrew/Cellar/gcc/14.2.0_1/include/c++/14 \
	-I/opt/homebrew/Cellar/gcc/14.2.0_1/include/c++/14/aarch64-apple-darwin24 \
	-I/opt/homebrew/Cellar/gcc/14.2.0_1/lib/gcc/current/gcc/aarch64-apple-darwin24/14/include \
	-I/opt/homebrew/Cellar/gcc/14.2.0_1/lib/gcc/current/gcc/aarch64-apple-darwin24/14/include-fixed \
	-I/Library/Developer/CommandLineTools/SDKs/MacOSX15.sdk/usr/include

driver: driver.o
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATH) -o driver driver.o

driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE_PATH) -c driver.cpp

clean:
	rm -f *.o driver

new:
	make clean
	make