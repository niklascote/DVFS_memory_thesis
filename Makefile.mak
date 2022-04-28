# Makefile for compiling the microbenchmark
#
CC = gcc
CFLAGS = -fopenmp -O0
#gcc -fopenmp -O0 microbenchmark.c -o microbenchmark
TARGET= microbenchmark


all: $(TARGET).c
        $(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c
clean:
        $(RM) $(TARGET)