target:	hw2

hw2:	hw2.o
		g++ hw2.o -o hw2

hw.o:	hw2.cpp
		g++ -c hw2.cpp