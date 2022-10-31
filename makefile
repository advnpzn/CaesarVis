all: caesar
	./caesar neko.png

caesar: main.o caesar.o
	g++ -o caesar main.o caesar.o -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

caesar.o: caesar.cpp caesar.hpp
	g++ -c caesar.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o caesar