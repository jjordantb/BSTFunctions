CC=g++
CFLAGS=-I

Main: BinNode.o BSTNode.o Main.o
	$(CC) -o Main BinNode.o BSTNode.o Main.o -I.
