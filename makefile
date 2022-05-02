CC = g++
OPT = -O2 -mtune=native -march=native
FLAG = -mavx2 -pthread
STD = -std=c++17
SRC = main.cpp bitmanipulation.cpp
PROG = test

$(PROG): $(SRC)
	$(CC) $(SRC) $(OPT) $(STD) $(FLAG) -o $(PROG)

clean:
	rm $(PROG) .*~ *~
