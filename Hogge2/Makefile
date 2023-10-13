output: main.o Stack.o 							// generate object files (.o)
	g++ -std=c++11 -o output main.o Stack.o 		// compile/build command
main.o: main.cpp 								// Rule for generating main.o file
	g++ -std=c++11 -c main.cpp
Stack.o: Stack.h Stack.cpp 						// Rule for generating Stack.o file
	g++ -std=c++11 -c Stack.cpp
clean: 											// Rule for cleaning project
	rm output main.o Stack.o
