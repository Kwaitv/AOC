# AOC 2022 template makefile
EXE = day1
OBJS = day1.o
CC = gcc
DEBUG = -g
WARN = -Wall -Wextra
CFLAGS = -O3 -I. $(DEBUG) $(WARN)
LIBS = 
.PHONY: clean

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)
