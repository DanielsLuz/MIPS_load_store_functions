CC = gcc
CUNIT_LDFLAGS = -lcunit
SRC = src
TEST = test
DEP = memfunctions.o
CFLAGS = -w
TEST_MODULES = $(TEST)/storeTests.c $(TEST)/loadTests.c
IFLAG = -I$(TEST)/CUnit/include 
LFLAG = -L$(TEST)/CUnit/lib

main: memfunctions
		$(CC) $(CFLAGS) $(SRC)/t1_mips_simulator.c -o t1_mips_simulator $(DEP)

tests: memfunctions
		$(CC) $(CFLAGS) $(IFLAG) $(TEST)/t1_mips_simulator_test.c $(TEST_MODULES) \
		$(LFLAG) $(CUNIT_LDFLAGS) $(DEP) -o t1_mips_simulator_test  

all: main tests

debug:	main test

debug:	CFLAGS=-g

memfunctions:
		$(CC) $(CFLAGS) -c $(SRC)/memfunctions.c

clean:
		rm -f *.o t1_mips_simulator t1_mips_simulator_test
