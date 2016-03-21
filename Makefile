CC=g++
CFLAGS=-I

Main: BinNode.o BSTNode.o Main.o
	$(CC) -o BSTFunctions BinNode.o BSTNode.o Main.o -I.
