SHELL=cmd.exe
OBJS=main.o Ts.o
main: $(OBJS)
	g++ -o search $(OBJS)
main.o: main.cpp Ts.h
	g++ -c main.cpp
Ts.o: Ts.cpp Ts.h
	g++ -c Ts.cpp
clean:
	del $(OBJS)