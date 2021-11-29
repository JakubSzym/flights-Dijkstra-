FLAGS=-g -Wall -pedantic -std=c++1z -iquote inc -lm
__start__:.//app

.//app: ./obj/main.o ./obj/path.o ./obj/net.o ./obj/earth.o
	g++ -o .//app ./obj/main.o ./obj/path.o ./obj/net.o ./obj/earth.o -lm
./obj:
	md ./obj;
./obj/main.o: src/main.cpp inc/path.hh
	g++ -c ${FLAGS} -o ./obj/main.o src/main.cpp
./obj/path.o: src/path.cpp inc/path.hh
	g++ -c ${FLAGS} -o ./obj/path.o src/path.cpp
./obj/net.o: src/net.cpp inc/net.hh
	g++ -c ${FLAGS} -o ./obj/net.o src/net.cpp
./obj/earth.o: src/earth.cpp inc/earth.hh
	g++ -c ${FLAGS} -o ./obj/earth.o src/earth.cpp
clean:
	rm -f .//app ./obj/*
