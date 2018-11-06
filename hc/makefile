SHELL=cmd.exe
OBJS=main.o Hc.o
main: $(OBJS)
	g++ -o search $(OBJS)
main.o: main.cpp Hc.h
	g++ -c main.cpp
hc.o: Hc.cpp Hc.h
	g++ -c Hc.cpp
clean:
	del $(OBJS)