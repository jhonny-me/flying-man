flying:main.o playway.o
	g++ main.o playway.o -o flying

main.o:main.cpp 
	g++   main.cpp -o main.o
playway.o: playway.cpp
	g++  playway.cpp -o playway.o

clean:
	rm *.o flying
	
