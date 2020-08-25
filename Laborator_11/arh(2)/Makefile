CC=g++
CFLAGS=-Wall -g --std=c++11 -Wwrite-strings

tested = exercitiul*.cpp
tests = exercitiul*_teste.cpp
structures = weighted_graph.cpp utils/list.cpp utils/dequeue.cpp utils/node_weight.cpp utils/list_node.cpp
others = utils/helpers.cpp utils/scope_measurer.cpp

all: build run clean

build: lab

lab: check_lab.cpp $(structures) $(others) $(tested) $(tests)
	$(CC) $(CFLAGS) -o $@ $^ -Iutils/

test: lab
	./lab 1 2 3 4

run: lab
	./lab

pack:
	zip -r arh.zip *.cpp *.h  Makefile graph_tool.py graphs/ utils/

.PHONY:
clean:
	rm -rf lab *.o
