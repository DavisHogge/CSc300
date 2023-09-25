output: main.o List.o 							// generate object files (.o)
	g++ -std=c++11 -o output main.o List.o 		// compile/build command
main.o: main.cpp 								// Rule for generating main.o file
	g++ -std=c++11 -c main.cpp
List.o: List.h List.cpp 						// Rule for generating List.o file
	g++ -std=c++11 -c List.cpp
clean: 											// Rule for cleaning project
	rm output main.o List.o