C = gcc
CFLAGS = -Wall -Wextra -lm

OBJS = steepest_descent.o
TESTS = test1.tst test2.tst test3.tst

all: clean $(OBJS)

run: $(OBJS) $(TESTS)
	for file in $$(ls *.tst); do ./$$file; done

clean:
	rm -f $(OBJS) $(TESTS)
	
purge: clean

%.o: %.c
	$(C) -c -o $@ $< $(CFLAGS)

%.tst: %.c 
	$(C) -o $@ $< $(CFLAGS) $(OBJS)
