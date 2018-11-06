SHELL=cmd.exe
OBJS=main.o Sa.o
main: $(OBJS)
	g++ -o search $(OBJS)
main.o: main.cpp Sa.h
	g++ -c main.cpp
Sa.o: Sa.cpp Sa.h
	g++ -c Sa.cpp
clean:
	del $(OBJS)