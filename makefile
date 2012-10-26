# files: source files:  main.cpp
# executable file: rps
#

student: rps.o
	g++ -o rps rps.o

rps.o: rps.cpp
	g++ -c rps.cpp


clean:
	rm rps rps.o
