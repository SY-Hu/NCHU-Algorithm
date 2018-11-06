SHELL=cmd.exe
OBJS=main.o Ga.o
main: $(OBJS)
	g++ -o search $(OBJS)
main.o: main.cpp Ga.h
	g++ -c main.cpp
Ga.o: Ga.cpp Ga.h
	g++ -c Ga.cpp
clean:
	del $(OBJS)