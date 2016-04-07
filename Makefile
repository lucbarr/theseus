genetics: genetics.o main.o	
	g++ main.o genetics.o -o theseus
	rm *.o
main.o: chromo.h util.h map.h main.cpp
	g++ -c main.cpp
biology.o: genetics.h chromo.h util.h genetics.cpp
	g++ -c genetics.cpp
