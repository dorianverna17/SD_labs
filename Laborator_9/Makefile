CC=g++
CFLAGS=-Wall -g --std=c++11 -Wwrite-strings

tested = exercitiul*.cpp
tests = exercitiul*_teste.cpp

all: build run clean

build: lab

helpers.o: helpers.cpp helpers.h

scope_measurer.o: scope_measurer.cpp scope_measurer.h

list.o: list.cpp list.h

dequeue.o: dequeue.cpp dequeue.h

undirected_graph.o: undirected_graph.cpp undirected_graph.h

lab: check_lab.cpp list.o undirected_graph.o helpers.o scope_measurer.o dequeue.o $(tested) $(tests)
	$(CC) $(CFLAGS) -o $@ $^

test: lab
	./lab 1 2 3 4

run: lab
	./lab

pack:
	zip arh.zip *.cpp *.h  Makefile *.csv

.PHONY:
clean:
	rm -rf lab *.o
