C = gcc
CFLAGS = -Wall -Wextra -lm

OBJS = steepest_descent.o
TESTS = test1.tst test2.tst test3.tst

all: clean $(OBJS)

run: $(OBJS) $(TESTS)
	for file in $$(ls *.tst); do ./$$file; done

cuter: c_example1main.o
	cp -f c_example1.sh.pro $(CUTER)/build/prototypes/dcicpp.sh.pro
	sed -f $(MYCUTER)/double/config/script.sed c_example1.sh.pro > $(MYCUTER)/bin/c_example1
	chmod a+x $(MYCUTER)/bin/c_example1
	cp -f c_example1main.c $(MYCUTER)/double/bin/c_example1ma.c
	mv -f c_example1main.o $(MYCUTER)/double/bin/c_example1ma.o

clean:
	rm -f $(OBJS) $(TESTS)
	
purge: clean

%.o: %.c
	$(C) -c -o $@ $< $(CFLAGS)

%.tst: %.c 
	$(C) -o $@ $< $(CFLAGS) $(OBJS)
