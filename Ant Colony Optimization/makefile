SHELL=cmd.exe
OBJS=main.o aco.o
main: $(OBJS)
	g++ -o search $(OBJS)
main.o: main.cpp Aco.h
	g++ -c main.cpp
aco.o: Aco.cpp Aco.h
	g++ -c Aco.cpp
clean:
	del $(OBJS)