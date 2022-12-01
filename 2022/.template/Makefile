# AOC 2022 template makefile
EXE = 
OBJS = 
CC = g++
DEBUG = -g
WARN = -Wall -Wextra
CFLAGS = -I. $(DEBUG) $(WARN)
LIBS = 
.PHONY: clean

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

clean:
	rm -f $(EXE) $(OBJS)
