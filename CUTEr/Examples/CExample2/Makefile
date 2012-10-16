C = gcc
CFLAGS = -Wall -Wextra -lm

OBJS = steepest_descent.o
TESTS = test1.tst test2.tst test3.tst

all: clean $(OBJS)

run: $(OBJS) $(TESTS)
	for file in $$(ls *.tst); do ./$$file; done

cuter: c_example2main.o
	cp -f c_example2.sh.pro $(CUTER)/build/prototypes/c_example2.sh.pro
	sed -f $(MYCUTER)/double/config/script.sed c_example2.sh.pro > $(MYCUTER)/bin/c_example2
	chmod a+x $(MYCUTER)/bin/c_example2
	cp -f c_example2main.c $(MYCUTER)/double/bin/c_example2ma.c
	mv -f c_example2main.o $(MYCUTER)/double/bin/c_example2ma.o

clean:
	rm -f $(OBJS) $(TESTS)
	
purge: clean

%.o: %.c
	$(C) -c -o $@ $< $(CFLAGS)

%.tst: %.c 
	$(C) -o $@ $< $(CFLAGS) $(OBJS)
