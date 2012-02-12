# Simple makefile for euler helper functions

GCC = g++
GCC_FLAGS = -w -Wall -Werror -pedantic -ansi
EULER_PATH = /home/rhalstea/programs/euler_helper_functions/src


# Do not modify below line
# ----- ----- ----- ----- ----- -----
OBJECTS = BigInt.o Primes.o
VPATH = $(EULER_PATH)
INCLUDES = -I. -I$(EULER_PATH)

%.exe: %.cpp $(OBJECTS)
	$(GCC) $(GCC_FLAGS) $(INCLUDES) -o $@ $< $(OBJECTS)

%.o: %.cpp %.h
	$(GCC) $(GCC_FLAGS) -c $<

clean:
	rm -rf *~ *.o *.exe