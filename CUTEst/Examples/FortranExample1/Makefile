F = gfortran
FFLAGS = 
I = -I$(CUTEST)/include
PKG = fortran_example

OBJS = gradient.o gradientmain.o
TESTS = test1.tst test2.tst test3.tst
DIR = $(shell pwd)

all: clean $(OBJS)

run: $(OBJS) $(TESTS)
	for file in $$(ls *.tst); do ./$$file; done

cutest: $(OBJS) $(PKG)main.o
	mkdir -p $(CUTEST)/src/$(PKG)
	sed 's:THISDIR:$(DIR):g' $(PKG).sh.pro > $(CUTEST)/packages/$(MYARCH)/double/$(PKG)
	chmod a+x $(CUTEST)/packages/$(MYARCH)/double/$(PKG)
	cp -f $(PKG)main.f $(CUTEST)/src/$(PKG)/$(PKG)_main.f
	cp -f $(PKG)main.o $(CUTEST)/objects/$(MYARCH)/double/$(PKG)_main.o
	cp -f $(OBJS) $(CUTEST)/objects/$(MYARCH)/double/
	cp -f makemaster $(CUTEST)/src/$(PKG)

clean:
	rm -f $(OBJS) $(TESTS)
	
purge: clean

%.o: %.f
	$(F) -c -o $@ $< $(FFLAGS) $(I)

%.tst: %.f
	$(F) -o $@ $< $(FFLAGS) $(OBJS)
