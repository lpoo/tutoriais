C = gcc
CFLAGS = -Wall -Wextra -lm
I = -I$(CUTEST)/include
PKG = c_example2

OBJS = steepest_descent.o
TESTS = test1.tst test2.tst test3.tst
DIR = $(shell pwd)

all: clean $(OBJS)

run: $(OBJS) $(TESTS)
	for file in $$(ls *.tst); do ./$$file; done

cutest: $(OBJS) $(PKG)main.o
	mkdir -p $(CUTEST)/src/$(PKG)
	sed 's:THISDIR:$(DIR):' $(PKG).sh.pro > $(CUTEST)/packages/$(MYARCH)/double/$(PKG)
	chmod a+x $(CUTEST)/packages/$(MYARCH)/double/$(PKG)
	cp -f $(PKG)main.c $(CUTEST)/src/$(PKG)/$(PKG)_main.c
	cp -f $(PKG)main.o $(CUTEST)/objects/$(MYARCH)/double/$(PKG)_main.o
	cp -f $(OBJS) $(CUTEST)/objects/$(MYARCH)/double/
	cp -f makemaster $(CUTEST)/src/$(PKG)

clean:
	rm -f $(OBJS) $(TESTS)
	
purge: clean

%.o: %.c
	$(C) -c -o $@ $< $(CFLAGS) $(I)

%.tst: %.c 
	$(C) -o $@ $< $(CFLAGS) $(OBJS)
