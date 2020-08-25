CC=g++
CFLAGS=-Wall -g --std=c++11 -Wwrite-strings

tested_files = exercitiul1.cpp exercitiul2.cpp exercitiul3.cpp
tests_files = exercitiul1_teste.cpp exercitiul2_teste.cpp exercitiul3_teste.cpp

all: build run clean

build: lab

helpers.o: helpers.cpp helpers.h

lab: check_lab5.cpp list.h list.cpp $(tested_files) $(tests_files) helpers.o
	$(CC) $(CFLAGS) -o $@ $^

test: lab
	time ./lab 1 2 4 6

run: lab
	time ./lab

pack:
	zip arh.zip *.cpp *.h  Makefile

.PHONY:
clean: lab
	rm -rf lab *.o
