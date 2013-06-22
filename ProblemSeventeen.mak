#ProblemSeventeen.mak
CC = gcc
WARNINGS = -Wall

all: ProblemSeventeen.exe

ProblemSeventeen.exe: ProblemSeventeen.o
	$(CC) $(WARNINGS) ProblemSeventeen.o -o ProblemSeventeen.exe
	
ProblemSeventeen.o: ProblemSeventeen.c ProblemSeventeen.h
	$(CC) -c ProblemSeventeen.c

clean:
	rm -rf *o ProblemSeventeen.exe
